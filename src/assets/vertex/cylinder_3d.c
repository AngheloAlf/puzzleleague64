#include "assets/vertex_cylinder_3d.h"

// clang-format off

#define XZ_SIGN(col) \
    (((col) >= BLOCK_COLS_3D / 2) ? -1 : 1)


#define X(col, ix) \
    ( \
        ((ix) == 0) ? X_0(col) : \
        ((ix) == 1) ? X_1(col) : \
        ((ix) == 2) ? X_1(col) : \
        ((ix) == 3) ? X_0(col) : \
        ((ix) == 4) ? X_4(col) : \
        ((ix) == 5) ? X_5(col) : \
        ((ix) == 6) ? X_5(col) : \
                      X_4(col)  \
    )

#define X_0_INNER(col) \
    ( \
        ((col) == 0) ? -80 : \
        ((col) == 1) ? -79 : \
        ((col) == 2) ? -70 : \
        ((col) == 3) ? -52 : \
        ((col) == 4) ? -27 : \
        ((col) == 5) ?   0 : \
        ((col) == 6) ?  27 : \
        ((col) == 7) ?  52 : \
                        70  \
    )

// x is symetrical, so we can have half the cases and multiply by -1 for the
// second half
#define X_0(col) \
    (XZ_SIGN(col) * X_0_INNER((col) % (BLOCK_COLS_3D / 2)))

#define X_1_INNER(col) \
    ( \
        ((col) == 0) ? -80 : \
        ((col) == 1) ? -70 : \
        ((col) == 2) ? -52 : \
        ((col) == 3) ? -27 : \
        ((col) == 4) ?   0 : \
        ((col) == 5) ?  27 : \
        ((col) == 6) ?  52 : \
        ((col) == 7) ?  70 : \
                        79  \
    )

#define X_1(col) \
    (XZ_SIGN(col) * X_1_INNER((col) % (BLOCK_COLS_3D / 2)))

#define X_4_INNER(col) \
    ( \
        ((col) == 0) ? -65 : \
        ((col) == 1) ? -65 : \
        ((col) == 2) ? -57 : \
        ((col) == 3) ? -42 : \
        ((col) == 4) ? -23 : \
        ((col) == 5) ?   0 : \
        ((col) == 6) ?  22 : \
        ((col) == 7) ?  42 : \
                        56  \
    )

#define X_4(col) \
    (XZ_SIGN(col) * X_4_INNER((col) % (BLOCK_COLS_3D / 2)))

#define X_5_INNER(col) \
    ( \
        ((col) == 0) ? -65 : \
        ((col) == 1) ? -56 : \
        ((col) == 2) ? -42 : \
        ((col) == 3) ? -22 : \
        ((col) == 4) ?   0 : \
        ((col) == 5) ?  23 : \
        ((col) == 6) ?  42 : \
        ((col) == 7) ?  57 : \
                        65  \
    )

#define X_5(col) \
    (XZ_SIGN(col) * X_5_INNER((col) % (BLOCK_COLS_3D / 2)))

#define Z_0_INNER(col) \
    ( \
        ((col) == 0) ? -14 : \
        ((col) == 1) ?  14 : \
        ((col) == 2) ?  40 : \
        ((col) == 3) ?  62 : \
        ((col) == 4) ?  76 : \
        ((col) == 5) ?  81 : \
        ((col) == 6) ?  76 : \
        ((col) == 7) ?  62 : \
        ((col) == 8) ?  40 : \
                        14  \
    )

// col 0 and 3 have the same values, same for col 1 and 2.
// col 1/2 kinda have the same values as col 0/3, but displaced by one entry
#define Z_0(col, ix) \
    (XZ_SIGN(col) * Z_0_INNER(( ((ix) == 0 || (ix) == 3) ? ((col) % (BLOCK_COLS_3D / 2)) : (((col) % (BLOCK_COLS_3D / 2)) + 1))))

#define Z_4_INNER(col) \
    ( \
        ((col) == 0) ? -12 : \
        ((col) == 1) ?  10 : \
        ((col) == 2) ?  32 : \
        ((col) == 3) ?  50 : \
        ((col) == 4) ?  61 : \
        ((col) == 5) ?  66 : \
        ((col) == 6) ?  62 : \
        ((col) == 7) ?  50 : \
                        33  \
    )

#define Z_4(col) \
    (XZ_SIGN(col) * Z_4_INNER((col) % (BLOCK_COLS_3D / 2)))

#define Z_5_INNER(col) \
    ( \
        ((col) == 0) ?  12 : \
        ((col) == 1) ?  33 : \
        ((col) == 2) ?  50 : \
        ((col) == 3) ?  62 : \
        ((col) == 4) ?  66 : \
        ((col) == 5) ?  61 : \
        ((col) == 6) ?  50 : \
        ((col) == 7) ?  32 : \
                        10  \
    )

#define Z_5(col) \
    (XZ_SIGN(col) * Z_5_INNER((col) % (BLOCK_COLS_3D / 2)))

#define Z(col, ix) \
    ( \
        ((ix) == 0) ? Z_0(col, ix) : \
        ((ix) == 1) ? Z_0(col, ix) : \
        ((ix) == 2) ? Z_0(col, ix) : \
        ((ix) == 3) ? Z_0(col, ix) : \
        ((ix) == 4) ? Z_4(col) : \
        ((ix) == 5) ? Z_5(col) : \
        ((ix) == 6) ? Z_5(col) : \
                      Z_4(col)  \
    )

#define Y_OFFSET(ix) \
    (\
        (((ix) == 0) || ((ix) == 1) || ((ix) == 4) || ((ix) == 6)) ?\
        0 : \
        (((ix) == 2 || (ix) == 3) ? 33 : 32) \
    )

#define Y(row, ix) \
    ((-208 + ((row) < BLOCK_LEN_ROWS ? (row) : -1) * 32) + Y_OFFSET(ix))

#define POS(row, col, ix) \
    { X(col, ix), Y(row, ix), Z(col, ix) }



// 1, 2, 5, 6
#define U(ix) \
    ((((ix) % 4) - 1 < 2U) * 2048)

// 0, 1, 4, 6
#define V(ix) \
    (((ix) == 0 || (ix) == 1 || (ix) == 4 || (ix) == 6) * 2048)

#define UV(ix) \
    { U(ix), V(ix) }


#define COLOR_RGB(ix) (((ix) < 4) ? 255 : 100)

#define COLOR(ix) \
    { COLOR_RGB(ix), COLOR_RGB(ix), COLOR_RGB(ix), 255 }


#define VTX_ENTRY(row, col, ix) \
    { { POS(row, col, ix), 0, UV(ix), COLOR(ix) } }

#define BLOCK_VTX(row, col) \
    { \
        VTX_ENTRY(row, col, 0), \
        VTX_ENTRY(row, col, 1), \
        VTX_ENTRY(row, col, 2), \
        VTX_ENTRY(row, col, 3), \
        VTX_ENTRY(row, col, 4), \
        VTX_ENTRY(row, col, 5), \
        VTX_ENTRY(row, col, 6), \
        VTX_ENTRY(row, col, 7), \
    }


#define ROW_BLOCK_VTX(row) \
    { \
        BLOCK_VTX(row, 0), \
        BLOCK_VTX(row, 1), \
        BLOCK_VTX(row, 2), \
        BLOCK_VTX(row, 3), \
        BLOCK_VTX(row, 4), \
        BLOCK_VTX(row, 5), \
        BLOCK_VTX(row, 6), \
        BLOCK_VTX(row, 7), \
        BLOCK_VTX(row, 8), \
        BLOCK_VTX(row, 9), \
        BLOCK_VTX(row, 10), \
        BLOCK_VTX(row, 11), \
        BLOCK_VTX(row, 12), \
        BLOCK_VTX(row, 13), \
        BLOCK_VTX(row, 14), \
        BLOCK_VTX(row, 15), \
        BLOCK_VTX(row, 16), \
        BLOCK_VTX(row, 17), \
    }

Vtx cylinder_3d[BLOCK_LEN_ROWS + 1][BLOCK_LEN_B][VTX3D_VERTICES_PER_BLOCK] = {
    ROW_BLOCK_VTX(0),
    ROW_BLOCK_VTX(1),
    ROW_BLOCK_VTX(2),
    ROW_BLOCK_VTX(3),
    ROW_BLOCK_VTX(4),
    ROW_BLOCK_VTX(5),
    ROW_BLOCK_VTX(6),
    ROW_BLOCK_VTX(7),
    ROW_BLOCK_VTX(8),
    ROW_BLOCK_VTX(9),
    ROW_BLOCK_VTX(10),
    ROW_BLOCK_VTX(11),
    ROW_BLOCK_VTX(12),
};
