#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2025 AngheloAlf
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import mapfile_parser
from pathlib import Path

def progressMain():
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", help="version to process", default="usa")

    args = parser.parse_args()

    mapPath = Path("build") / args.version / f"puzzleleague64.{args.version}.map"

    mapFile = mapfile_parser.MapFile()
    mapFile.readMapFile(mapPath)

    prefixesToTrim = [
        f"build/{args.version}/lib/",
        f"build/{args.version}/src/",
        f"build/{args.version}/asm/{args.version}/data/",
        f"build/{args.version}/asm/{args.version}/",
        f"build/{args.version}/",
        f"build/"
    ]

    categories = mapfile_parser.ReportCategories()
    # id, name, paths
    categories.push("rom_header", "rom_header", ["rom_header/"])
    categories.push("ipl3", "ipl3", ["us/data/ipl3"])
    categories.push("entry", "entry", ["entry/"])

    categories.push("game_cod", "Game code", ["main/"])

    categories.push("libkmc", "libkmc", ["libkmc/"])
    categories.push("libultra", "libultra", ["libultra/", "ultralib/"])
    categories.push("libmus", "libmus", ["libmus/"])
    categories.push("flash", "flash", ["flash/"])
    categories.push("libhvqm", "libhvqm", ["libhvqm/"])

    categories.push("libs", "Libraries", ["libkmc/", "libultra/", "ultralib/", "libmus/", "flash/", "libhvqm/"])

    categories.push("rsp", "rsp", ["rsp/"])
    categories.push("buffers", "buffers", ["buffers/"])
    categories.push("assets", "assets", ["assets/", "segment_", "bin_file", "12C1B0", "5337F0", "1C60660", "1D3D320"])

    mapFile.writeObjdiffReportToFile("report_puzzleleague.json", prefixesToTrim, categories, "asm", pathIndex=3)

if __name__ == "__main__":
    progressMain()
