/**
 * Original filename: attack2d.c
 */

#include "attack2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "animation.h"
#include "cursor.h"
#include "init2d.h"
#include "sfxlimit.h"
#include "tetwell.h"

void Init2DAttackPosition(attack_t *attack, ENUM_TYPE(AttackType, s32) type, s32 num) {
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;

    attack->state = ATTACKSTATE_1;
    attack->disappear = -1;
    attack->type = type;
    attack->unk_20 = 0;
    attack->delay = 40;
    attack->level = 1;

    attack->rect.s.imageW = 16 << 5;
    attack->rect.s.scaleW = 32 << 5;
    attack->rect.s.imageStride = 8;
    attack->rect.s.imageFmt = G_IM_FMT_CI;
    attack->rect.s.imageSiz = G_IM_SIZ_8b;
    attack->rect.s.imageAdrs = 0;

    switch (type) {
        case ATTACKTYPE_1:
            temp_v0 = st_AttackPosition[num];
            st_AttackPosition[num] &= 0xFC;
            if ((temp_v0 & 3) == 1) {
                attack->start = 0;
                attack->unk_1C = 3;
                st_AttackPosition[num] |= 2;
            } else {
                attack->start = 3;
                attack->unk_1C = 6;
                st_AttackPosition[num] |= 1;
            }
            break;

        case ATTACKTYPE_2:
            temp_v0_2 = st_AttackPosition[num] & 0x1C;
            st_AttackPosition[num] &= 0xE3;
            if (temp_v0_2 == 4) {
                attack->start = 0;
                attack->unk_1C = 4;
                st_AttackPosition[num] |= 8;
            } else if (temp_v0_2 == 8) {
                attack->start = 1;
                attack->unk_1C = 5;
                st_AttackPosition[num] |= 0x10;
            } else {
                attack->start = 2;
                attack->unk_1C = 6;
                st_AttackPosition[num] |= 4;
            }
            break;

        case ATTACKTYPE_3:
            temp_v0_3 = st_AttackPosition[num];
            st_AttackPosition[num] &= 0x9F;
            if ((temp_v0_3 & 0x60) == 0x20) {
                attack->start = 0;
                attack->unk_1C = 5;
                st_AttackPosition[num] |= 0x40;
            } else {
                attack->start = 1;
                attack->unk_1C = 6;
                st_AttackPosition[num] |= 0x20;
            }
            break;

        default:
            attack->unk_1C = 6;
            attack->start = 0;
            // TODO: fix weird condition
            if (((type == ATTACKTYPE_4) || (type == ATTACKTYPE_9)) == 0) {
                attack->level = type - ATTACKTYPE_9;
            }
            break;
    }
}

INLINE void Init2DAttackFace(attack_t *attack) {
    attack->rect.s.imageW = 16 << 5;
    attack->rect.s.scaleW = 911;
    attack->rect.s.imageStride = 8;
    attack->rect.s.imageFmt = G_IM_FMT_CI;
    attack->rect.s.imageSiz = G_IM_SIZ_8b;
    attack->rect.s.imageAdrs = 0;
}

void Update2DAttackFace(tetWell *well, attack_t *attack) {
    s32 y;
    s32 x;
    s32 var_v0;
    s32 temp;

    x = well->block_rect[0][0].s.objX >> 0x2;

    y = well->block_rect[attack->currRow][0].s.objY >> 0x2;
    if (attack->type < ATTACKTYPE_11) {
        attack->rect.s.objY = y << 2;
    } else {
        attack->rect.s.objX = (x + 0x2D) << 2;
    }

    switch (attack->type) {
        case ATTACKTYPE_1:
            temp = attack->start;
            temp++;
            x = well->block_rect[0][temp].s.objX >> 2;
            attack->rect.s.objX = x << 2;
            break;

        case ATTACKTYPE_2:
            temp = attack->start;
            temp++;
            x = well->block_rect[0][temp].s.objX >> 2;
            attack->rect.s.objX = (x + 9) << 2;
            break;

        case ATTACKTYPE_3:
            temp = attack->start;
            temp += 2;
            x = well->block_rect[0][temp].s.objX >> 2;
            attack->rect.s.objX = x << 2;
            break;

        case ATTACKTYPE_4:
        case ATTACKTYPE_10:
            var_v0 = (x + 0x2D);
            attack->rect.s.objX = var_v0 << 2;
            break;

        default:
            attack->rect.s.objY = (y - ((attack->type - ATTACKTYPE_10) * 8)) << 2;
            if (attack->unk_20 == 0x20) {
                x = attack->unk_10 % 10;
                if (x == 0) {
                    if (attack->rect.s.imageAdrs == 4) {
                        attack->rect.s.imageAdrs = 6;
                    } else {
                        attack->rect.s.imageAdrs = 4;
                    }
                }
            }
            break;
    }
}

void Update2DAttack(tetWell *well, cursor_t *cursor, s32 num) {
    s32 count;
    s32 pos;
    s32 type;
    s32 lev;
    s32 row;
    s32 col;

    s32 var_fp;
    s32 sp3C;

    s32 sound;

    char position[5];
    uObjSprite *rect;
    attack_t *attack;
    block_t *block;

#if 0
    int count; // r7
    int pos; // r25
    int type; // r4
    int lev; // r24
    int row; // r6
    int col; // r23

    int drop; // r22

    int sound; // r1+0x20

    int upgrade; // r21

    char position[5]; // r1+0x18
    uObjSprite * rect; // r3
    struct attack_t * attack; // r4
#endif

    var_fp = 0;
    sp3C = -1;
    sound = 0;
    bzero(position, sizeof(position));

    position[0] = -1;
    for (count = 0; count < ATTACK_COUNT; count++) {
        attack = &well->attack[count];

        if ((attack->type == ATTACKTYPE_10) && (attack->unk_28 != -1)) {
            if ((attack->state == ATTACKSTATE_1) || (attack->state == ATTACKSTATE_2)) {
                if (attack->disappear != -1) {
                    sp3C = well->attack[attack->unk_28].disappear;
                }
            }
        } else if ((attack->state >= ATTACKSTATE_1) && (attack->state <= ATTACKSTATE_3)) {
            if (attack->disappear != -1) {
                if (attack->disappear < ARRAY_COUNT(position)) {
                    position[attack->disappear] = -1;
                }
            }
        }
    }

    for (count = 0; count < ATTACK_COUNT; count++) {
        attack = &well->attack[count];

        switch (attack->state) {
            case ATTACKSTATE_1:
                gOverflow += 0x1E;
                AttackFly(well, attack, num);
                break;

            case ATTACKSTATE_2:
            case ATTACKSTATE_3:
            case ATTACKSTATE_4:
                if (attack->state != ATTACKSTATE_4) {
                    gOverflow += 0x3C;
                }

                if (position[attack->disappear - 1] == 0) {
                    if (sp3C != attack->disappear) {
                        attack->disappear--;
                        if (attack->disappear < ARRAY_COUNT(position)) {
                            position[attack->disappear] = -1;
                        } else if (attack->disappear == ARRAY_COUNT(position)) {
                            position[attack->disappear - 1] = -1;
                        }
                    }
                }

                AttackTop(well, cursor, attack, num, count);

                if (attack->state == ATTACKSTATE_5) {
                    if (attack->delay == -1) {
                        attack->delay = 0;
                    } else {
                        var_fp++;
                        Init2DAttackFace(attack);
                    }
                } else if (attack->state == ATTACKSTATE_4) {
                    if (attack->delay == 0) {
                        var_fp++;
                        attack->delay = -1;
                        Init2DAttackFace(attack);
                    }
                }
                break;

            case ATTACKSTATE_5:
            case ATTACKSTATE_6:
                if ((attack->type == ATTACKTYPE_4) || (attack->type >= ATTACKTYPE_9)) {
                    gOverflow += attack->level * 0xA;
                }
                AttackFall(well, cursor, attack, &sound);
                attack->unk_20 = 0;
                break;

            case ATTACKSTATE_7:
                AttackShake(well, cursor, attack);
                FALLTHROUGH;

            case ATTACKSTATE_8:
                row = attack->level;
                if ((attack->currRow + row) > BLOCK_LEN_ROWS) {
                    row = BLOCK_LEN_ROWS - attack->currRow;
                }

                gOverflow = gOverflow + ((attack->unk_1C - attack->start) * row * 5) + ((row - 1) * 0xA);
                if ((attack->disappear == -1) && (attack->type != ATTACKTYPE_9)) {
                    if (attack->unk_10 < 0) {
                        attack->unk_10++;
                        if (attack->unk_10 != 0) {
                            if ((attack->currRow < BLOCK_LEN_ROWS) && (attack->unk_20 != 0)) {
                                Update2DAttackFace(well, attack);
                            }
                        }
#if VERSION_EUR
                        if (attack->unk_10 == 0) {
                            if (B_801C6BDC_usa[num] != 0) {
                                Init2DFaceTMEM(attack);
                                Update2DAttackFace(well, attack);
                            }
                        }
#endif
                    } else if (attack->unk_20 != 0) {
                        attack->unk_20 = 0;
                        attack->unk_10 = -0x3C;
#if !VERSION_EUR
                        if (B_801C6BDC_usa[num] != 0) {
                            attack->unk_10 = -0xA;
                        }
#endif
                    } else if (B_801C6BDC_usa[num] != 0) {
                        if (attack->currRow < BLOCK_LEN_ROWS) {
                            Init2DFaceTMEM(attack);
                            Update2DAttackFace(well, attack);
                        }
                    } else if ((attack->currRow < BLOCK_LEN_ROWS) && (AnimationRandom(0x64) % 3 == 0)) {
                        Init2DFaceTMEM(attack);
                        Update2DAttackFace(well, attack);
                    } else {
                        attack->unk_10 = -0x1E;
                    }
                }

                for (lev = 0; lev < attack->level; lev++) {
                    row = attack->currRow + lev;
                    pos = 0;
                    if (row >= BLOCK_LEN_ROWS) {
                        break;
                    }

                    for (col = attack->start; col < attack->unk_1C; pos++, col++) {
                        block = &well->block[row][col];
                        rect = &well->block_rect[row][col];

                        if ((attack->delay > 0) || (attack->unk_10 > 0)) {
                            if (attack->delay % 2 != 0) {
                                rect->s.imageAdrs = 0x86;
                            } else {
                                rect->s.imageAdrs = 6;
                            }
                            continue;
                        }

                        if (attack->disappear != -1) {
                            if (block->drop == 0) {
                                if (block->type == BLOCKTYPE_9) {
                                    rect->s.imageAdrs = 6;
                                }
                                continue;
                            } else if (block->drop == 1) {
                                type = attack->type - 0x16;
                                if (block->type == BLOCKTYPE_9) {
                                    Init2DAttackTMEM(rect, type, lev - 1, pos);
                                }
                                continue;
                            }
                        }

                        type = attack->type;
                        if (block->type == BLOCKTYPE_9) {
                            Init2DAttackTMEM(rect, type, lev, pos);
                        }
                    }
                }
                break;
        }
    }

    st_Attack2DTopPosition[num][0] -= var_fp;
    if (st_Attack2DTopPosition[num][0] < 1) {
        st_Attack2DTopPosition[num][0] = 1;
    }

    if (sound != 0) {
        if (num == 0) {
            PlaySE(SFX_INIT_TABLE, sound + SFX_11A);
        } else {
            PlaySE(SFX_INIT_TABLE, sound + SFX_11D);
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack2d", func_80072198_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack2d", func_800724C4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack2d", func_80070BFC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack2d", func_80070DA8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack2d", func_800724A4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack2d", func_800727D0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack2d", func_80070F08_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack2d", func_800710B4_ger);
#endif

#if VERSION_USA
#ifdef NON_EQUIVALENT
void Change2DAttack(tetWell *well, cursor_t *cursor, s32 num, s32 combo) {
    s32 sp18[5];
    s32 sp3C;
    s32 sp44;
    s32 sp4C;
    s32 sp54;
    s32 *sp8C;
    s32 temp_a0;
    s32 temp_a1_2;
    s32 temp_s5;
    s32 temp_t0;
    s32 temp_v0_3;
    s32 var_a2;
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    s32 var_t0;
    s32 var_t2;
    block_t *temp_s2;
    attack_t *temp_s1;
    s32 temp;
    uObjSprite *rect;

    sp54 = 0;
    var_t2 = 0;
    temp_t0 = well->unk_43C8;
    temp = well->unk_43CC;
    sp44 = well->unk_43D0;

    sp4C = well->unk_43D8;

    for (var_a2 = 0; var_a2 < 5; var_a2++) {
        sp18[var_a2] = -1;
    }

    for (var_a2 = 0; var_a2 < 5; var_a2++) {
        temp_a0 = cursor->unk_84[var_a2];
        if (temp_a0 != 0) {
            gOverflow += temp_a0 * 0x28;
        }
    }

    for (sp3C = 0; sp3C < 0x17; sp3C++) {
        if (cursor->target[sp3C] != 0) {
            temp_s1 = &well->attack[cursor->target[sp3C] - 1];
            var_s4 = temp_s1->level;
            if ((temp_s1->currRow + var_s4) >= 0xD) {
                var_s4 = 0xC - temp_s1->currRow;
            }
            var_t2 += (temp_s1->unk_1C - temp_s1->start) * var_s4;
        }
    }

    if (var_t2 != 0) {
        for (var_a2 = 0; var_a2 < 5; var_a2++) {
            if (cursor->unk_84[var_a2] == 0) {
                break;
            }
        }

        cursor->unk_84[var_a2] = var_t2;

        for (sp3C = 0; sp3C < 0x17; sp3C++) {
            if (cursor->target[sp3C] != 0) {
                temp_s1 = &well->attack[cursor->target[sp3C] - 1];
                temp_s1->delay = temp_t0;
                temp_s1->unk_10 = temp_t0 + temp + ((combo - 1) * sp44) + 1;
                temp_s1->disappear = var_a2;
            }
        }

        for (sp3C = 0; sp3C < 0x17; sp3C++) {
            cursor->target[sp3C] = 0;
        }
    }

    sp8C = sp18;
    for (sp3C = 0; sp3C < 0x14; sp3C++) {
        temp_s1 = &well->attack[sp3C];
        if ((temp_s1->state < 7) || (temp_s1->disappear == -1)) {
            continue;
        }

        cursor->state = 2;
        if ((temp_s1->delay > 0) || (temp_s1->unk_10 > 0)) {
            if (temp_s1->delay > 0) {
                temp_s1->delay--;
                if (temp_s1->unk_10 > 0) {
                    temp_s1->unk_10--;
                    if ((sp54 == 0) && (temp_s1->delay <= 0)) {
                        sp54 = -1;
                        gOverflow += 0x5A;
                    }
                }
            }
            continue;
        }

        var_t0 = 0;
        for (var_t2 = 0; var_t2 < 5; var_t2++) {
            if (sp18[var_t2] == temp_s1->disappear) {
                var_t0 = -1;
            }
        }

        if (var_t0 != 0) {
            continue;
        }

        for (var_s3 = 0; var_s3 < temp_s1->level; var_s3++) {
            var_s4 = temp_s1->currRow + var_s3;

            if (var_s4 < 0xC) {
                for (var_s0 = temp_s1->unk_1C - 1; var_s0 >= temp_s1->start; var_s0--) {
                    temp_s2 = &well->block[var_s4][var_s0];
                    if ((temp_s2->type != BLOCKTYPE_9) || (temp_s2->drop != 0)) {
                        continue;
                    }

                    if (temp_s2->disappear == 0) {
                        temp_s2->disappear = sp44;
                    }
                    *sp8C++ = temp_s1->disappear;
                    temp_s2->disappear--;
                    if (temp_s2->disappear == 0) {
                        temp_v0_3 = cursor->unk_84[temp_s1->disappear];
                        temp_s5 = temp_v0_3 - 1;
                        var_t2 = temp_v0_3;
                        cursor->unk_84[temp_s1->disappear]--;
                        if (temp_v0_3 == 1) {
                            well->unk_43BC = -1;
                            gOverflow += 0x3C;
                        }
                        StartExplosion(well, num, var_s4, var_s0, temp_s2->bomb);
                        PlayExplosionSound(num, temp_s2->sound);
                        if (var_s3 == 0) {
                            temp_s2->type = AttackToBlock(well, var_s4, var_s0);
                            temp_s2->state = BLOCKSTATE_9;
                            temp_s2->chain_flag = -1;
                            temp_s2->delay = (temp_s5 * sp44) + sp4C;
                            rect = &well->block_rect[var_s4][var_s0];
                            Init2DTetrisTMEM(temp_s2, rect);
                        } else {
                            temp_s2->drop = 1;
                        }

                        if ((var_s0 == temp_s1->start) & (var_s3 == 0)) {
                            if (temp_s1->level == 1) {
                                if (temp_s1->type == 0xA) {
                                    temp_s1->type = 4;
                                }
                                temp_a1_2 = (FindEmptySpaces(well, temp_s1) + 1);
                                if (cursor->waiting < sp4C + temp_a1_2) {
                                    cursor->waiting = sp4C + temp_a1_2;
                                }
                                temp_s1->state = 0;
                                temp_s1->disappear = -1;
                                if (cursor->target[0x16] == 0) {
                                    cursor->state = 0;
                                }
                            } else {
                                temp_s1->type += 0x15;
                            }
                        } else if (var_s0 == temp_s1->start) {
                            if (var_s3 == (temp_s1->level - 1)) {
                                temp_s1->currRow++;
                                temp_s1->level--;
                                temp_s1->disappear = -1;
                                temp_s1->type -= 0x16;

                                for (var_s3 = 0; var_s3 < temp_s1->level; var_s3++) {
                                    var_s4 = temp_s1->currRow + var_s3;
                                    for (var_s0 = temp_s1->start; var_s0 < temp_s1->unk_1C; var_s0++) {
                                        well->block[var_s4][var_s0].drop = 0;
                                    }
                                }
                                temp_a1_2 = (FindEmptySpaces(well, temp_s1) + 1);
                                if (cursor->waiting < sp4C + temp_a1_2) {
                                    cursor->waiting = sp4C + temp_a1_2;
                                }
                                if (cursor->unk_84[temp_s1->disappear] == 0) {
                                    cursor->state = 0;
                                }
                            }
                        }
                    }
                    var_s0 = temp_s1->start;
                    var_s3 = temp_s1->level;
                }

            } else {
                temp_s1->currRow++;
                temp_s1->level--;
                temp_s1->disappear = -1;
                temp_s1->type -= 0x16;

                // var_s3 is reused here?
                for (var_s3 = 0; var_s3 < temp_s1->level; var_s3++) {
                    var_s4 = temp_s1->currRow + var_s3;
                    if (var_s4 < 0xC) {
                        for (var_s0 = temp_s1->start; var_s0 < temp_s1->unk_1C; var_s0++) {
                            well->block[var_s4][var_s0].drop = 0;
                        }
                    }
                }

                temp_a1_2 = FindEmptySpaces(well, temp_s1);
                if (cursor->waiting < sp4C + temp_a1_2) {
                    cursor->waiting = sp4C + temp_a1_2;
                }
                cursor->state = 0;
            }
        }
    }

    if (var_t2 == 1) {
        FinishGarbageBlock(well);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/attack2d", Change2DAttack);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack2d", Change2DAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack2d", Change2DAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack2d", Change2DAttack);
#endif
