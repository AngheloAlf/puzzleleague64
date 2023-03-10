#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 AngheloAlf
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import mapfile_parser
from pathlib import Path


def mapToPj64symsMain():
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", help="version to process", default="usa")
    parser.add_argument("-o", "--output", default="PUZZLE LEAGUE N64.sym", type=Path)

    args = parser.parse_args()

    version: str = args.version
    output: Path = args.output
    mapPath = Path("build") / f"puzzleleague.{version}.map"

    exit(mapfile_parser.frontends.pj64_syms.doPj64Syms(mapPath, output))

if __name__ == "__main__":
    mapToPj64symsMain()
