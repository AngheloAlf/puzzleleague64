offsets = [
0x01AD0EA0,
0x01AD8720,
0x01C5EFB0,
0x01C60660,
0x01AD8720,
0x01FCE1A0,
0x01FCE670,
0x01FCF820,
0x01FCF900,
0x01FCE670,
0x01C60AD0,
0x01C63BE0,
0x00000000,
0x00000000,
0x01C63BE0,
0x017C2A80,
0x017CA780,
0x00000000,
0x00000000,
0x017CA780,
0x01D3D390,
0x01D3E1A0,
0x01D66C70,
0x01D66F00,
0x01D3E1A0,
0x01D66F00,
0x01D67A70,
0x01D8B4C0,
0x01D8B6C0,
0x01D67A70,
0x01D8B6C0,
0x01D8C620,
0x01DB4980,
0x01DB4C20,
0x01D8C620,
0x01DB4C20,
0x01DB5790,
0x01DD4750,
0x01DD4950,
0x01DB5790,
0x01DD4950,
0x01DD54C0,
0x01DF38F0,
0x01DF3AF0,
0x01DD54C0,
0x01DF3AF0,
0x01DF4660,
0x01E16C10,
0x01E16E10,
0x01DF4660,
0x01E16E10,
0x01E17980,
0x01E36C00,
0x01E36E00,
0x01E17980,
0x01E36E00,
0x01E37970,
0x01E5D070,
0x01E5D270,
0x01E37970,
0x01E5D270,
0x01E5DDE0,
0x01E7B650,
0x01E7B850,
0x01E5DDE0,
0x01E7B850,
0x01E7C710,
0x01EA1000,
0x01EA12B0,
0x01E7C710,
0x01EA12B0,
0x01EA2170,
0x01ED7210,
0x01ED74C0,
0x01EA2170,
0x01ED74C0,
0x01ED8030,
0x01F03840,
0x01F03A40,
0x01ED8030,
0x01F03A40,
0x01F049A0,
0x01F2C5C0,
0x01F2C860,
0x01F049A0,
0x01F2C860,
0x01F2D920,
0x01F64640,
0x01F64920,
0x01F2D920,
0x01F64920,
0x01F65490,
0x01F898F0,
0x01F89AF0,
0x01F65490,
0x01F89AF0,
0x01F8A660,
0x01FA9EB0,
0x01FAA0B0,
0x01F8A660,
0x01FAA0B0,
0x01FAAC20,
0x01FCDF80,
0x01FCE1A0,
0x01FAAC20,
0x01D37FF0,
0x01D38180,
0x01D3D2C0,
0x01D3D320,
0x01D38180,
0x01D3D390,
0x01D3E1A0,
0x01D66C70,
0x01D66F00,
0x01D3E1A0,
0x01D66F00,
0x01D67A70,
0x01D8B4C0,
0x01D8B6C0,
0x01D67A70,
0x01D8B6C0,
0x01D8C620,
0x01DB4980,
0x01DB4C20,
0x01D8C620,
0x01DB4C20,
0x01DB5790,
0x01DD4750,
0x01DD4950,
0x01DB5790,
0x01DD4950,
0x01DD54C0,
0x01DF38F0,
0x01DF3AF0,
0x01DD54C0,
0x01DF3AF0,
0x01DF4660,
0x01E16C10,
0x01E16E10,
0x01DF4660,
0x01E16E10,
0x01E17980,
0x01E36C00,
0x01E36E00,
0x01E17980,
0x01E36E00,
0x01E37970,
0x01E5D070,
0x01E5D270,
0x01E37970,
0x01E5D270,
0x01E5DDE0,
0x01E7B650,
0x01E7B850,
0x01E5DDE0,
0x01E7B850,
0x01E7C710,
0x01EA1000,
0x01EA12B0,
0x01E7C710,
0x01EA12B0,
0x01EA2170,
0x01ED7210,
0x01ED74C0,
0x01EA2170,
0x01ED74C0,
0x01ED8030,
0x01F03840,
0x01F03A40,
0x01ED8030,
0x01F03A40,
0x01F049A0,
0x01F2C5C0,
0x01F2C860,
0x01F049A0,
0x01F2C860,
0x01F2D920,
0x01F64640,
0x01F64920,
0x01F2D920,
0x01F64920,
0x01F65490,
0x01F898F0,
0x01F89AF0,
0x01F65490,
0x01F89AF0,
0x01F8A660,
0x01FA9EB0,
0x01FAA0B0,
0x01F8A660,
0x01FAA0B0,
0x01FAAC20,
0x01FCDF80,
0x01FCE1A0,
0x01FAAC20,
]

import dataclasses

@dataclasses.dataclass
class Pair:
    x: int
    y: int|None = None


off_dict: dict[int, Pair] = dict()

def add_to_dict(start, end):

    if start in off_dict:
        assert off_dict[start].y == end
    else:
        off_dict[start] = Pair(start, end)

i = 0
while i < len(offsets):
    a, b, c, d, e = offsets[i:i+5]

    # assert a not in off_dict, f"{a:X}"
    # assert c not in off_dict, f"{c:X}"
    # assert e not in off_dict, f"{e:X}"

    add_to_dict(a, b)
    add_to_dict(c, d)
    add_to_dict(e, None)

    if 0 in off_dict:
        del off_dict[0]

    i += 5

off_list = list(off_dict.values())
off_list.sort(key=lambda x: x.x)

segment_names = [

"segment_17C2A80",
"segment_17CA780",
"segment_1AD0EA0",
"segment_1AD8720",
"segment_1C5EFB0",
"segment_1C60AD0",
"segment_1C63BE0",
"segment_1D37FF0",
"segment_1D38180",
"segment_1D3D2C0",
"segment_1D3D390",
"segment_1D3E1A0",
"segment_1D66C70",
"segment_1D66F00",
"segment_1D67A70",
"segment_1D8B4C0",
"segment_1D8B6C0",
"segment_1D8C620",
"segment_1DB4980",
"segment_1DB4C20",
"segment_1DB5790",
"segment_1DD4750",
"segment_1DD4950",
"segment_1DD54C0",
"segment_1DF38F0",
"segment_1DF3AF0",
"segment_1DF4660",
"segment_1E16C10",
"segment_1E16E10",
"segment_1E17980",
"segment_1E36C00",
"segment_1E36E00",
"segment_1E37970",
"segment_1E5D070",
"segment_1E5D270",
"segment_1E5DDE0",
"segment_1E7B650",
"segment_1E7B850",
"segment_1E7C710",
"segment_1EA1000",
"segment_1EA12B0",
"segment_1EA2170",
"segment_1ED7210",
"segment_1ED74C0",
"segment_1ED8030",
"segment_1F03840",
"segment_1F03A40",
"segment_1F049A0",
"segment_1F2C5C0",
"segment_1F2C860",
"segment_1F2D920",
"segment_1F64640",
"segment_1F64920",
"segment_1F65490",
"segment_1F898F0",
"segment_1F89AF0",
"segment_1F8A660",
"segment_1FA9EB0",
"segment_1FAA0B0",
"segment_1FAAC20",
"segment_1FCDF80",
"segment_1FCE1A0",
"segment_1FCE670",
"segment_1FCF820",

]

def print_segment(i, offset):
    # print(f'"segment_{offset:06X}",')
    # return
    print(f"""
  - name: {segment_names[i]}
    type: bin
    start: 0x{offset:06X}""")


for i, entry in enumerate(off_list):
    if i + 1 == len(off_list):
        break

    # assert y == pairs[i+1][0], f"{y:X} {pairs[i+1][0]:X}"

    print_segment(i, entry.x)

    if entry.y is None:
        # continue
        print("  # unknown end for the above one")
    elif entry.y != off_list[i+1].x:
        # continue
        print(f"""
  - type: bin
    start: 0x{entry.y:06X}""")


print_segment(len(off_list)-1, off_list[-1].x)

print(f"""
  - type: bin
    start: 0x{off_list[-1].y:06X}
""")
