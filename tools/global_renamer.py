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
"func_80049034_eur": "func_80048D94_usa",
"func_800477B4_fra": "func_80048D94_usa",
"func_80047924_ger": "func_80048D94_usa",
"D_800B6F00_eur": "attack_combo7",
"D_800B6F14_eur": "attack_chain3",
"D_800B6F14_eur": "attack_chain3",
"D_800B6F08_eur": "ring_chain3",
"D_800B6F20_eur": "attack_chain4",
"D_800B6F24_eur": "attack_chain5",
"D_800B6F28_eur": "attack_chain6",
"D_800B6F30_eur": "attack_chain7",
"D_800B6F38_eur": "attack_chain8",
"D_800B6F40_eur": "attack_chain9",
"D_800B6F48_eur": "attack_chain10",
"D_800B6F54_eur": "attack_chain11",
"D_800B6F60_eur": "attack_chain12",
"D_800B6F6C_eur": "attack_chain13",
"D_800B6F00_eur": "attack_combo7",
"D_800B6F14_eur": "attack_chain3",
"D_800B6F78_eur": "attackRow1",
"D_800B6F80_eur": "attackRow2",
"D_800B6F88_eur": "attackRow3",
"D_800B6F90_eur": "attackRow4",
"D_800B6F98_eur": "attackRow5",
"D_800B6FA0_eur": "attackRow6",
"D_800B6FA8_eur": "attackRow7",
"D_800B6FB0_eur": "attackRow8",
"D_800B6FB8_eur": "attackRow9",
"D_800B5720_fra": "attack_combo4",
"D_800B5724_fra": "attack_combo5",
"D_800B5728_fra": "attack_combo6",
"D_800B5730_fra": "attack_combo7",
"D_800B5744_fra": "attack_chain3",
"D_800B5744_fra": "attack_chain3",
"D_800B5738_fra": "ring_chain3",
"D_800B5750_fra": "attack_chain4",
"D_800B5754_fra": "attack_chain5",
"D_800B5758_fra": "attack_chain6",
"D_800B5760_fra": "attack_chain7",
"D_800B5768_fra": "attack_chain8",
"D_800B5770_fra": "attack_chain9",
"D_800B5778_fra": "attack_chain10",
"D_800B5784_fra": "attack_chain11",
"D_800B5790_fra": "attack_chain12",
"D_800B579C_fra": "attack_chain13",
"D_800B5730_fra": "attack_combo7",
"D_800B5744_fra": "attack_chain3",
"D_800B57A8_fra": "attackRow1",
"D_800B57B0_fra": "attackRow2",
"D_800B57B8_fra": "attackRow3",
"D_800B57C0_fra": "attackRow4",
"D_800B57C8_fra": "attackRow5",
"D_800B57D0_fra": "attackRow6",
"D_800B57D8_fra": "attackRow7",
"D_800B57E0_fra": "attackRow8",
"D_800B57E8_fra": "attackRow9",
"D_800AC950_ger": "attack_combo4",
"D_800AC954_ger": "attack_combo5",
"D_800AC958_ger": "attack_combo6",
"D_800AC960_ger": "attack_combo7",
"D_800AC974_ger": "attack_chain3",
"D_800AC974_ger": "attack_chain3",
"D_800AC968_ger": "ring_chain3",
"D_800AC980_ger": "attack_chain4",
"D_800AC984_ger": "attack_chain5",
"D_800AC988_ger": "attack_chain6",
"D_800AC990_ger": "attack_chain7",
"D_800AC998_ger": "attack_chain8",
"D_800AC9A0_ger": "attack_chain9",
"D_800AC9A8_ger": "attack_chain10",
"D_800AC9B4_ger": "attack_chain11",
"D_800AC9C0_ger": "attack_chain12",
"D_800AC9CC_ger": "attack_chain13",
"D_800AC960_ger": "attack_combo7",
"D_800AC974_ger": "attack_chain3",
"D_800AC9D8_ger": "attackRow1",
"D_800AC9E0_ger": "attackRow2",
"D_800AC9E8_ger": "attackRow3",
"D_800AC9F0_ger": "attackRow4",
"D_800AC9F8_ger": "attackRow5",
"D_800ACA00_ger": "attackRow6",
"D_800ACA08_ger": "attackRow7",
"D_800ACA10_ger": "attackRow8",
"D_800ACA18_ger": "attackRow9",
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
