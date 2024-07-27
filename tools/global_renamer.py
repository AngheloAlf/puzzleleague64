#!/usr/bin/env python3

# Adapted from https://github.com/zeldaret/mm/blob/main/tools/namefixer.py

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
"func_80029818_eur": "func_800296B0_usa",
"func_80029788_fra": "func_800296B0_usa",
"func_80029810_ger": "func_800296B0_usa",

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
