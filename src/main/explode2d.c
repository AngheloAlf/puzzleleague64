/**
 * Original filename: explode2d.c
 */

#include "explode2d.h"

#include "ultra64.h"
#include "macros_defines.h"
#include "main_variables.h"

void Start2DExplosion(tetWell *well, s32 row, s32 col, s32 type) {
    s32 i;
    s32 count;
    s32 total;
    uObjSprite *rect;
    explode_t *explode;

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

INLINE void Update2DExplode1(explode_t *explode) {
    s8 *ptr;
    s32 position;

    if (explode->frame == 0x14) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(160 << 2);
        explode->rect.s.objY = -(160 << 2);
        return;
    }

    ptr = Explosion1[explode->frame];
    position = explode->pos;
    explode->rect.s.objX = (ptr[position * 3 + 1] + explode->x) << 2;
    explode->rect.s.objY = (ptr[position * 3 + 2] + explode->y) << 2;
    explode->rect.s.imageAdrs = Explosion2DTMEM[ptr[position * 3 + 0]];

    explode->frame++;
    if (explode->pos == 0) {
        gOverflow += 0x1E;
    }
}

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

INLINE void Update2DIconSplash(explode_t *explode) {
    s8 *ptr;

    if (explode->frame == 0x28) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(160 << 2);
        explode->rect.s.objY = -(160 << 2);
        return;
    }

    ptr = IconSplash[explode->frame];
    ptr += explode->pos * 2;
    explode->rect.s.objX = (ptr[0] + explode->x) << 2;
    explode->rect.s.objY = (ptr[1] + explode->y) << 2;

    explode->frame++;
    if (explode->pos == 0) {
        gOverflow += 0x46;
    }
}

void Update2DExplosion(tetWell *well) {
    explode_t *explode;
    s32 count;

    for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
        explode = &well->explosion[count];
        if (explode->type == -1) {
            continue;
        }

        if (explode->type == 0x19) {
            Update2DIconSplash(explode);
        } else if (explode->type < 0x1F) {
            Update2DExplode1(explode);
        } else {
            Update2DExplode2(explode);
        }
    }
}
