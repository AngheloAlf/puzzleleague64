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
    filepath: Path
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
    # Some versions have garbage padding and we need to preserve it
    garbageFilename: Path|None = None

    fileList: list[BinEntry] = []

    for filepath in filesFolderPath.iterdir():
        if filepath.name == ".garbage.garbage":
            garbageFilename = filepath
            continue
        fileList.append(BinEntry(filepath))

    fileList.sort(key=lambda x: x.filepath.name.upper())

    if len(fileList) > 0x255:
        spimdisasm.common.Utils.eprint(f"There are more files (0x{len(fileList):X}) in the folder ({filesFolderPath}) than the allowed limit (0x255)")
        spimdisasm.common.Utils.eprint(f"The files at the end of the list will not be packaged into the bin_file.")
        fileList = fileList[:0x255]

    # Read all the files, get their sizes and pre-package them
    currentOffset = 4 + 0x18 * len(fileList)
    for entry in fileList:
        currentBinary = spimdisasm.common.Utils.readFileAsBytearray(entry.filepath)
        assert currentBinary, f"'{entry.filepath}' not found"

        entry.size = len(currentBinary)
        entry.offset = currentOffset

        packedBinary.extend(currentBinary)
        currentOffset += entry.size

        # Align every file to halfword
        if currentOffset & 1:
            currentOffset += 1
            packedBinary.append(0xFF)

    # Add the garbage to the pre-packaged binary
    if garbageFilename is not None:
        currentBinary = spimdisasm.common.Utils.readFileAsBytearray(garbageFilename)
        assert currentBinary, f"'{garbageFilename}' not found"

        packedBinary.extend(currentBinary)

    outputPath.parent.mkdir(parents=True, exist_ok=True)
    with outputPath.open("wb") as f:
        buffer = spimdisasm.common.Utils.wordsToBytes([len(fileList)])
        f.write(buffer)

        for entry in fileList:
            buffer = spimdisasm.common.Utils.wordsToBytes([entry.size, entry.offset])
            f.write(buffer)

            # The system expects filenames in all caps
            buffer = bytearray(entry.filepath.name.upper().encode("ascii"))
            while len(buffer) < 0x10:
                buffer.append(0)
            f.write(buffer)

        f.write(packedBinary)


if __name__ == "__main__":
    main()

