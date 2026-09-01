/**
 * Original filename: attack3d.c
 */

#include "attack3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "cursor.h"
#include "sfxlimit.h"
#include "tetwell.h"

void Init3DAttackPosition(attack_t *attack, ENUM_TYPE(AttackType, s32) type, s32 num) {
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1;
    uObjSprite *rect = &attack->rect;

    attack->state = ATTACKSTATE_1;
    attack->disappear = -1;
    attack->delay = 25;
    attack->type = type;
    attack->level = 1;

    // Shouldn't this be zero?
    rect->s.paddingX = 0x14;
    rect->s.paddingY = 0x10;

    switch (type) {
        case ATTACKTYPE_1:
            temp_v0 = st_AttackPosition[num];
            st_AttackPosition[num] &= 0xFC;
            if ((temp_v0 & 3) == 1) {
                attack->start = 2;
                attack->unk_1C = 5;
                st_AttackPosition[num] |= 2;
            } else {
                attack->start = 5;
                attack->unk_1C = 8;
                st_AttackPosition[num] |= 1;
            }
            rect->s.paddingX = 0x18;
            rect->s.imagePal = 7;
            break;

        case ATTACKTYPE_2:
            temp_v1 = st_AttackPosition[num];
            st_AttackPosition[num] &= 0xE3;

            if ((temp_v1 & 0x1C) == 0x4) {
                attack->start = 2;
                attack->unk_1C = 6;
                st_AttackPosition[num] |= 8;
            } else if ((temp_v1 & 0x1C) == 0x8) {
                attack->start = 3;
                attack->unk_1C = 7;
                st_AttackPosition[num] |= 0x10;
            } else {
                attack->start = 4;
                attack->unk_1C = 8;
                st_AttackPosition[num] |= 4;
            }

            rect->s.paddingX = 0x10;
            rect->s.imagePal = 7;
            break;

        case ATTACKTYPE_3:
            temp_v0_2 = st_AttackPosition[num];
            st_AttackPosition[num] &= 0x9F;

            if ((temp_v0_2 & 0x60) == 0x20) {
                attack->start = 2;
                attack->unk_1C = 7;
                st_AttackPosition[num] |= 0x40;
            } else {
                attack->start = 3;
                attack->unk_1C = 8;
                st_AttackPosition[num] |= 0x20;
            }
            rect->s.paddingX = 0x18;
            rect->s.imagePal = 7;
            break;

        case ATTACKTYPE_4:
            attack->start = 2;
            attack->unk_1C = 8;
            rect->s.imagePal = 5;
            break;

        case ATTACKTYPE_9:
            attack->start = 2;
            attack->unk_1C = 8;
            rect->s.imagePal = 4;
            break;

        case ATTACKTYPE_15:
        case ATTACKTYPE_21:
            rect->s.imagePal = 4;
            break;

        case ATTACKTYPE_10:
        case ATTACKTYPE_16:
            rect->s.imagePal = 5;
            break;

        case ATTACKTYPE_12:
        case ATTACKTYPE_18:
            rect->s.imagePal = 1;
            break;

        case ATTACKTYPE_13:
        case ATTACKTYPE_19:
            rect->s.imagePal = 2;
            break;

        case ATTACKTYPE_14:
        case ATTACKTYPE_20:
            rect->s.imagePal = 3;
            break;

        default:
            rect->s.imagePal = 6;
            break;
    }

    if (attack->type >= ATTACKTYPE_10) {
        Set3DRingPosition(attack);
    }
}

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
        attack->level = attack->type - ATTACKTYPE_11;
    } else {
        attack->level = 1;
    }

    if (attack->level > 0xA) {
        attack->level = 0xA;
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
            PlaySE(SFX_INIT_TABLE, sound + SFX_11A);
        } else {
            PlaySE(SFX_INIT_TABLE, sound + SFX_11D);
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
