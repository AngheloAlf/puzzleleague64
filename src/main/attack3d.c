/**
 * Original filename: attack3d.c
 */

#include "attack3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "cursor.h"
#include "sfxlimit.h"
#include "tetwell.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack3d", Init3DAttackPosition);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack3d", Init3DAttackPosition);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack3d", Init3DAttackPosition);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack3d", Init3DAttackPosition);
#endif

INLINE void Set3DRingPosition(attack_t *attack) {
    switch (attack->type) {
        case ATTACKTYPE_10:
            attack->start = 2;
            attack->unk_1C = 8;
            break;
        case ATTACKTYPE_11:
            attack->start = 0x11;
            attack->unk_1C = 11;
            break;
        default:
            attack->start = 0xE;
            attack->unk_1C = 0xE;
            break;
    }

    if (attack->type > 0xB) {
        attack->unk_14 = attack->type - 0xB;
    } else {
        attack->unk_14 = 1;
    }

    if (attack->unk_14 > 0xA) {
        attack->unk_14 = 0xA;
    }
}

void Upgrade3DBrick(tetWell *well, s32 slot, s32 num) {
    attack_t *attack = &well->attack[slot];

    if (attack->type < ATTACKTYPE_10) {
        return;
    }

    if (attack->state == ATTACKSTATE_1) {
        attack->type++;
        if (attack->type > 0x16) {
            attack->type = 0x16;
        }

        Init3DAttackPosition(attack, attack->type, num);
        return;
    }

    if ((attack->state == ATTACKSTATE_2) || (attack->state == ATTACKSTATE_3)) {
        attack->state = ATTACKSTATE_2;

        attack->type++;
        if (attack->type > 0x16) {
            attack->type = 0x16;
        }

        attack->rect.s.imagePal++;
        if (attack->type == 0x16) {
            attack->rect.s.imagePal = 6;
        } else if (attack->rect.s.imagePal > 6) {
            attack->rect.s.imagePal = 1;
        }

        Set3DRingPosition(attack);

        attack->delay = ADJUST_FRAMERATE(60);
    }
}

void Draw3DChain3_CrossBoundary(attack_t *attack, s32 *begin, s32 *end, s32 *pos) {
    if (attack->start == 6) {
        if (*begin == 0) {
            *begin = attack->start;
            *end = 9;
            *pos = 0;
        }
    } else if (attack->start == 7) {
        if (*begin == 1) {
            *begin = attack->start;
            *end = 9;
            *pos = 0;
        }
    } else if (attack->start == 8) {
        if (*begin == 2) {
            *begin = attack->start;
            *end = 9;
            *pos = 0;
        }
    }
}

void Update3DAttack(tetWell *well, cursor_t *cursor, s32 num) {
    char position[5];
    attack_t *attack;
    s32 count;
    s32 var_s3 = 0;
    s32 var_fp = -1;
    s32 sound = 0;

#if 0
    int drop; // r27
    int upgrade; // r26
#endif

    bzero(&position, sizeof(s8) * ARRAY_COUNT(position));

    position[0] = -1;
    for (count = 0; count < ATTACK_COUNT; count++) {
        attack = &well->attack[count];

        if ((attack->type == 0xA) && (attack->unk_28 != -1)) {
            if (((attack->state == ATTACKSTATE_1) || (attack->state == ATTACKSTATE_2)) && (attack->disappear != -1)) {
                var_fp = well->attack[attack->unk_28].disappear;
            }
        } else if ((attack->state >= ATTACKSTATE_1) && (attack->state <= ATTACKSTATE_3) && (attack->disappear != -1)) {
            if (attack->disappear < ARRAY_COUNT(position)) {
                position[attack->disappear] = -1;
            }
        }
    }

    for (count = 0; count < ATTACK_COUNT; count++) {
        attack = &well->attack[count];

        switch (attack->state) {
            case ATTACKSTATE_1:
                AttackFly(well, attack, num);
                break;

            case ATTACKSTATE_2:
            case ATTACKSTATE_3:
            case ATTACKSTATE_4:
                if (position[attack->disappear - 1] == 0) {
                    if (var_fp != attack->disappear) {
                        attack->disappear--;
                        if (attack->disappear < ARRAY_COUNT(position)) {
                            position[attack->disappear] = -1;
                        } else if (attack->disappear == ARRAY_COUNT(position)) {
                            position[ARRAY_COUNT(position) - 1] = -1;
                        }
                    }
                }

                AttackTop(well, cursor, attack, num, count);

                if (attack->state == ATTACKSTATE_5) {
                    if (attack->delay == -1) {
                        attack->delay = 0;
                    } else {
                        var_s3++;
                    }
                } else if ((attack->state == ATTACKSTATE_4) && (attack->delay == 0)) {
                    attack->delay = -1;
                    var_s3++;
                }
                break;

            case ATTACKSTATE_5:
            case ATTACKSTATE_6:
                AttackFall(well, cursor, attack, &sound);
                break;

            case ATTACKSTATE_7:
                AttackShake(well, cursor, attack);
                break;
        }
    }

    st_Attack3DTopPosition[num][0] -= var_s3;
    if (st_Attack3DTopPosition[num][0] <= 0) {
        st_Attack3DTopPosition[num][0] = 1;
    }

    if (sound != 0) {
        if (num == 0) {
            PlaySE(SFX_INIT_TABLE, sound + 0x11A);
        } else {
            PlaySE(SFX_INIT_TABLE, sound + 0x11D);
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack3d", func_80069360_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack3d", func_80069630_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack3d", func_80067D78_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack3d", func_80067F20_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack3d", func_80069954_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack3d", func_80069C24_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack3d", func_8006836C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack3d", func_80068514_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/attack3d", Change3DAttack);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/attack3d", Change3DAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/attack3d", Change3DAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/attack3d", Change3DAttack);
#endif
