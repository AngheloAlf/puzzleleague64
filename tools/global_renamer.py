#!/usr/bin/env python3

# Adapted from https://github.com/zeldaret/mm/blob/main/tools/namefixer.py

# This script is nice because it renames files too

import argparse
import os
from pathlib import Path

# all occurrences of keys will be replaced by associated value
simpleReplace: dict[str, str] = {
}

# all occurrences of keys will be replaced by associated value,
# if the occurence is the whole word
# for example, if there is a space before and an open parenthesis after,
# like for a function call: ` func_8002E4B4(`
wordReplace: dict[str, str] = {
"func_80084DE0_eur": "MimicCheckState",
"func_80088648_eur": "TutorialCheckState",
"func_80055B0C_eur": "CompactWell",
"func_80084894_eur": "UpdateMTController",
"func_80055AC0_eur": "CheckCollision",
"func_80056964_eur": "CheckChainCounter",
"func_80056A00_eur": "ComboCount",
"func_80057210_eur": "CheckShake",
"func_80055FA0_eur": "CheckIcon",
"func_8005D240_eur": "StartAttack",
"func_80059300_eur": "UpdateWell",
"func_8005CDC8_eur": "ChangeAttack",
"func_80059C8C_eur": "UpdateCursor",
"func_80059CE0_eur": "UpdateIcon",
"func_8005C9F0_eur": "UpdateAttack",
"func_80059D20_eur": "UpdateDistance",
"func_80052EC8_eur": "UpdateMiscStuff",
"func_80056CDC_eur": "AddNewRow",
"func_80083500_fra": "MimicCheckState",
"func_80086D68_fra": "TutorialCheckState",
"func_8005427C_fra": "CompactWell",
"func_80082FB4_fra": "UpdateMTController",
"func_80054230_fra": "CheckCollision",
"func_800550D4_fra": "CheckChainCounter",
"func_80055170_fra": "ComboCount",
"func_80055980_fra": "CheckShake",
"func_80054710_fra": "CheckIcon",
"func_8005B980_fra": "StartAttack",
"func_80057A38_fra": "UpdateWell",
"func_8005B508_fra": "ChangeAttack",
"func_800583C4_fra": "UpdateCursor",
"func_80058418_fra": "UpdateIcon",
"func_8005B130_fra": "UpdateAttack",
"func_80058458_fra": "UpdateDistance",
"func_80051638_fra": "UpdateMiscStuff",
"func_8005544C_fra": "AddNewRow",
"func_800836C0_ger": "MimicCheckState",
"func_80086F28_ger": "TutorialCheckState",
"func_800543FC_ger": "CompactWell",
"func_80083174_ger": "UpdateMTController",
"func_800543B0_ger": "CheckCollision",
"func_80055254_ger": "CheckChainCounter",
"func_800552F0_ger": "ComboCount",
"func_80055B00_ger": "CheckShake",
"func_80054890_ger": "CheckIcon",
"func_8005BB30_ger": "StartAttack",
"func_80057BF0_ger": "UpdateWell",
"func_8005B6B8_ger": "ChangeAttack",
"func_8005857C_ger": "UpdateCursor",
"func_800585D0_ger": "UpdateIcon",
"func_8005B2E0_ger": "UpdateAttack",
"func_80058610_ger": "UpdateDistance",
"func_800517B8_ger": "UpdateMiscStuff",
"func_800555CC_ger": "AddNewRow",

}

# [a-zA-Z0-9_]
def is_word_char(c: str) -> bool:
    return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9') or c == '_'

def replace_single(file: Path):
    with file.open('r', encoding = 'utf-8') as infile:
        srcdata = infile.read()

    changesCount = 0

    for old, new in simpleReplace.items():
        # replace `old` with `new`
        if old in srcdata:
            changesCount += 1
            print(old, "->", new)
            srcdata = srcdata.replace(old, new)

    for old, new in wordReplace.items():
        assert old
        assert new

        # replace `old` with `new` if the occurence of `old` is the whole word
        oldStartIdx = srcdata.find(old)
        if oldStartIdx >= 0:
            old_start_as_word = is_word_char(old[0])
            old_end_as_word = is_word_char(old[-1])
            replaceCount = 0
            while oldStartIdx >= 0:
                replace = True
                if old_start_as_word:
                    if oldStartIdx == 0:
                        pass
                    elif is_word_char(srcdata[oldStartIdx-1]):
                        replace = False
                if old_end_as_word:
                    oldEndIdx = oldStartIdx + len(old)
                    if oldEndIdx >= len(srcdata):
                        pass
                    elif is_word_char(srcdata[oldEndIdx]):
                        replace = False
                if replace:
                    srcdata = srcdata[:oldStartIdx] + new + srcdata[oldEndIdx:]
                    replaceCount += 1
                oldStartIdx = srcdata.find(old, oldStartIdx + len(new))
            if replaceCount > 0:
                changesCount += 1
                print(old, "->", new)

    if changesCount > 0:
        print('Changed', changesCount, 'entry' if changesCount == 1 else 'entries', 'in', file)
        with file.open('w', encoding = 'utf-8', newline = '\n') as outfile:
            outfile.write(srcdata)

    newStem = wordReplace.get(file.stem)
    if newStem is not None:
        newPath = file.with_stem(newStem)
        print(f"Renaming '{file}' to '{newPath}'")
        file.rename(newPath)

def replace_all(repo: Path):
    for filename in (repo / "src").rglob("*"):
        if filename.is_file():
            if filename.suffix == '.c' or filename.suffix == '.h':
                replace_single(filename)

    for filename in (repo / "include").rglob("*"):
        if filename.is_file():
            if filename.suffix == '.c' or filename.suffix == '.h':
                replace_single(filename)

    for filename in (repo / "asm").rglob("*"):
        if filename.is_file():
            if filename.suffix == '.s':
                replace_single(filename)

    for filename in (repo / "config").rglob("**/linker_scripts/*"):
        if filename.is_file():
            replace_single(filename)

    for filename in (repo / "config").rglob("**/relocs/*"):
        if filename.is_file():
            replace_single(filename)

    for filename in (repo / "config").rglob("**/symbol_addrs/*"):
        if filename.is_file():
            replace_single(filename)


def dictSanityCheck():
    keys = wordReplace.keys()
    values = wordReplace.values()
    for k in keys:
        assert "+" not in k, f"Invalid character found on '{k}'"
        if k in values:
            print(f"Key '{k}' found in values")
            print(f"This would produce unintended renames")
            print(f"Fix this by removing said key from the dictionary")
            exit(-1)

    keys = simpleReplace.keys()
    values = {*wordReplace.values(), *simpleReplace.values()}
    for k in keys:
        for value in values:
            if k in value:
                print(f"Key '{k}' found in values")
                print(f"This would produce unintended renames")
                print(f"Fix this by removing said key from the dictionary")
                exit(-1)

def main():
    parser = argparse.ArgumentParser(description='Apply function renames to a file')
    parser.add_argument('file', help="source file to be processed. use . to process the whole repo")
    args = parser.parse_args()

    dictSanityCheck()

    if args.file == '.':
        replace_all(Path(os.curdir))
    else:
        replace_single(Path(args.file))

if __name__ == "__main__":
    main()
