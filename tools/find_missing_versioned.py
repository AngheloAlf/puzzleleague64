#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2026 AngheloAlf
# SPDX-License-Identifier: MIT

"""
Silly script to find functions that have been matched on a version but not
others
"""

from __future__ import annotations

from pathlib import Path

import mapfile_parser

BASE_PATH = Path("build/usa/puzzleleague64.usa.map")
EUR_PATH = Path("build/eur/puzzleleague64.eur.map")
FRA_PATH = Path("build/fra/puzzleleague64.fra.map")
GER_PATH = Path("build/ger/puzzleleague64.ger.map")

BASE_MAP = mapfile_parser.MapFile.newFromMapFile(BASE_PATH)
EUR_MAP = mapfile_parser.MapFile.newFromMapFile(EUR_PATH)
FRA_MAP = mapfile_parser.MapFile.newFromMapFile(FRA_PATH)
GER_MAP = mapfile_parser.MapFile.newFromMapFile(GER_PATH)


def find_section_by_name(m: mapfile_parser.MapFile, filepath: Path) -> mapfile_parser.Section | None:
    for seg in m:
        for sect in seg:
            if sect.filepath.name == filepath.name and sect.filepath.parent.name == filepath.parent.name and sect.filepath.parent.parent.name == filepath.parent.parent.name:
                return sect

    return None


for seg in GER_MAP:
    for sect in seg:
        if sect.sectionType != ".text":
            continue

        for sym in sect:
            if sym.nonmatchingSymExists:
                found = BASE_MAP.findSymbolByName(sym.name)
                if found is None:
                    # print(sym)
                    pass
                elif not found.symbol.nonmatchingSymExists:
                    print(sym.name)

        other_sect = find_section_by_name(BASE_MAP, sect.filepath)
        if other_sect is not None:
            nonmatching_count = sum(int(sym.nonmatchingSymExists) for sym in sect)
            nonmatching_count_other = sum(int(sym.nonmatchingSymExists) for sym in other_sect)

            if nonmatching_count != nonmatching_count_other:
                print(sect.filepath, nonmatching_count, nonmatching_count_other)
