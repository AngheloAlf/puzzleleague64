/**
 * Original filename: explode3d.c
 */

#include "explode3d.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

void Start3DExplosion(tetWell *well, s32 num, s32 row, s32 col, s32 type) {
    explode_t *explode;
    s32 count;
    s32 i;
    s32 total;

    if (row >= BLOCK_LEN_ROWS) {
        return;
    }

    if (type < 0x20) {
        total = 4;
    } else if (type == 0x20) {
        total = 6;
    } else {
        total = 8;
    }

    for (i = 0; i < total; i++) {
        for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
            if (well->explosion[count].type == -1) {
                explode = &well->explosion[count];

                explode->frame = -1;
                explode->type = type;
                explode->pos = i;
                explode->rect.s.imageFmt = num;
                explode->rect.s.scaleW = col;
                explode->rect.s.scaleH = row;
                Match3DPosition(num, row, col, &explode->x, &explode->y);

                if (type == 0x1E) {
                    explode->rect.s.imageSiz = 8;
                    switch (i) {
                        case 0:
                            explode->rect.s.paddingX = 1;
                            explode->rect.s.paddingY = 1;
                            break;

                        case 1:
                            explode->rect.s.paddingX = 0xFFFF;
                            explode->rect.s.paddingY = 1;
                            break;

                        case 2:
                            explode->rect.s.paddingX = 0xFFFF;
                            explode->rect.s.paddingY = 0xFFFF;
                            break;

                        case 3:
                            explode->rect.s.paddingX = 1;
                            explode->rect.s.paddingY = 0xFFFF;
                            break;
                    }
                }
                break;
            }
        }
    }
}

void Start3DExBlosion(tetWell *well, s32 num, s32 x, s32 y) {
    explode_t *explode;
    s32 count;
    s32 i;

    for (i = 0; i < 4; i++) {
        for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
            if (well->explosion[count].type == -1) {
                explode = &well->explosion[count];

                explode->type = 0x17;
                explode->pos = i;
                explode->frame = 0;
                explode->rect.s.scaleW = 1;
                explode->rect.s.imageFmt = num;
                explode->x = x;
                explode->y = y;
                explode->rect.s.imageSiz = 8;

                switch (i) {
                    case 0:
                        explode->rect.s.paddingX = 1;
                        explode->rect.s.paddingY = 1;
                        break;

                    case 1:
                        explode->rect.s.paddingX = 0xFFFF;
                        explode->rect.s.paddingY = 1;
                        break;

                    case 2:
                        explode->rect.s.paddingX = 0xFFFF;
                        explode->rect.s.paddingY = 0xFFFF;
                        break;

                    case 3:
                        explode->rect.s.paddingX = 1;
                        explode->rect.s.paddingY = 0xFFFF;
                        break;
                }
                break;
            }
        }
    }
}

void Start3DIconSplash(tetWell *well, s32 num, s32 row, s32 col) {
    explode_t *explode;
    s32 count;
    s32 i;

    for (i = 0; i < 6; i++) {
        for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
            if (well->explosion[count].type == -1) {
                explode = &well->explosion[count];

                explode->type = 0x19;
                explode->pos = i;
                explode->frame = 0;
                explode->rect.s.imageFmt = num;
                explode->rect.s.scaleW = col;
                explode->rect.s.scaleH = row;
                Match3DPosition(num, row, col, &explode->x, &explode->y);
                explode->rect.s.imageSiz = 8;
                explode->rect.s.paddingX = 1;
                explode->rect.s.paddingY = 1;
                explode->rect.s.imagePal = 1;
                explode->y -= 4;
                break;
            }
        }
    }
}

void func_8006A9EC_usa(explode_t *explode, s32 arg1);
#if VERSION_USA
#ifdef NON_MATCHING
void func_8006A9EC_usa(explode_t *explode, s32 arg1) {
    s32 temp;
    s8 *temp_a0;

    temp_a0 = Explosion1[explode->frame];
    temp_a0 += explode->pos * 3;
    temp = temp_a0[0];

    if (temp == 8) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(40 << 2);
        explode->rect.s.objY = -(40 << 2);
        return;
    }

    explode->rect.s.objX = temp_a0[1] + explode->x;
    explode->rect.s.objY = temp_a0[2] + explode->y - arg1;
    explode->rect.s.imagePal = temp;
    explode->frame++;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/explode3d", func_8006A9EC_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode3d", func_8006ACBC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode3d", func_800693FC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode3d", func_800695AC_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode3d", func_8006AA88_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode3d", func_8006AD58_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode3d", func_80069498_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode3d", func_80069648_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode3d", func_8006AC3C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode3d", func_8006AF0C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode3d", func_8006964C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode3d", func_800697FC_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode3d", Update3DExplosion);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode3d", Update3DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode3d", Update3DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode3d", Update3DExplosion);
#endif
