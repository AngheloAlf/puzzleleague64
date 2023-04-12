#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 AngheloAlf
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import dataclasses
from pathlib import Path
import spimdisasm


@dataclasses.dataclass
class BinEntry:
    filename: str
    size: int = 0
    offset: int = 0


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("files_folder", help="Folder of the binary files")
    parser.add_argument("output", help="Path and name to the resulting binary")

    args = parser.parse_args()

    filesFolderPath = Path(args.files_folder)
    outputPath = Path(args.output)

    packedBinary = bytearray()

    fileList: list[BinEntry] = []

    for filepath in filesFolderPath.iterdir():
        # The system expects filenames in all caps
        filename = filepath.name.upper()
        fileList.append(BinEntry(filename))

    fileList.sort(key=lambda x: x.filename)

    if len(fileList) > 0x255:
        spimdisasm.common.Utils.eprint(f"There are more files (0x{len(fileList):X}) in the folder ({filesFolderPath}) than the allowed limit (0x255)")
        spimdisasm.common.Utils.eprint(f"The files at the end of the list will not be packaged into the bin_file.")
        fileList = fileList[:0x255]

    currentOffset = 4 + 0x18 * len(fileList)
    for entry in fileList:
        currentPath = filesFolderPath / entry.filename

        currentBinary = spimdisasm.common.Utils.readFileAsBytearray(currentPath)
        assert currentBinary, f"'{currentPath}' not found"

        entry.size = len(currentBinary)
        entry.offset = currentOffset

        packedBinary.extend(currentBinary)

        currentOffset += entry.size

        # Align every file to halfword
        if currentOffset & 1:
            currentOffset += 1
            packedBinary.append(0xFF)


    outputPath.parent.mkdir(parents=True, exist_ok=True)
    with outputPath.open("wb") as f:
        buffer = bytearray(4)
        spimdisasm.common.Utils.wordsToBytes([len(fileList)], buffer)
        f.write(buffer)

        for entry in fileList:
            buffer = bytearray(0x8)
            spimdisasm.common.Utils.wordsToBytes([entry.size, entry.offset], buffer)
            f.write(buffer)

            buffer = bytearray(entry.filename.encode("ascii"))
            while len(buffer) < 0x10:
                buffer.append(0)
            f.write(buffer)

        f.write(packedBinary)



if __name__ == "__main__":
    main()

