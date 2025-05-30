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
"D_800B78A0_eur": "D_800B7380_usa",
"D_800B78B8_eur": "D_800B7398_usa",
"D_800B78D0_eur": "D_800B73B0_usa",
"D_800B78E8_eur": "D_800B73C8_usa",
"D_800B7900_eur": "D_800B73E0_usa",
"D_800B7918_eur": "D_800B73F8_usa",
"D_800B7930_eur": "D_800B7410_usa",
"D_800B7948_eur": "D_800B7428_usa",
"D_800B7960_eur": "D_800B7440_usa",
"D_800B7978_eur": "D_800B7458_usa",
"D_800B7990_eur": "D_800B7470_usa",
"D_800B79A8_eur": "D_800B7488_usa",
"D_800B79C0_eur": "D_800B74A0_usa",
"D_800B7918_eur": "D_800B73F8_usa",
"D_800B7930_eur": "D_800B7410_usa",
"D_800B7948_eur": "D_800B7428_usa",
"D_800B7960_eur": "D_800B7440_usa",
"D_800B78D0_eur": "D_800B73B0_usa",
"D_800B7918_eur": "D_800B73F8_usa",
"D_800B7930_eur": "D_800B7410_usa",
"D_800B7948_eur": "D_800B7428_usa",
"D_800B7960_eur": "D_800B7440_usa",
"D_800B7978_eur": "D_800B7458_usa",
"D_800B7990_eur": "D_800B7470_usa",
"D_800B79A8_eur": "D_800B7488_usa",
"D_800B79C0_eur": "D_800B74A0_usa",
"D_800B79D8_eur": "D_800B74B8_usa",
"D_800B60D0_fra": "D_800B7380_usa",
"D_800B60E8_fra": "D_800B7398_usa",
"D_800B6100_fra": "D_800B73B0_usa",
"D_800B6118_fra": "D_800B73C8_usa",
"D_800B6130_fra": "D_800B73E0_usa",
"D_800B6148_fra": "D_800B73F8_usa",
"D_800B6160_fra": "D_800B7410_usa",
"D_800B6178_fra": "D_800B7428_usa",
"D_800B6190_fra": "D_800B7440_usa",
"D_800B61A8_fra": "D_800B7458_usa",
"D_800B61C0_fra": "D_800B7470_usa",
"D_800B61D8_fra": "D_800B7488_usa",
"D_800B61F0_fra": "D_800B74A0_usa",
"D_800B6148_fra": "D_800B73F8_usa",
"D_800B6160_fra": "D_800B7410_usa",
"D_800B6178_fra": "D_800B7428_usa",
"D_800B6190_fra": "D_800B7440_usa",
"D_800B6100_fra": "D_800B73B0_usa",
"D_800B6148_fra": "D_800B73F8_usa",
"D_800B6160_fra": "D_800B7410_usa",
"D_800B6178_fra": "D_800B7428_usa",
"D_800B6190_fra": "D_800B7440_usa",
"D_800B61A8_fra": "D_800B7458_usa",
"D_800B61C0_fra": "D_800B7470_usa",
"D_800B61D8_fra": "D_800B7488_usa",
"D_800B61F0_fra": "D_800B74A0_usa",
"D_800B6208_fra": "D_800B74B8_usa",
"D_800AD300_ger": "D_800B7380_usa",
"D_800AD318_ger": "D_800B7398_usa",
"D_800AD330_ger": "D_800B73B0_usa",
"D_800AD348_ger": "D_800B73C8_usa",
"D_800AD360_ger": "D_800B73E0_usa",
"D_800AD378_ger": "D_800B73F8_usa",
"D_800AD390_ger": "D_800B7410_usa",
"D_800AD3A8_ger": "D_800B7428_usa",
"D_800AD3C0_ger": "D_800B7440_usa",
"D_800AD3D8_ger": "D_800B7458_usa",
"D_800AD3F0_ger": "D_800B7470_usa",
"D_800AD408_ger": "D_800B7488_usa",
"D_800AD420_ger": "D_800B74A0_usa",
"D_800AD378_ger": "D_800B73F8_usa",
"D_800AD390_ger": "D_800B7410_usa",
"D_800AD3A8_ger": "D_800B7428_usa",
"D_800AD3C0_ger": "D_800B7440_usa",
"D_800AD330_ger": "D_800B73B0_usa",
"D_800AD378_ger": "D_800B73F8_usa",
"D_800AD390_ger": "D_800B7410_usa",
"D_800AD3A8_ger": "D_800B7428_usa",
"D_800AD3C0_ger": "D_800B7440_usa",
"D_800AD3D8_ger": "D_800B7458_usa",
"D_800AD3F0_ger": "D_800B7470_usa",
"D_800AD408_ger": "D_800B7488_usa",
"D_800AD420_ger": "D_800B74A0_usa",
"D_800AD438_ger": "D_800B74B8_usa",

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

    for filename in (repo / "linker_scripts").rglob("*"):
        if filename.is_file():
            replace_single(filename)

    for filename in (repo / "relocs").rglob("*"):
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
