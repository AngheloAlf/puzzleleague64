/**
 * Original filename: attack.c
 */

#include "attack.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "attack3d.h"
#include "sfxlimit.h"

#if VERSION_USA
// Maybe?
// int FromNumberToCombo(int number /* r1+0x0 */, int * type /* r1+0x4 */)
INLINE s32 func_8005A8D0_usa(s32 arg0, s32 *arg1) {
    switch (arg0) {
        case 0x3:
            *arg1 = 0;
            return 0;

        case 0x4:
            *arg1 = 1;
            break;

        case 0x5:
            *arg1 = 2;
            break;

        case 0x6:
            *arg1 = 3;
            break;

        case 0x8:
            *arg1 = 5;
            break;

        case 0x9:
            *arg1 = 6;
            break;

        case 0xA:
            *arg1 = 7;
            break;

        case 0xB:
            *arg1 = 8;
            break;

        default:
            *arg1 = 4;
            break;
    }

    if (arg0 < 8) {
        return 1;
    }
    if (arg0 < 0xD) {
        return 2;
    }
    if (arg0 == 0xD) {
        return 3;
    }
    if (arg0 < 0x14) {
        return 4;
    }
    if (arg0 < 0x1B) {
        return 6;
    }
    return 8;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", func_8005A990_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", func_8005A9EC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", AttackFly);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", AttackTop);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", AttackFall);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", AttackShake);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", func_8005BD24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", func_8005BEFC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", func_8005BFB4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005AB90_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005AC50_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005ACAC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", AttackFly);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", AttackTop);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", AttackFall);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", AttackShake);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005BFFC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005C1D4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005C28C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_800592D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_80059390_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_800593EC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", AttackFly);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", AttackTop);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", AttackFall);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", AttackShake);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_8005A73C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_8005A914_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_8005A9CC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_80059480_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_80059540_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_8005959C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", AttackFly);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", AttackTop);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", AttackFall);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", AttackShake);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_8005A8EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_8005AAC4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_8005AB7C_ger);
#endif

void AttackPackEmpty(tetWell *well, s32 num) {
    s32 var_a0_2;
    s32 var_s1;
    s32 var_s2;
    nbool var_s4;
    attack_t *attack1;
    attack_t *attack2;

#if 0
    int flag; // r29
    int count; // r28
    int check; // r27
    int pos; // r4
#endif

#if PRESERVE_UB
    var_s4 = nfalse;
#endif

    for (var_s2 = 0; var_s2 < ATTACK_COUNT; var_s2++) {
        if (well->attack[var_s2].state == ATTACKSTATE_0) {
            var_s4 = nfalse;

            for (var_s1 = var_s2 + 1; var_s1 < ATTACK_COUNT; var_s1++) {
                if (well->attack[var_s1].state != ATTACKSTATE_0) {
                    attack1 = &well->attack[var_s1];
                    var_s4 = ntrue;

                    bcopy(attack1, &well->attack[var_s2], sizeof(attack_t));
                    if ((attack1->state >= ATTACKSTATE_1) && (attack1->state <= ATTACKSTATE_3)) {
                        if ((attack1->type >= ATTACKTYPE_10) && (attack1->unk_28 == -1)) {
                            attack_chain2[num] = var_s2;

                            for (var_a0_2 = 0; var_a0_2 < ATTACK_COUNT; var_a0_2++) {
                                if (var_a0_2 != var_s1) {
                                    attack2 = &well->attack[var_a0_2];
                                    if ((attack2->type == ATTACKTYPE_10) && (attack2->unk_28 == var_s1) &&
                                        ((attack2->state == ATTACKSTATE_1) || (attack2->state == ATTACKSTATE_2))) {
                                        attack2->unk_28 = var_s2;
                                    }
                                }
                            }
                        }
                    }

                    attack1->state = ATTACKSTATE_0;
                    attack1->delay = 0;
                    attack1->unk_10 = 0;
                    attack1->disappear = -1;
                    break;
                }
            }
        }

        if (!var_s4) {
            break;
        }
    }
}

s32 ReturnAttackSlot(tetWell *well, s32 row, s32 col) {
    s32 count;
    s32 temp;
    attack_t *attack;

    for (count = 0; count < ATTACK_COUNT; count++) {
        attack = &well->attack[count];

        if ((attack->state < ATTACKSTATE_5) || (attack->disappear != -1)) {
            continue;
        }

        if ((row < attack->unk_24) || (row >= attack->unk_24 + attack->unk_14)) {
            continue;
        }

        if (attack->start == attack->unk_1C) {
            return count;
        } else if (attack->unk_1C < attack->start) {
            // TODO: macro-ify 0x12
            for (temp = attack->start; temp < 0x12; temp++) {
                if (col == temp) {
                    return count;
                }
            }

            for (temp = 0; temp < attack->unk_1C; temp++) {
                if (col == temp) {
                    return count;
                }
            }
        } else if ((col >= attack->start) && (col < attack->unk_1C)) {
            return count;
        }
    }

    return -1;
}

INLINE void Match3DPosition(s32 num, s32 row, s32 col, s32 *x, s32 *y) {
    DATA_INLINE_CONST s32 sp0[] = {
        13, 23, 39, 59, 79, 99, 115, 125,
    };
    DATA_INLINE_CONST s32 sp20[] = {
        177, 187, 203, 223, 243, 263, 279, 289,
    };
    DATA_INLINE_CONST s32 sp40[] = {
        105, 115, 131, 151, 171, 191, 207, 217,
    };
    s32 index;

#if 0
    int left[8]; // r1+0x5C
    int right[8]; // r1+0x3C
    int centre[8]; // r1+0x1C
#endif

    *y = 204 - (row * 16);
    switch (col) {
        case 0x1:
            index = 1;
            break;
        case 0x2:
            index = 2;
            break;
        case 0x3:
            index = 3;
            break;
        case 0x4:
            index = 4;
            break;
        case 0x5:
            index = 5;
            break;
        case 0x6:
            index = 6;
            break;
        case 0x7:
            index = 7;
            break;
        case 0x8:
            index = 8;
            break;
        default:
            *x = -20;
            return;
    }

    if ((gTheGame.unk_9C08 == 1) && (gSelection != 0x64)) {
        *x = sp40[index - 1];
    } else if (num == 0) {
        *x = sp0[index - 1];
    } else {
        *x = sp20[index - 1];
    }
}

void UpdateAttack(tetWell *well, cursor_t *cursor, s32 num) {
    if (gTheGame.unk_9C0C == 1) {
        Update2DAttack(well, cursor, num);
    } else {
        Update3DAttack(well, cursor, num);
    }

    AttackPackEmpty(well, num);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", func_8005C780_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", func_8005CA58_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", func_8005B198_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", func_8005B348_ger);
#endif

void ChangeAttack(tetWell *well, cursor_t *cursor, s32 num, s32 combo) {
    if (gTheGame.unk_9C0C == 1) {
        Change2DAttack(well, cursor, num, combo);
    } else {
        Change3DAttack(well, cursor, num, combo);
    }
}

void InitFlyAttack(tetWell *well, attack_t *attack, s32 posX, s32 posY, s32 type, s32 num) {
    s32 sp10;
    s32 sp14;
    s32 temp_s5;
    s32 var_a0_2;
    s32 temp;

#if 0
    int x; // r1+0x24
    int y; // r1+0x20
    int diff; // r31
    int pos; // r30
    int which; // r5
    int blockHSize; // r29
#endif

    if ((gSelection != 0x64) && ((gSelection < 0x96) || (gSelection >= 0xA1))) {
        return;
    }

    temp_s5 = well->unk_441C - 0xDF;
    if (gTheGame.unk_9C0C == 1) {
        sp10 = well->unk_3830[0][0].s.objX >> 0x2;
        sp14 = (well->unk_3830[0][0].s.objY >> 0x2) - temp_s5;
        Init2DAttackPosition(attack, type, num);
        attack->unk_10 = sp10 + (posX * 0x10);
        attack->unk_24 = sp14 - (posY * 0x10);
        return;
    }

    Match3DPosition(num, posY, posX, &sp10, &sp14);

    if (sp10 > 0) {
        Init3DAttackPosition(attack, type, num);
        attack->unk_10 = sp10;
        attack->unk_24 = sp14 - temp_s5;
        return;
    }

    Init3DAttackPosition(attack, type, num);
    temp = (num == 0) ? 1 : 0;
    if ((attack->type == ATTACKTYPE_10) && (attack->unk_28 != -1)) {
        if (well->attack[attack->unk_28].type < 0xA) {
            attack->state = ATTACKSTATE_0;
            return;
        }

        attack->disappear = well->attack[attack->unk_28].disappear;
        if (well->attack[attack->unk_28].state == ATTACKSTATE_1) {
            well->attack[attack->unk_28].type++;
            // TODO: enum value for AttackType?
            if (well->attack[attack->unk_28].type > 0x16) {
                well->attack[attack->unk_28].type = 0x16;
            }

            Init3DAttackPosition(&well->attack[attack->unk_28], well->attack[attack->unk_28].type, num);
            attack->state = ATTACKSTATE_0;
            return;
        }
    } else {
        var_a0_2 = st_Attack3DTopPosition[temp][0];
        st_Attack3DTopPosition[temp][0] = var_a0_2 + 1;

        attack->disappear = MIN(var_a0_2, 5);
    }

    attack->rect.s.objX = st_Attack3DTopPosition[temp][attack->disappear];
    attack->rect.s.objY = (2 << 2) + 2;
    attack->state = ATTACKSTATE_2;
    attack->delay = ADJUST_FRAMERATE(60);
}

#if VERSION_USA
#if 0
// ? func_80005888_usa(s32, ?, ?);                     /* extern */
// ? InitFlyAttack(tetWell *, void *, s32, s32, s32, s32); /* extern */
// ? Upgrade3DBrick(tetWell *, s32, s32);           /* extern */
extern s32 B_801AB8DC_usa;

void StartAttack(tetWell *well, s32 num) {
    icon_t sp18;

    s32 sp80;
    s32 sp8C;
    s32 *sp94;
    s32 sp9C;
    attack_t *temp_s1;
    s32 temp_s4;
    s32 temp_s7;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    tetWell *var_fp;
    icon_t *temp_s2;
    attack_t *var_s1;
    void *var_s1_2;
    void *var_s1_3;

    s32 temp;

    sp9C = 0;
    if (num == 0) {
        var_fp = &gTheGame.tetrisWell[1];
        sp94 = &attack_chain2[1];
    } else {
        var_fp = &gTheGame.tetrisWell[0];
        sp94 = &attack_chain2[0];
    }

    for (sp8C = 0; sp8C < 0xA; sp8C++) {
        if (well->icon[sp8C].flag == 0) {
            continue;
        }

        temp_s2 = &well->icon[sp8C];
        if (temp_s2->count > 0) {
            continue;
        }

        sp80 = 0;
        temp_s7 = -temp_s2->count;
        if (temp_s2->type == 0xA) {
            if (temp_s7 >= 4) {
                sp9C = temp_s2->count;
                bcopy(temp_s2, &sp18, 0x68);
            }
            well->unk_43A8--;
            temp_s2->count = well->unk_43A8;
            if ((well->unk_43A8 < -0xD) && !(gGameStatus & 2)) {
                temp_s2->count = -0x63;
            }
            gOverflow += well->unk_43A8 * -0x1E;
            temp_s1 = &var_fp->attack[*sp94];
            var_s1 = NULL;

            if ((temp_s1->state - 1) < 3U) {
                if (temp_s1->type >= 0xA) {
                    if ((temp_s1->unk_28 == -1) && (temp_s1->type - 9 < -temp_s2->count)) {
                        for (var_s0 = 0; var_s0 < 0x14; var_s0++) {
                            if (var_fp->attack[var_s0].state == ATTACKSTATE_0) {
                                var_s1 = &var_fp->attack[var_s0];
                                break;
                            }
                        }

                        if (var_s1 == NULL) {
                            if (gTheGame.unk_9C0C != 1) {
                                Upgrade3DBrick(well, *sp94, num);
                            }
                            continue;
                        }

                        var_s1->unk_28 = *sp94;
                        InitFlyAttack(well, var_s1, temp_s2->from_x, temp_s2->to_y, 0xA, num);
                    }
                }
            }

            if (var_s1 == NULL) {
                for (var_s0_2 = 0; var_s0_2 < 0x14; var_s0_2++) {
                    if (var_fp->attack[var_s0_2].state == ATTACKSTATE_0) {
                        var_s1 = &var_fp->attack[var_s0_2];
                        break;
                    }
                }

                if (var_s1 == NULL) {
                    continue;
                }

                var_s1->unk_28 = -1;
                InitFlyAttack(well, var_s1, temp_s2->from_x, temp_s2->to_y, 0xA, num);
                *sp94 = var_s0_2;
            }
        }

        if (temp_s2->type != 0xC) {
            if ((temp_s2->type != 0xA) || (temp_s7 < 4)) {
                if ((temp_s2->type != 0xA) || (well->unk_43A4 == 0)) {
                    continue;
                }
            }
        }

        var_s4 = func_8005A8D0_usa(temp_s7, &sp80);

        if ((var_s4 >= 3) && (gTheGame.unk_9C0C == 2)) {
            var_s4 = 2;
        }
        if (((temp_s2->type == 0xC) & ((temp_s7 < 0x24) ^ 1)) && !(gGameStatus & 2)) {
            temp_s2->type = 0xD;
        }

        for (var_s3 = 0; var_s3 < var_s4; var_s3++) {
            s32 arg4;
            var_s1_2 = NULL;

            for (var_s0_3 = 0; var_s0_3 < 0x14; var_s0_3++) {
                if (var_fp->attack[var_s0_3].state == ATTACKSTATE_0) {
                    var_s1_2 = &var_fp->attack[var_s0_3];
                    break;
                }
            }

            if (var_s1_2 != NULL) {
                if (sp80 < 5) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, sp80, num);
                } else if ((sp80 == 5) && (var_s3 == 0)) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, 1, num);
                } else if ((sp80 == 5) && (var_s3 == 1)) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, 2, num);
                } else if (sp80 == 6) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, 2, num);
                } else if (sp80 == 7) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, 3, num);
                } else if ((sp80 == 8) && (var_s3 == 0)) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, 4, num);
                } else if ((sp80 == 8) && (var_s3 == 1)) {
                    InitFlyAttack(well, var_s1_2, temp_s2->from_x, temp_s2->to_y, 3, num);
                }
            }
        }

        temp_v0_2 = well->unk_43A4;
        if (temp_s7 != temp_v0_2) {
            well->unk_43A4 = temp_v0_2;
        }

        if (well->unk_43A4 != 0) {
            temp_s4 = well->unk_43A4 - 2;
            if ((temp_s2->type != 0xA) && (temp_s7 == 3) && (well->unk_43A4 == temp_s7)) {
                temp_s2->flag = 0;
            }

            if (num == 0) {
                func_80005888_usa(B_801C6EE8_usa, 1, 1);
            } else {
                func_80005888_usa(B_801C6E58_usa, 2, 1);
            }

            for (var_s3_2 = 0; var_s3_2 < temp_s4; var_s3_2++) {
                var_s1_3 = NULL;

                for (var_s0_4 = 0; var_s0_4 < 0x14; var_s0_4++) {
                    if (var_fp->attack[var_s0_4].state == ATTACKSTATE_0) {
                        var_s1_3 = &var_fp->attack[var_s0_4];
                        break;
                    }
                }

                if (var_s1_3 != NULL) {
                    InitFlyAttack(well, var_s1_3, temp_s2->from_x, temp_s2->to_y, 9, num);
                }
            }
        }
    }

    if (sp9C != 0) {
        for (temp = 0; temp < 10; temp++) {
            if (well->icon[temp].flag == 0) {
                sp18.flag = -1;
                if ((sp9C < -0x23) && !(gGameStatus & 2)) {
                    sp18.type = 0xD;
                } else {
                    sp18.type = 0xC;
                }
                sp18.count = sp9C;

                bcopy(&sp18, &well->icon[temp], 0x68);
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/attack", StartAttack);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack", StartAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack", StartAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack", StartAttack);
#endif
