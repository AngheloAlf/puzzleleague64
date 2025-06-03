/**
 * Original filename: explode3d.c
 */

#include "explode3d.h"

#include "ultra64.h"
#include "macros_defines.h"
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

INLINE void Update3DExplode1(explode_t *explode, s32 distance) {
    s8 *ptr;
    s32 position;
    s32 first;

    ptr = Explosion1[explode->frame];
    position = explode->pos * 3;
    first = ptr[position + 0];

    if (first == 8) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(40 << 2);
        explode->rect.s.objY = -(40 << 2);
        return;
    }

    explode->rect.s.objX = ptr[position + 1] + explode->x;
    explode->rect.s.objY = ptr[position + 2] + explode->y - distance;
    explode->rect.s.imagePal = first;
    explode->frame++;
}

void Update3DExplode2(explode_t *explode, s32 distance) {
    s8 *ptr;
    s32 position;
    s32 first;
    s32 max;
    uObjSprite_t *s;

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

    position = explode->pos * 4;
    first = ptr[position + 0];
    s = &explode->rect.s;

    if ((first == 8) || (explode->frame == max)) {
        explode->type = -1;
        explode->frame = -1;
        s->objX = -(40 << 2);
        s->objY = -(40 << 2);
        return;
    }

    if (first < 0) {
        s->objX = -(40 << 2);
        s->objY = -(40 << 2);
    } else {
        if (first == 0) {
            s->imageSiz = 16;
        } else {
            s->imageSiz = 8;
        }

        s->objX = explode->x + ptr[position + 1];
        s->objY = explode->y + ptr[position + 2] - distance;
        s->imagePal = first;

        switch (ptr[position + 3]) {
            case 1:
                s->paddingX = 1;
                s->paddingY = 1;
                break;
            case 2:
                s->paddingX = 0xFFFF;
                s->paddingY = 1;
                break;
            case 3:
                s->paddingX = 0xFFFF;
                s->paddingY = 0xFFFF;
                break;
            case 4:
                s->paddingX = 1;
                s->paddingY = 0xFFFF;
                break;
        }
    }

    explode->frame++;
}

INLINE void func_8006AC3C_usa(explode_t *explode, s32 distance) {
    s8 *ptr = IconSplash[explode->frame];
    s32 position;

    if (explode->frame == 0x19) {
        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.objX = -(40 << 2);
        explode->rect.s.objY = -(40 << 2);
        return;
    }

    position = explode->pos * 2;
    explode->rect.s.objX = ptr[position + 0] + explode->x;
    explode->rect.s.objY = ptr[position + 1] + explode->y - distance;
    explode->frame++;
}

void Update3DExplosion(tetWell *well) {
    s32 distance = well->unk_43F8 / 2;
    explode_t *explode;
    s32 count;
    s32 temp;

    for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
        explode = &well->explosion[count];

        if (explode->type == -1) {
            continue;
        }

        if (explode->frame < 0) {
            explode->frame++;
        } else if (explode->type == 0x17) {
            Update3DExplode1(explode, 0);
        } else {
            Match3DPosition(explode->rect.s.imageFmt, 0, explode->rect.s.scaleW, &explode->x, &temp);
            if (explode->type == 0x19) {
                explode->x += 5;

                func_8006AC3C_usa(explode, distance);
            } else if (explode->type == 0x1E) {
                Update3DExplode1(explode, distance);
            } else {
                Update3DExplode2(explode, distance);
            }
        }
    }
}
