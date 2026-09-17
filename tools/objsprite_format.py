#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2026 AngheloAlf
# SPDX-License-Identifier: MIT

import argparse
import re
from collections.abc import Callable
from pathlib import Path


def main() -> None:
    parser = argparse.ArgumentParser()

    parser.add_argument("path", nargs="?")

    args = parser.parse_args()

    if args.path is None:
        for current_dir, _, filename_list in Path("src/main/").walk():
            for filename in filename_list:
                this_file = current_dir / filename
                original, fixed = find_fixups(this_file)
                if original != fixed:
                    print(f"Fixing {this_file}")
                    this_file.write_text("".join(fixed))
    else:
        path = Path(args.path)

        original, fixed = find_fixups(path)
        if original != fixed:
            path.write_text("".join(fixed))


def find_fixups(path: Path) -> tuple[list[str], list[str]]:
    original = []
    fixed = []

    with path.open() as f:
        for line in f:
            original.append(line)
            fixed.append(fixup_line(line))

    return (original, fixed)


def fixup_line(line: str) -> str:
    """
    Tries to fix a line by applying regexes and using each associated callback
    """

    for reg, callback in REGEXES:
        m = reg.search(line)
        if m is not None:
            accesor = m.group("accesor")
            field = m.group("field")
            value = callback(m.group("value"))
            recreated = f"{accesor}{field} = {value};"
            fixed = reg.sub(recreated, line, count=1)
            return fixed

    return line



def unshift(value: str, shift: int) -> str:
    """
    Unshift a fractional value into a shifted expression

    For example,
    0x400 -> 256 << 2
    0x803 -> (512 << 2) + 3
    """
    val = int(value, 0)
    negative = False
    if val < 0:
        val = -val
        negative = True

    d = 1 << shift
    i = val // d
    f = val % d

    integer_part = f"{i} << {shift}"
    if negative:
        if f == 0:
            return f"-({integer_part})"
        if i == 0:
            return f"-{f}"
        return f"-(({integer_part}) + {f})"
    else:
        if f == 0 and i == 0:
            return "0"
        if f == 0:
            return integer_part
        if i == 0:
            return f"{f}"
        return f"({integer_part}) + {f}"


VALUE_PATTERN = r"(?P<value>-?0x[0-9A-Fa-f]+|-?[0-9]+)"

RE_OBJX = re.compile(f"(?P<accesor>.|->)(?P<field>objX) = {VALUE_PATTERN};") # s10.2
RE_OBJY = re.compile(f"(?P<accesor>.|->)(?P<field>objY) = {VALUE_PATTERN};") # s10.2
RE_SCALEW = re.compile(f"(?P<accesor>.|->)(?P<field>scaleW) = {VALUE_PATTERN};") # u5.10
RE_SCALEH = re.compile(f"(?P<accesor>.|->)(?P<field>scaleH) = {VALUE_PATTERN};") # u5.10
RE_IMAGEW = re.compile(f"(?P<accesor>.|->)(?P<field>imageW) = {VALUE_PATTERN};") # u10.5
RE_IMAGEH = re.compile(f"(?P<accesor>.|->)(?P<field>imageH) = {VALUE_PATTERN};") # u10.5
RE_IMAGEFMT = re.compile(f"(?P<accesor>.|->)(?P<field>imageFmt) = {VALUE_PATTERN};") # G_IM_FMT_
RE_IMAGESIZ = re.compile(f"(?P<accesor>.|->)(?P<field>imageSiz) = {VALUE_PATTERN};") # G_IM_SIZ_

IM_FMTS: list[str] = [
    "G_IM_FMT_RGBA",
    "G_IM_FMT_YUV",
    "G_IM_FMT_CI",
    "G_IM_FMT_IA",
    "G_IM_FMT_I",
]
def get_im_fmt(value: str) -> str:
    val = int(value, 0)
    if val < 0 or val >= len(IM_FMTS):
        return value
    return IM_FMTS[val]

IM_SIZS: list[str] = [
    "G_IM_SIZ_4b",
    "G_IM_SIZ_8b",
    "G_IM_SIZ_16b",
    "G_IM_SIZ_32b",
]
def get_im_siz(value: str) -> str:
    val = int(value, 0)
    if val < 0 or val >= len(IM_SIZS):
        return value
    return IM_SIZS[val]

REGEXES: list[tuple[re.Pattern[str], Callable[[str], str]]] = [
    (RE_OBJX, lambda value: unshift(value, 2)),
    (RE_OBJY, lambda value: unshift(value, 2)),
    (RE_SCALEW, lambda value: unshift(value, 10)),
    (RE_SCALEH, lambda value: unshift(value, 10)),
    (RE_IMAGEW, lambda value: unshift(value, 5)),
    (RE_IMAGEH, lambda value: unshift(value, 5)),
    (RE_IMAGEFMT, get_im_fmt),
    (RE_IMAGESIZ, get_im_siz),
]


if __name__ == "__main__":
    main()
