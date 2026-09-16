#!/usr/bin/env python3
import ast
import re
import statistics
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Tuple

USA_NONMATCHINGS_PREFIX = "asm/usa/nonmatchings"
NONMATCHING_RE = re.compile(
    r"\bnonmatching\s+([A-Za-z_][A-Za-z0-9_]*)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\b"
)
STRING_LITERAL_RE = re.compile(r'"(?:\\.|[^"\\])*"')
IDENTIFIER_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")

@dataclass(frozen=True)
class PendingFunction:
    name: str
    size: int
    source_path: Path
    asm_path: Path

def strip_c_comments(text: str) -> str:
    result: List[str] = []
    i = 0
    state = "normal"
    while i < len(text):
        char = text[i]
        next_char = text[i + 1] if i + 1 < len(text) else ""
        if state == "normal":
            if char == "/" and next_char == "/":
                result.extend((" ", " "))
                i += 2
                state = "line_comment"
            elif char == "/" and next_char == "*":
                result.extend((" ", " "))
                i += 2
                state = "block_comment"
            elif char == '"':
                result.append(char)
                i += 1
                state = "string"
            elif char == "'":
                result.append(char)
                i += 1
                state = "char"
            else:
                result.append(char)
                i += 1
        elif state == "line_comment":
            if char == "\n":
                result.append("\n")
                state = "normal"
            else:
                result.append(" ")
            i += 1
        elif state == "block_comment":
            if char == "*" and next_char == "/":
                result.extend((" ", " "))
                i += 2
                state = "normal"
            else:
                result.append("\n" if char == "\n" else " ")
            i += 1
        elif state in ("string", "char"):
            result.append(char)
            i += 1
            if char == "\\" and i < len(text):
                result.append(text[i])
                i += 1
            elif (state == "string" and char == '"') or (state == "char" and char == "'"):
                state = "normal"
    return "".join(result)

def iter_include_asm_arguments(text: str) -> Iterable[str]:
    token = "INCLUDE_ASM"
    position = 0
    while True:
        start = text.find(token, position)
        if start < 0:
            return
        before = text[start - 1] if start > 0 else ""
        after_index = start + len(token)
        after = text[after_index] if after_index < len(text) else ""
        if (before and (before.isalnum() or before == "_")) or (after and (after.isalnum() or after == "_")):
            position = after_index
            continue
        cursor = after_index
        while cursor < len(text) and text[cursor].isspace():
            cursor += 1
        if cursor >= len(text) or text[cursor] != "(":
            position = after_index
            continue
        argument_start = cursor + 1
        cursor += 1
        depth = 1
        state = "normal"
        while cursor < len(text) and depth > 0:
            char = text[cursor]
            if state == "normal":
                if char == '"':
                    state = "string"
                elif char == "'":
                    state = "char"
                elif char == "(":
                    depth += 1
                elif char == ")":
                    depth -= 1
                    if depth == 0:
                        yield text[argument_start:cursor]
                        cursor += 1
                        break
            elif state == "string":
                if char == "\\":
                    cursor += 1
                elif char == '"':
                    state = "normal"
            elif state == "char":
                if char == "\\":
                    cursor += 1
                elif char == "'":
                    state = "normal"
            cursor += 1
        position = max(cursor, after_index)

def decode_c_string(literal: str) -> Optional[str]:
    try:
        value = ast.literal_eval(literal)
    except (SyntaxError, ValueError):
        return None
    return value if isinstance(value, str) else None

def parse_include_asm(arguments: str) -> Optional[Tuple[str, str]]:
    string_values = []
    for match in STRING_LITERAL_RE.finditer(arguments):
        value = decode_c_string(match.group(0))
        if value is not None:
            string_values.append(value.replace("\\", "/"))
    asm_base = next(
        (
            value.rstrip("/")
            for value in string_values
            if value.rstrip("/") == USA_NONMATCHINGS_PREFIX
            or value.startswith(USA_NONMATCHINGS_PREFIX + "/")
        ),
        None,
    )
    if asm_base is None:
        return None
    identifiers = IDENTIFIER_RE.findall(arguments)
    if not identifiers:
        return None
    return asm_base, identifiers[-1]

def index_nonmatching_directives(root: Path):
    asm_root = root / USA_NONMATCHINGS_PREFIX
    if not asm_root.is_dir():
        raise RuntimeError(f"No se encontró el directorio: {asm_root}")
    by_function: Dict[str, List[Tuple[int, Path]]] = {}
    by_path: Dict[Path, List[Tuple[str, int]]] = {}
    for asm_path in sorted(asm_root.rglob("*.s")):
        text = asm_path.read_text(encoding="utf-8", errors="replace")
        relative_path = asm_path.relative_to(root)
        for match in NONMATCHING_RE.finditer(text):
            function_name = match.group(1)
            size = int(match.group(2), 0)
            by_function.setdefault(function_name, []).append((size, relative_path))
            by_path.setdefault(relative_path, []).append((function_name, size))
    return by_function, by_path

def expected_asm_paths(asm_base: str, function_name: str) -> List[Path]:
    base = Path(asm_base)
    candidates: List[Path] = []
    if base.suffix == ".s":
        candidates.append(base)
    else:
        candidates.append(base / f"{function_name}.s")
        candidates.append(base.with_suffix(".s"))
    result: List[Path] = []
    seen = set()
    for path in candidates:
        normalized = Path(path.as_posix())
        if normalized not in seen:
            seen.add(normalized)
            result.append(normalized)
    return result

def resolve_directive(asm_base: str, function_name: str, by_function, by_path):
    for candidate_path in expected_asm_paths(asm_base, function_name):
        for directive_name, size in by_path.get(candidate_path, []):
            if directive_name == function_name:
                return size, candidate_path
    matches = by_function.get(function_name, [])
    if len(matches) == 1:
        return matches[0]
    base_path = Path(asm_base)
    scoped_matches = [
        (size, path)
        for size, path in matches
        if path == base_path
        or base_path in path.parents
        or path.with_suffix("") == base_path
    ]
    if len(scoped_matches) == 1:
        return scoped_matches[0]
    return None

def collect_pending_functions(root: Path) -> List[PendingFunction]:
    src_root = root / "src"
    if not src_root.is_dir():
        raise RuntimeError(f"No se encontró el directorio: {src_root}")
    pending: List[Tuple[str, str, Path]] = []
    seen = set()
    for source_path in sorted(src_root.rglob("*.c")):
        text = source_path.read_text(encoding="utf-8", errors="replace")
        text = strip_c_comments(text)
        for arguments in iter_include_asm_arguments(text):
            parsed = parse_include_asm(arguments)
            if parsed is None:
                continue
            asm_base, function_name = parsed
            relative_source = source_path.relative_to(root)
            key = (asm_base, function_name, relative_source.as_posix())
            if key not in seen:
                seen.add(key)
                pending.append((asm_base, function_name, relative_source))

    by_function, by_path = index_nonmatching_directives(root)
    functions: List[PendingFunction] = []
    seen_functions = set()
    for asm_base, function_name, source_path in pending:
        resolved = resolve_directive(asm_base, function_name, by_function, by_path)
        if resolved is None:
            continue
        size, asm_path = resolved
        key = (function_name, source_path, asm_path)
        if key in seen_functions:
            continue
        seen_functions.add(key)
        functions.append(
            PendingFunction(
                name=function_name,
                size=size,
                source_path=source_path,
                asm_path=asm_path,
            )
        )
    return functions

def format_median(value: int | float) -> str:
    if isinstance(value, float) and value.is_integer():
        return str(int(value))
    return str(value)

def print_table(functions: List[PendingFunction]) -> None:
    headers = ("Bytes (dec)", "Hex", "Función", "Archivo C origen", "Ruta del archivo .s")
    rows = [
        (
            str(f.size),
            f"0x{f.size:X}",
            f.name,
            f.source_path.as_posix(),
            f.asm_path.as_posix(),
        )
        for f in functions
    ]
    widths = [
        max(len(headers[i]), *(len(r[i]) for r in rows)) if rows else len(headers[i])
        for i in range(len(headers))
    ]
    print(
        f"{headers[0]:>{widths[0]}}  "
        f"{headers[1]:>{widths[1]}}  "
        f"{headers[2]:<{widths[2]}}  "
        f"{headers[3]:<{widths[3]}}  "
        f"{headers[4]:<{widths[4]}}"
    )
    print(
        f"{'-' * widths[0]}  "
        f"{'-' * widths[1]}  "
        f"{'-' * widths[2]}  "
        f"{'-' * widths[3]}  "
        f"{'-' * widths[4]}"
    )
    for row in rows:
        print(
            f"{row[0]:>{widths[0]}}  "
            f"{row[1]:>{widths[1]}}  "
            f"{row[2]:<{widths[2]}}  "
            f"{row[3]:<{widths[3]}}  "
            f"{row[4]:<{widths[4]}}"
        )

def main() -> int:
    root = Path.cwd()
    try:
        pending = collect_pending_functions(root)
    except RuntimeError as error:
        print(f"Error: {error}", file=sys.stderr)
        return 1

    sizes = [f.size for f in pending]
    print(f"Total de funciones pendientes: {len(pending)}")
    if sizes:
        median_size = statistics.median(sizes)
        print(f"Mediana de tamaños: {format_median(median_size)} bytes")
    else:
        print("Mediana de tamaños: N/A")

    candidates = sorted(
        [f for f in pending if 320 <= f.size <= 1000],
        key=lambda f: (f.size, f.name, f.source_path.as_posix(), f.asm_path.as_posix()),
    )
    print()
    print("Candidatas con 320 <= tamaño_bytes <= 1000:")
    print_table(candidates)
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
