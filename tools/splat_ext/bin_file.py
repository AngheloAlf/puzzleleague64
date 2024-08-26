#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 AngheloAlf
# SPDX-License-Identifier: MIT

from pathlib import Path
from typing import Optional
import spimdisasm

from splat.util import log, options

from splat.segtypes.common.segment import Segment


ENTRY_SIZE = 4 + 4 + 0x10

class N64SegBin_file(Segment):
    def out_path(self) -> Optional[Path]:
        if self.type.startswith("."):
            return options.opts.src_path / self.dir / f"{self.name}.s"
        return options.opts.asset_path / self.dir / f"{self.name}.bin"

    def folder_path(self) -> Path:
        return options.opts.asset_path / self.dir

    def split(self, rom_bytes):
        path = self.out_path()
        assert path is not None
        path.parent.mkdir(parents=True, exist_ok=True)

        if self.rom_end is None:
            log.error(
                f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
            )

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        outputFolder = self.folder_path()
        outputFolder.mkdir(parents=True, exist_ok=True)

        offset = self.rom_start
        filecount = spimdisasm.common.Utils.bytesToWords(rom_bytes, offset, offset+4)[0]
        assert filecount > 0
        offset += 4

        lastFileEnd = 0

        for i in range(filecount):
            fileSize, fileOffset = spimdisasm.common.Utils.bytesToWords(rom_bytes, offset, offset+8)
            fileNameList = spimdisasm.common.Utils.decodeString(rom_bytes, offset + 8, "ascii")
            assert len(fileNameList[0]) == 1, f"fileNameList yield more or less than 1 result: {fileNameList}"
            fileName = fileNameList[0][0]

            currentFile = outputFolder / fileName

            with currentFile.open("wb") as f:
                fileStart = fileOffset + self.rom_start
                fileEnd = fileStart + fileSize
                f.write(rom_bytes[fileStart:fileEnd])
                lastFileEnd = fileEnd

            self.log(f"Wrote {fileName} to {currentFile}")

            offset += ENTRY_SIZE

        if lastFileEnd != self.rom_end:
            fileName = ".garbage.garbage"
            currentFile = outputFolder / fileName

            with currentFile.open("wb") as f:
                fileStart = lastFileEnd
                fileEnd = self.rom_end
                f.write(rom_bytes[fileStart:fileEnd])

            self.log(f"Wrote {fileName} to {currentFile}")

    def should_split(self) -> bool:
        return options.opts.is_mode_active(self.type)
