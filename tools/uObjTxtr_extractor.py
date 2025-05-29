#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 AngheloAlf
# SPDX-License-Identifier: MIT

# http://n64devkit.square7.ch/ucode/s2dex/04.htm

from __future__ import annotations

import argparse
from pathlib import Path
import spimdisasm
import struct
import sys
from typing import NoReturn


def fatalError(*args, **kwargs) -> NoReturn:
    print("Error:", *args, file=sys.stderr, **kwargs)
    exit(1)


def u8(data: bytearray, offset: int) -> int:
    assert offset >= 0
    assert offset < len(data)
    return data[offset]

def u16(data: bytearray, offset: int) -> int:
    assert offset >= 0
    assert offset < len(data)
    return struct.unpack_from(">H", data, offset)[0]

def u32(data: bytearray, offset: int) -> int:
    assert offset >= 0
    assert offset < len(data)
    return struct.unpack_from(">I", data, offset)[0]


uObjTxtr_size = 0x18

G_OBJLT_TXTRBLOCK = 0x00001033
G_OBJLT_TXTRTILE  = 0x00fc1034
G_OBJLT_TLUT      = 0x00000030


G_IM_SIZ_4b  = 0
G_IM_SIZ_8b  = 1
G_IM_SIZ_16b = 2
G_IM_SIZ_32b = 3

imSizeNames = {
    G_IM_SIZ_4b : f"G_IM_SIZ_4b",
    G_IM_SIZ_8b : f"G_IM_SIZ_8b",
    G_IM_SIZ_16b: f"G_IM_SIZ_16b",
    G_IM_SIZ_32b: f"G_IM_SIZ_32b",
}


G_TX_DXT_FRAC = 11

def GS_CALC_DXT(line: int) -> int:
    return (((1<< G_TX_DXT_FRAC)-1)//(line)+1)
def GS_PIX2TMEM(pix: int, siz: int) -> int:
    return ((pix)>>(4-(siz)))
def GS_PIX2DXT(pix: int, siz: int) -> int:
    return GS_CALC_DXT(GS_PIX2TMEM((pix), (siz)))


def GS_TB_TSIZE(pix: int, siz: int) -> int:
    return (GS_PIX2TMEM((pix),(siz))-1)
def GS_TB_TLINE(pix: int, siz: int) -> int:
    return (GS_CALC_DXT(GS_PIX2TMEM((pix),(siz))))


def calculate_block_height(tsize, tline):
    return (tsize + 1) * (tline - 1) / ((1<< G_TX_DXT_FRAC)-1)

def calculate_block_width(tsize, siz, height):
    return ((tsize + 1) << (4 - siz)) / height


def process_TxtrBlock(data: bytearray, name: str):
    typ   = u32(data, 0x0)  # Type G_OBJLT_TXTRBLOCK
    image = u32(data, 0x4)  # Texture source address in DRAM
    tmem  = u16(data, 0x8)  # TMEM word address of load destination(8byteWORD)
    tsize = u16(data, 0xA)  # Texture size     Specified by the macro GS_TB_TSIZE()
    tline = u16(data, 0xC)  # Texture 1 line width Specified by the macro GS_TB_TLINE()
    sid   = u16(data, 0xE)  # Status ID  Select from { 0, 4, 8, 12 }
    flag  = u32(data, 0x10) # Status flag
    mask  = u32(data, 0x14) # Status mask

    typ   = u32(data, 0x0)  # Type G_OBJLT_TXTRBLOCK
    assert typ == G_OBJLT_TXTRBLOCK

    tmemStr = f"{tmem}"
    tsizeStr = f"{tsize}"
    tlineStr = f"{tline}"

    height = int(round(calculate_block_height(tsize, tline), 0))
    print(f"#if 0")
    print(f"height:", height)
    print()
    print(f"Possible widths:")
    for siz, imName in imSizeNames.items():
        width = calculate_block_width(tsize, siz, height)
        width = int(round(width, 0))
        print(f"    {width} ({imName})")
    print()

    # TODO
    if tmem == 0:
        print(f"Possible combinations:", end="")
        for siz, imName in imSizeNames.items():
            width = calculate_block_width(tsize, siz, height)
            width = int(round(width, 0))

            if GS_PIX2TMEM(0, siz) != tmem:
                continue
            if GS_TB_TSIZE(width * height, siz) != tsize:
                continue
            if GS_TB_TLINE(width, siz) != tline:
                continue

            print()
            print(f"    /* tmem  */ GS_PIX2TMEM(0,       {imName}),")
            print(f"    /* tsize */ GS_TB_TSIZE({width} * {height}, {imName}),")
            print(f"    /* tline */ GS_TB_TLINE({width},      {imName}),")

    print(f"#endif")

    flagStr = f"0x{flag:X}"
    if flag == 0xFFFFFFFF:
        flagStr = f"-1"

    maskStr = f"0x{mask:X}"
    if mask == 0xFFFFFFFF:
        maskStr = f"-1"

    print(f"uObjTxtr {name} = {{")
    print(f"    /* type  */ G_OBJLT_TXTRBLOCK,")
    print(f"    /* image */ (u64 *)D_{image:08X},")
    print(f"    /* tmem  */ {tmemStr},")
    print(f"    /* tsize */ {tsizeStr},")
    print(f"    /* tline */ {tlineStr},")
    print(f"    /* sid   */ {sid},")
    print(f"    /* flag  */ (u32){flagStr},")
    print(f"    /* mask  */ {maskStr},")
    print(f"}};")


def GS_TT_TWIDTH(pix: int, siz: int) -> int:
    return ((GS_PIX2TMEM((pix), (siz))<<2)-1)
def GS_TT_THEIGHT(pix: int, siz: int) -> int:
    return (((pix)<<2)-1)


def process_TxtrTile(data: bytearray, name: str):
    typ     = u32(data, 0x0)  # Type G_OBJLT_TXTRTILE
    image   = u32(data, 0x4)  # Texture source address in DRAM
    tmem    = u16(data, 0x8)  # TMEM words address of load destination(8byteWORD)
    twidth  = u16(data, 0xA)  # Texture width  Specified by the macro GS_TT_TWIDTH()
    theight = u16(data, 0xC)  # Texture height  Specified by the macro GS_TT_THEIGHT()
    sid     = u16(data, 0xE)  # Status ID  Select from { 0, 4, 8, 12 }
    flag    = u32(data, 0x10) # Status flag
    mask    = u32(data, 0x14) # Status mask

    assert typ == G_OBJLT_TXTRTILE

    tmemStr = f"{tmem}"
    twidthStr = f"{twidth}"
    theightStr = f"{theight}"

    flagStr = f"0x{flag:X}"
    if flag == 0xFFFFFFFF:
        flagStr = f"-1"

    maskStr = f"0x{mask:X}"
    if mask == 0xFFFFFFFF:
        maskStr = f"-1"

    print(f"uObjTxtr {name} = {{")
    print(f"    /* type    */ G_OBJLT_TXTRTILE,")
    print(f"    /* image   */ (u64 *)D_{image:08X},")
    print(f"    /* tmem    */ {tmemStr},")
    print(f"    /* twidth  */ {twidthStr},")
    print(f"    /* theight */ {theightStr},")
    print(f"    /* sid     */ {sid},")
    print(f"    /* flag    */ (u32){flagStr},")
    print(f"    /* mask    */ {maskStr},")
    print(f"}};")

def GS_PAL_HEAD(head):
    return ((head)+256)
def GS_PAL_NUM(num):
    return ((num)-1)


def process_TxtrTLUT(data: bytearray, name: str):
    typ   = u32(data, 0x0)  # Type G_OBJLT_TLUT
    image = u32(data, 0x4)  # Texture source address in DRAM
    phead = u16(data, 0x8)  # Number in TLUT area over 256 and under 511 of load destination
    pnum  = u16(data, 0xA)  # Number of TLUT to be loaded - 1
    zero  = u16(data, 0xC)  # 0 is always substituted
    sid   = u16(data, 0xE)  # Status ID  Select from { 0, 4, 8, 12 }
    flag  = u32(data, 0x10) # Status flag
    mask  = u32(data, 0x14) # Status mask

    assert typ == G_OBJLT_TLUT

    pheadStr = f"GS_PAL_HEAD({phead-256})"
    pnumStr  = f"GS_PAL_NUM({pnum+1})"

    flagStr = f"0x{flag:X}"
    if flag == 0xFFFFFFFF:
        flagStr = f"-1"

    maskStr = f"0x{mask:X}"
    if mask == 0xFFFFFFFF:
        maskStr = f"-1"

    print(f"uObjTxtr {name} = {{")
    print(f"    /* type  */ G_OBJLT_TLUT,")
    print(f"    /* image */ (u64 *)D_{image:08X},")
    print(f"    /* phead */ {pheadStr},")
    print(f"    /* pnum  */ {pnumStr},")
    print(f"    /* zero  */ {zero},")
    print(f"    /* sid   */ {sid},")
    print(f"    /* flag  */ (u32){flagStr},")
    print(f"    /* mask  */ {maskStr},")
    print(f"}};")


typesProcessors = {
    G_OBJLT_TXTRBLOCK : process_TxtrBlock,
    G_OBJLT_TXTRTILE  : process_TxtrTile,
    G_OBJLT_TLUT      : process_TxtrTLUT,
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("offset", help="Rom offset to the uObjTxtr element")
    parser.add_argument("-n", "--name", help="Name to be used for the generated variable")
    parser.add_argument("-v", "--version", help="version to process", default="usa")

    args = parser.parse_args()

    baseromPath = Path(f"baserom.{args.version}.z64")
    if not baseromPath.exists():
        fatalError(baseromPath, "not found")

    offset = int(args.offset, 0)
    name = args.name
    if name is None:
        name = f"D_{offset:X}"
    # print(name)

    fileContents = spimdisasm.common.Utils.readFileAsBytearray(baseromPath)
    assert len(fileContents) > 0

    data = fileContents[offset : offset + uObjTxtr_size]
    assert len(data) == uObjTxtr_size

    typ = u32(data, 0x0)
    processor = typesProcessors.get(typ)
    if processor is None:
        fatalError(f"Provided offset (0x{offset:06X}) does not point to a valid uObjTxtr")

    processor(data, name)


if __name__ == "__main__":
    main()
