#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2025 AngheloAlf
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import dataclasses
from pathlib import Path
import struct
import sys
from typing import TextIO, NoReturn

def fatal_error(*args, **kwargs) -> NoReturn:
    print("Error:", *args, file=sys.stderr, **kwargs)
    exit(1)


def u16(data: bytes, offset: int) -> int:
    assert offset >= 0
    assert offset < len(data)
    return struct.unpack_from(">H", data, offset)[0]

def s16(data: bytes, offset: int) -> int:
    assert offset >= 0
    assert offset < len(data)
    return struct.unpack_from(">h", data, offset)[0]


@dataclasses.dataclass
class FlicAnimeBGHeader:
    bpp: int
    is_intensity: int
    width: int
    height: int
    x: int
    y: int

    @staticmethod
    def size() -> int:
        return 0xC

    @staticmethod
    def from_bin(bin_bytes: bytes, offset: int) -> FlicAnimeBGHeader:
        bpp          = s16(bin_bytes, offset + 0x0)
        is_intensity = s16(bin_bytes, offset + 0x2)
        width        = s16(bin_bytes, offset + 0x4)
        height       = s16(bin_bytes, offset + 0x6)
        x            = u16(bin_bytes, offset + 0x8)
        y            = u16(bin_bytes, offset + 0xA)

        return FlicAnimeBGHeader(
            bpp = bpp,
            is_intensity = is_intensity,
            width = width,
            height = height,
            x = x,
            y = y,
        )


def write_yaml(name: str, headers: list[FlicAnimeBGHeader], bin_bytes: bytes):
    with Path(f"config/assets/flic_anime_bg/{name}.yaml").open("w") as yaml_file:
        yaml_file.write(f"""\
segments:
  - type: group
    start: 0x0
    dir: flic_anime_bg/{name}
    subsegments:
""")
        for i in range(len(headers)):
            header = headers[i]
            start = "0x18" if i == 0 else "auto"

            assert header.bpp == 16, name
            yaml_file.write(f"      - {{ start: {start}, type: rgba16, name: tex{i}.rgba16, width: {header.width:>3}, height: {header.height:>3} }}\n")
        yaml_file.write(f"  - [0x{len(bin_bytes):06X}]\n\n")
        yaml_file.write(f"""\
options:
  basename: ""
  base_path: ../../../../../
  compiler: GCC
  find_file_boundaries: False
  platform: n64
  extensions_path: tools/splat_ext

  do_c_func_detection: False
  o_as_suffix: True
  gfx_ucode: f3dex
  use_legacy_include_asm: False
  create_undefined_funcs_auto: False
  create_undefined_syms_auto: False
""")

def write_c(name: str, headers: list[FlicAnimeBGHeader]):
    with Path(f"src/assets/flic_anime_bg/{name}.c").open("w") as c_file:
        c_file.write(f"""\
#include "assets/flic_anime_bg.h"

#include "alignment.h"
""")
        for i in range(len(headers)):
            header = headers[i]

            # assert header.bpp == 16, name
            c_file.write(f"""\

FlicAnimeBGHeader flic_anime_bg_{name}_{i}_header = {{
    {header.bpp}, // bpp
    {header.is_intensity}, // is_intensity
    {header.width}, // width
    {header.height}, // height
    {header.x}, // x
    {header.y}, // y
}};
""")

        for i in range(len(headers)):
            header = headers[i]

            assert header.bpp == 16, name
            c_file.write(f"""\

u16 flic_anime_bg_{name}_{i}_texture[] ALIGNED(8) = {{
#include "assets/flic_anime_bg/{name}/tex{i}.rgba16.inc"
}};
""")


def do_bin(bin_path: Path):
    bin_bytes = bin_path.read_bytes()

    name = bin_path.with_suffix("").with_suffix("").stem

    headers: list[FlicAnimeBGHeader] = []

    offset = 0
    for i in range(2):
        header = FlicAnimeBGHeader.from_bin(bin_bytes, offset)
        # Everything seens to be rgba16
        assert header.bpp == 16, bin_path

        headers.append(header)
        offset += FlicAnimeBGHeader.size()

    write_yaml(name, headers, bin_bytes)
    write_c(name, headers)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-v", "--version", help="version to process", default="usa")

    args = parser.parse_args()

    flic_anime_bg_folder = Path(f"bin/{args.version}/assets_bins/flic_anime_bg")
    if not flic_anime_bg_folder.exists():
        fatal_error(flic_anime_bg_folder, "does not exist.")

    for p in flic_anime_bg_folder.iterdir():
        if not p.is_file():
            fatal_error("Found unexpected", p, "path.")
        do_bin(p)

if __name__ == "__main__":
    main()
