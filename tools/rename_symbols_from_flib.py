syms = {

}
found = set()


a = open("asdf.txt")
for line in a:
    if ", " not in line:
        continue
    name, addr, *_ = line.strip().split(", ")
    addr = int(addr, 16)
    syms[addr] = name
a.close()

FILEPATH = "linker_scripts/ger/symbol_addrs_main.txt"

b = open(FILEPATH)
new_data = []
for line in b:
    if ";" in line and " = " in line:
        old_name, addr = line.split(";")[0].split(" = ")
        addr = int(addr, 16)
        if addr in syms:
            new_name = syms[addr]
            line = line.replace(old_name, new_name)
            found.add(addr)

    new_data.append(line)
b.close()

b = open(FILEPATH, "w")
for line in new_data:
    b.write(line)
b.close()

print({f"0x{x:08X}" : syms[x] for x in set(syms.keys()) - found})
