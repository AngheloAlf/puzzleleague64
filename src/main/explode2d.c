/**
 * Original filename: explode2d.c
 */

#include "explode2d.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

void Start2DExplosion(tetWell *well, s32 row, s32 col, s32 type) {
    s32 i;
    s32 count;
    s32 total;
    uObjSprite *rect;
    explode_t *explode;

    if (row >= BLOCK_LEN_A) {
        return;
    }

    if (type < 0x20) {
        total = 4;
    } else if (type == 0x20) {
        total = 6;
    } else {
        total = 8;
    }

    rect = &well->unk_3830[row][col];

    for (i = 0; i < total; i++) {
        for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
            if (well->explosion[count].type == -1) {
                explode = &well->explosion[count];

                explode->type = type;
                explode->pos = i;
                explode->frame = 0;
                explode->x = (rect->s.objX >> 2) + 1;
                explode->y = (rect->s.objY >> 2);

                if (type == 0x1E) {
                    explode->rect.s.imageW = 8 << 5;
                    explode->rect.s.imageH = 8 << 5;
                    switch (i) {
                        case 0:
                            explode->rect.s.imageFlags = 0;
                            break;

                        case 1:
                            explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPS;
                            break;

                        case 2:
                            explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPS | G_OBJ_FLAG_FLIPT;
                            break;

                        case 3:
                            explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPT;
                            break;
                    }
                }

                break;
            }
        }
    }
}

void Start2DExBlosion(tetWell *well, s32 row, s32 col, s32 type UNUSED) {
    s32 count;
    s32 i;
    explode_t *explode;

    for (i = 0; i < 4; i++) {
        for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
            if (well->explosion[count].type == -1) {
                explode = &well->explosion[count];

                explode->type = 0x17;
                explode->pos = i;
                explode->frame = 0;
                explode->x = row;
                explode->y = col;
                explode->rect.s.imageW = 8 << 5;
                explode->rect.s.imageH = 8 << 5;

                switch (i) {
                    case 0:
                        explode->rect.s.imageFlags = 0;
                        break;

                    case 1:
                        explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPS;
                        break;

                    case 2:
                        explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPS | G_OBJ_FLAG_FLIPT;
                        break;

                    case 3:
                        explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPT;
                        break;
                }
                break;
            }
        }
    }
}

void Start2DIconSplash(tetWell *well, s32 x, s32 y) {
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
                explode->x = x;
                explode->y = y;
                explode->rect.s.imageW = 8 << 5;
                explode->rect.s.imageH = 8 << 5;
                explode->rect.s.imageFlags = 0;
                explode->rect.s.imageAdrs = Explosion2DTMEM[1];
                break;
            }
        }
    }
}

#if VERSION_USA
#ifdef NON_MATCHING
// INLINE
void func_80073138_usa(explode_t *explode) {
    s8 *temp_v1_2;

    if (explode->frame == 0x14) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(160 << 2);
        explode->rect.s.objY = -(160 << 2);
        return;
    }

    temp_v1_2 = Explosion1[explode->frame];
    temp_v1_2 += explode->pos * 3;
    explode->rect.s.objX = (temp_v1_2[1] + explode->x) << 2;
    explode->rect.s.objY = (temp_v1_2[2] + explode->y) << 2;
    explode->rect.s.imageAdrs = Explosion2DTMEM[temp_v1_2[0]];

    explode->frame++;
    if (explode->pos == 0) {
        gOverflow += 0x1E;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", func_80073138_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", func_80073138_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", func_80073138_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", func_80073138_usa);
#endif

void Update2DExplode2(explode_t *explode) {
    s8 *ptr;
    s32 position;
    s32 first;
    s32 max;

    switch (explode->type) {
        case 0x1F:
            max = 0x14;
            ptr = Explosion2[explode->frame];
            break;

        case 0x20:
            max = 0x18;
            ptr = Explosion3[explode->frame];
            break;

        case 0x21:
            max = 0x18;
            ptr = Explosion4[explode->frame];
            break;
    }

    if (explode->frame == max) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(160 << 2);
        explode->rect.s.objY = -(160 << 2);
        return;
    }

    position = explode->pos * 4;
    first = ptr[position + 0];
    if (first >= 0) {
        if (first == 0) {
            explode->rect.s.imageW = 16 << 5;
            explode->rect.s.imageH = 16 << 5;
        } else {
            explode->rect.s.imageW = 8 << 5;
            explode->rect.s.imageH = 8 << 5;
        }

        explode->rect.s.objX = (ptr[position + 1] + explode->x) << 2;
        explode->rect.s.objY = (ptr[position + 2] + explode->y) << 2;
        explode->rect.s.imageAdrs = Explosion2DTMEM[first];

        switch (ptr[position + 3]) {
            case 0x1:
                explode->rect.s.imageFlags = 0;
                break;
            case 0x2:
                explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPS;
                break;
            case 0x3:
                explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPS | G_OBJ_FLAG_FLIPT;
                break;
            case 0x4:
                explode->rect.s.imageFlags = G_OBJ_FLAG_FLIPT;
                break;
        }
    } else {
        explode->rect.s.objX = -0x280;
        explode->rect.s.objY = -0x280;
    }

    explode->frame++;
    if (explode->pos == 0) {
        gOverflow += 0x1E;
    }
}

INLINE void func_800733D0_usa(explode_t *explode) {
    s8 *temp_a0;

    if (explode->frame == 0x28) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(160 << 2);
        explode->rect.s.objY = -(160 << 2);
        return;
    }

    temp_a0 = IconSplash[explode->frame];
    temp_a0 += explode->pos * 2;
    explode->rect.s.objX = (temp_a0[0] + explode->x) << 2;
    explode->rect.s.objY = (temp_a0[1] + explode->y) << 2;

    explode->frame++;
    if (explode->pos == 0) {
        gOverflow += 0x46;
    }
}

#if VERSION_USA
#ifdef NON_MATCHING
void Update2DExplosion(tetWell *well) {
    s32 var_s2;
    s8 *temp_a0;
    explode_t *temp_a1;
    s8 *temp_v1_4;

    for (var_s2 = 0; var_s2 < TETWELL_EXPLOSION_LEN; var_s2++) {
        temp_a1 = &well->explosion[var_s2];
        if (temp_a1->type == -1) {
            continue;
        }

        if (temp_a1->type == 0x19) {
            if (temp_a1->frame == 0x28) {
                temp_a1->type = -1;
                temp_a1->frame = -1;
                temp_a1->rect.s.objX = -(160 << 2);
                temp_a1->rect.s.objY = -(160 << 2);
            } else {
                temp_a0 = &IconSplash[temp_a1->frame][temp_a1->pos * 2];
                temp_a1->rect.s.objX = (temp_a0[0] + temp_a1->x) << 2;
                temp_a1->rect.s.objY = (temp_a0[1] + temp_a1->y) << 2;
                temp_a1->frame++;
                if (temp_a1->pos == 0) {
                    gOverflow += 0x46;
                }
            }
        } else if (temp_a1->type < 0x1F) {
            if (temp_a1->frame == 0x14) {
                temp_a1->type = -1;
                temp_a1->frame = -1;
                temp_a1->rect.s.objX = -(160 << 2);
                temp_a1->rect.s.objY = -(160 << 2);
            } else {
                temp_v1_4 = &Explosion1[temp_a1->frame][temp_a1->pos * 3];
                temp_a1->rect.s.objX = (temp_v1_4[1] + temp_a1->x) << 2;
                temp_a1->rect.s.objY = (temp_v1_4[2] + temp_a1->y) << 2;
                temp_a1->rect.s.imageAdrs = Explosion2DTMEM[temp_v1_4[0]];
                temp_a1->frame++;
                if (temp_a1->pos == 0) {
                    gOverflow += 0x1E;
                }
            }
        } else {
            Update2DExplode2(temp_a1);
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", Update2DExplosion);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", Update2DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", Update2DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", Update2DExplosion);
#endif
