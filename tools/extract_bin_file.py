#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 AngheloAlf
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
from pathlib import Path
import spimdisasm


bin_file_offset = {
    "usa": 0x9BDB40,
    "eur": 0x9BDDF0,
    "fra": 0x9BC450,
    "ger": 0x9B2BB0,
}

ENTRY_SIZE = 4 + 4 + 0x10


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("output", help="Folder to put the extracted files")
    parser.add_argument("-v", "--version", help="Which version should be processed", default="usa", choices=["usa", "eur", "fra", "ger"])

    args = parser.parse_args()

    segmentOffset = bin_file_offset.get(args.version, -1)
    if segmentOffset < 0:
        print(f"Version '{args.version}' does not have the bin_file offset set yet")
        exit(-1)

    baseromPath = Path(f"baserom.{args.version}.z64")
    baserom = spimdisasm.common.Utils.readFileAsBytearray(baseromPath)
    assert baserom, f"'{baseromPath}' not found"

    outputFolder = Path(args.output)
    outputFolder.mkdir(parents=True, exist_ok=True)

    offset = segmentOffset
    filecount = spimdisasm.common.Utils.bytesToWords(baserom, offset, offset+4)[0]
    offset += 4

    totalSize = 0
    largerEnd = 0

    stats = dict()

    for i in range(filecount):
        fileSize, fileOffset = spimdisasm.common.Utils.bytesToWords(baserom, offset, offset+8)
        fileNameList = spimdisasm.common.Utils.decodeString(baserom, offset + 8, "ascii")
        assert len(fileNameList[0]) == 1, f"fileNameList yield more or less than 1 result: {fileNameList}"
        fileName = fileNameList[0][0]
        print(f"{i:>3}", f"0x{fileSize:06X}", f"0x{fileOffset:06X}", fileName)

        currentFile = outputFolder / fileName

        extension = currentFile.suffix
        if extension not in stats:
            stats[extension] = 0
        stats[extension] += 1

        with currentFile.open("wb") as f:
            fileStart = fileOffset + segmentOffset
            fileEnd = fileStart + fileSize
            if fileEnd > largerEnd:
                largerEnd = fileEnd
            f.write(baserom[fileStart:fileEnd])

        totalSize += fileSize

        offset += ENTRY_SIZE

    print(f"0x{offset:06X}", f"0x{offset-segmentOffset:06X}")
    print(f"Total files size: {totalSize} bytes, {totalSize / 1024} kilobytes, {totalSize / 1024 / 1024} megabytes")
    print(f"Segment end: 0x{largerEnd:06X}")
    print(stats)


if __name__ == "__main__":
    main()
