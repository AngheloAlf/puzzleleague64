import argparse
from pathlib import Path

syms: dict[int, tuple[str, int|None]] = {

}
names: set[str] = set()
found: set[int] = set()
duped_addrs: set[int] = set()
duped_names: set[str] = set()
duped_syms: set[tuple[int, str]] = set()


parser = argparse.ArgumentParser()
parser.add_argument("filepath")

args = parser.parse_args()

FILEPATH = Path(args.filepath)

def parse_flib_symbols(path: Path):
    a = path.open()
    for line in a:
        if ", " not in line:
            continue
        name, addr, extra, *_ = line.strip().split(", ")
        if name == "":
            continue
        size = None
        temp = int(extra.split(" ")[0], 16)
        if temp != 0:
            size = temp

        addr = int(addr, 16)

        if addr >= 0x90000000:
            continue

        if addr in syms:
            duped_addrs.add(addr)
            duped_names.add(name)
            duped_syms.add((addr, name))
            del syms[addr]
            continue
        if name in names:
            duped_addrs.add(addr)
            duped_names.add(name)
            duped_syms.add((addr, name))
            duped_key = None
            for key, value in syms.items():
                if value == name:
                    duped_key = key
                    break
            if duped_key is not None:
                del syms[duped_key]
            continue
        if addr in duped_addrs:
            duped_syms.add((addr, name))
            continue
        if name in duped_names:
            duped_syms.add((addr, name))
            continue

        syms[addr] = (name, size)
        names.add(name)
    a.close()

parse_flib_symbols(Path("asdf.txt"))

b = FILEPATH.open()
new_data = []
for line in b:
    if ";" in line and " = " in line:
        old_name, addr = line.split(";")[0].split(" = ")
        addr = int(addr, 16)
        if addr in syms:
            new_name, new_size = syms[addr]
            line = line.replace(old_name, new_name)
            if new_size is not None:
                line = line.replace("\n", f" size:0x{new_size:X}\n")
            found.add(addr)

    new_data.append(line)
b.close()

b = FILEPATH.open("w")
for line in new_data:
    b.write(line)
b.close()

print("symbols not found:")
for key, value in {x: syms[x] for x in set(syms.keys()) - found}.items():
    print("    ", f"0x{key:08X}", value)
print()

print("duplicated syms")
for key, value in duped_syms:
    print("    ", f"0x{key:08X}", value)
