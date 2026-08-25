#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2026 AngheloAlf
# SPDX-License-Identifier: MIT

import argparse
from pathlib import Path
from typing import Generator


def iter_syms(path: Path) -> Generator[tuple[str, int], None, None]:
    sym = None
    for line in path.open():
        if sym is not None:
            stuff = line.strip().split("/*")[1].split("*/")[0].strip().split(" ")
            # Get the element on the middle.
            # This should work for getting the vram on bss and data
            addr = int(stuff[len(stuff) // 2], 16)
            yield sym, addr
            sym = None
        if line.startswith("dlabel"):
            sym = line.strip().split("dlabel ")[1]


def find_first_file(main_dir: Path, sym: str) -> Path | None:
    for current_dir, _, filename_list in main_dir.walk():
        for filename in filename_list:
            this_file = current_dir / filename
            full_text = this_file.read_text()
            index = full_text.find(f"({sym}")
            if index == -1:
                continue
            expr = full_text[index+1:].split(")")[0].split(" ")[0]
            if sym == expr:
                return this_file
    return None


parser = argparse.ArgumentParser()

parser.add_argument("path")

args = parser.parse_args()

path = Path(args.path)

VERSIONS = {
    "usa",
    "eur",
    "fra",
    "ger",
}

version = None
for p in path.parents:
    if p.name in VERSIONS:
        version = p.name
        break

if version is None:
    print("Version not found")
    exit(1)

main_dir = Path(f"asm/{version}/nonmatchings/main/")
main_dir2 = Path(f"asm/{version}/matchings/main/")

duplicated = set()
all_files = set()

files = [("", -1)]
for sym, addr in iter_syms(path):
    file = find_first_file(main_dir, sym) or find_first_file(main_dir2, sym)
    if file is not None:
        name = file.parent.name
        if files[-1][0] != name:
            files.append((name, addr))
            if name in all_files:
                duplicated.add(name)
            all_files.add(name)
    else:
        print(f"Not found: {addr:08X} '{sym}'")

if duplicated:
    print(duplicated)

for (name, addr) in files:
    if addr < 0:
        continue
    print(f"      - {{ type: bss, vram: 0x{addr:08X}, name: main/{name} }}")
