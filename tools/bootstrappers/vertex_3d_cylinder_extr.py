import struct
import sys


def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def load_vtx_file(path):
    with open(path, "rb") as f:
        data = f.read()
    vtxs = struct.iter_unpack(">hhhHhhBBBB", data)

    """
    for vtx in vtxs:
        x, y, z, flg, u, v, r, g, b, a = vtx
        print(f"VTX({x}, {y}, {z}, {flg}, {u}, {v}, {r}, {g}, {b}, {a}),")
    """

    y_list = []
    current_y = None

    x_list = []
    prev_x_list = None
    z_list = []
    prev_z_list = None

    for row in range(12 +1):
        for col in range(18):
            row_x_list = []
            row_z_list = []
            print(f"    // {row} {col}")
            for ix in range(8):

                def ensure(condition: bool):
                    if not condition:
                        raise RuntimeError(f"{row} {col} {ix}")

                vtx = next(vtxs)
                x, y, z, flg, u, v, r, g, b, a = vtx

                print(f"    VTX({x}, {y}, {z}, {flg}, {u}, {v}, {r}, {g}, {b}, {a}),")

                ensure(flg == 0)
                ensure(a == 255)
                if ix < 4:
                    ensure(r == 255)
                    ensure(g == 255)
                    ensure(b == 255)
                else:
                    ensure(r == 100)
                    ensure(g == 100)
                    ensure(b == 100)

                if ix in (1, 2, 5, 6):
                    ensure(u == 2048)
                else:
                    ensure(u == 0)

                if ix in (0, 1, 4, 6):
                    ensure(v == 2048)
                else:
                    ensure(v == 0)

                if ix == 0:
                    if col == 0:
                        y_list.append(y)
                        current_y = y
                    else:
                        ensure(y == current_y)

                row_x_list.append(x)
                row_z_list.append(z)

            print()

            x_list.append(row_x_list)
            z_list.append(row_z_list)

        if prev_x_list is not None:
            ensure(prev_x_list == x_list)
        prev_x_list = x_list
        x_list = []

        if prev_z_list is not None:
            ensure(prev_z_list == z_list)
        prev_z_list = z_list
        z_list = []

    eprint(f"{y_list=}")
    """
    for i in range(len(y_list)-1):
        a = y_list[i]
        b = y_list[i+1]
        eprint(b-a)
    """

    eprint("prev_x_list")
    print_list_of_lists(prev_x_list)
    eprint("prev_z_list")
    print_list_of_lists(prev_z_list)


def print_list_of_lists(l):
    eprint("[")
    for arr in l:
        eprint("    [", end="")
        for x in arr:
            eprint(f"{x: 3}, ", end="")
        eprint("],")

    eprint("]")


print("""\
#include "assets/vertex_cylinder_3d.h"

#define VTX(x, y, z, flg, u, v, r, g, b, a) \\
    { { { x, y, z }, flg, { u, v }, { r, g, b, a } } }

Vtx cylinder_3d[(BLOCK_LEN_ROWS + 1) * BLOCK_LEN_B * VTX3D_VERTICES_PER_BLOCK] = {\
""")

load_vtx_file("bin/usa/assets_bins/vertex/segment_vertex.databin.bin")

print("};")
