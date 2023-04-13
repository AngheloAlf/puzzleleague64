offsets = [
0x01BF29A0,
0x01BF5AB0,
]

pairs = set()

i = 0
while i < len(offsets):
    pairs.add(tuple(offsets[i:i+2]))

    i += 2

pairs = sorted(pairs)

# print(pairs)

segment_names_1 = [
"segment_1D358C0",
]

def print_segment(i, offset):
    # print(f'"segment_{offset:06X}",')
    # return
    print(f"""
  - name: {segment_names_1[i]}
    type: bin
    start: 0x{offset:06X}""")


for i, (x, y) in enumerate(pairs):
    if i + 1 == len(pairs):
        break

    assert y == pairs[i+1][0]

    print_segment(i, x)

print_segment(len(pairs)-1, pairs[-1][0])

print(f"""
  - type: bin
    start: 0x{pairs[-1][1]:06X}
""")
