#ifndef ASSETS_VERTEX_CYLINDER_3D
#define ASSETS_VERTEX_CYLINDER_3D

#include "ultra64.h"

#include "unknown_defines.h"

#define VTX3D_VERTICES_PER_BLOCK (8)
#define GET_VTX3D_INDEX(row, col) ((row) * BLOCK_COLS_3D * VTX3D_VERTICES_PER_BLOCK + (col) * VTX3D_VERTICES_PER_BLOCK)

#endif
