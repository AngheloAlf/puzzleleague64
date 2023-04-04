/**
 * Original filename: controller.c
 */

#include "controller.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
extern OSMesg B_801AB80C_usa[1];

void InitController(void) {
    osCreateMesgQueue(&B_801AB988_usa, B_801AB80C_usa, ARRAY_COUNT(B_801AB80C_usa));
    osSetEventMesg(OS_EVENT_SI, &B_801AB988_usa, (OSMesg)1);
    CheckController();
}

extern s32 B_801A5B30_usa;
extern s32 B_801A5B40_usa;
extern OSContStatus B_801F9CA8_usa[MAXCONTROLLERS];

extern u8 D_800B69B0_usa;

#ifdef NON_EQUIVALENT
void CheckController(void) {
    s32 var_a0;

    if (osContInit(&B_801AB988_usa, &D_800B69B0_usa, B_801F9CA8_usa) != 0) {
        osSyncPrintf("InitController(): Failure initing controllers\n");
    }
    osContSetCh(2U);
    osContStartQuery(&B_801AB988_usa);
    osRecvMesg(&B_801AB988_usa, NULL, 1);
    osContGetQuery(&B_801F9CA8_usa);
    D_800B69B0_usa = 0;

    for (var_a0 = 0; var_a0 < 4; var_a0++) {
        if ((B_801F9CA8_usa[var_a0].type & CONT_TYPE_MASK) == CONT_TYPE_NORMAL) {
            D_800B69B0_usa |= 1 << var_a0;
        }
    }

    B_801A5B30_usa = -1;
    B_801A5B40_usa = -1;
    if (D_800B69B0_usa & 1) {
        B_801A5B30_usa = 0;
    }
    if ((D_800B69B0_usa >> 1) & 1) {
        B_801A5B40_usa = 1;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/controller", CheckController);
#endif

void func_80046F8C_usa(void) {
    OSContStatus sp10[MAXCONTROLLERS];
    s32 i;

    osContReset(&B_801AB988_usa, sp10);
    osSetEventMesg(OS_EVENT_SI, &B_801AB988_usa, (OSMesg)1);
    osContSetCh(2);

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (((sp10[i].type & CONT_TYPE_NORMAL) == CONT_TYPE_NORMAL) && (sp10[i].errno != CONT_NO_RESPONSE_ERROR)) {
            D_800B69B0_usa |= 1 << i;
        } else {
            D_800B69B0_usa &= ~(1 << i);
        }
    }
}

#if 0
extern OSContPad B_801C7228_usa;

void UpdateController(void) {
    OSContPad *temp_a2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a3;
    s32 var_v0;
    s8 temp_v1_2;
    s8 temp_v1_3;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u16 var_v0_2;
    void *temp_a1;

    osContGetReadData(&B_801C7228_usa);
    var_a3 = 0;
    var_v0 = 0 & 0xFFFF;
    do {
        temp_a0 = var_v0 * 0x10;
        temp_v1 = *(&B_801A5B30_usa + temp_a0);
        if (temp_v1 == var_v0) {
            temp_a2 = &(&B_801C7228_usa)[temp_v1];
            temp_a1 = temp_a0 + &B_801A5B30_usa;
            if (temp_a2->errno == 0) {
                temp_v1_2 = temp_a2->stick_x;
                var_a0 = (temp_v1_2 < -0x1E) << 9;
                if (temp_v1_2 >= 0x1F) {
                    var_a0 |= 0x100;
                }
                temp_v1_3 = temp_a2->stick_y;
                if (temp_v1_3 < -0x1E) {
                    var_a0 |= 0x400;
                }
                if (temp_v1_3 >= 0x1F) {
                    var_a0 |= 0x800;
                }
                temp_v1_4 = temp_a2->button;
                if (!(temp_v1_4 & 0xF00)) {
                    temp_a2->button = temp_v1_4 | var_a0;
                }
                temp_v1_5 = temp_a2->button ^ temp_a1->unk_E;
                temp_a1->unk_4 = temp_v1_5;
                temp_a1->unk_4 = (u16) (temp_v1_5 & temp_a2->button);
                temp_a1->unk_E = (u16) temp_a2->button;
                temp_a1->unk_6 = (u16) temp_a1->unk_4;
                temp_v1_6 = temp_a2->button;
                if (temp_v1_6 & 0xF00) {
                    if (temp_v1_6 & 0x800) {
                        temp_a2->button = 0x800;
                    } else if (temp_v1_6 & 0x400) {
                        temp_a2->button = 0x400;
                    } else {
                        var_v0_2 = 0x200;
                        if (!(temp_v1_6 & 0x200)) {
                            var_v0_2 = 0x100;
                        }
                        temp_a2->button = var_v0_2;
                    }
                    if (temp_a1->unk_4 & 0xC000) {
                        if (temp_a1->unk_8 <= 0) {
                            temp_a1->unk_6 = 0U;
                        }
                        temp_a1->unk_8 = 0xB;
                    } else {
                        temp_v1_7 = temp_a2->button;
                        if (temp_v1_7 == temp_a1->unk_C) {
                            temp_v0 = temp_a1->unk_8 - 1;
                            temp_a1->unk_8 = temp_v0;
                            if (temp_v0 <= 0) {
                                temp_a1->unk_6 = (u16) temp_a2->button;
                            } else {
                                temp_a1->unk_6 = 0U;
                            }
                        } else {
                            temp_a1->unk_6 = temp_v1_7;
                            temp_a1->unk_8 = 0xA;
                        }
                    }
                } else {
                    temp_a2->button = 0;
                }
                temp_a1->unk_C = (u16) temp_a2->button;
            }
        }
        var_a3 += 1;
        var_v0 = var_a3 & 0xFFFF;
    } while ((u32) (var_a3 & 0xFFFF) < 2U);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/controller", UpdateController);
#endif

#if 0
extern OSContPad B_801C7228_usa;

void UpdateMenuController(void) {
    OSContPad *temp_a2;
    s32 temp_a0;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a3;
    s32 var_v0;
    s8 temp_v1_2;
    s8 temp_v1_3;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v1_4;
    void *temp_a1;

    osContGetReadData(&B_801C7228_usa);
    var_a3 = 0;
    var_v0 = 0 & 0xFFFF;
    do {
        temp_a0 = var_v0 * 0x10;
        temp_v1 = *(&B_801A5B30_usa + temp_a0);
        if (temp_v1 == var_v0) {
            temp_a2 = &(&B_801C7228_usa)[temp_v1];
            temp_a1 = temp_a0 + &B_801A5B30_usa;
            if (temp_a2->errno == 0) {
                temp_v1_2 = temp_a2->stick_x;
                var_a0 = (temp_v1_2 < -0x1E) << 9;
                if (temp_v1_2 >= 0x1F) {
                    var_a0 |= 0x100;
                }
                temp_v1_3 = temp_a2->stick_y;
                if (temp_v1_3 < -0x1E) {
                    var_a0 |= 0x400;
                }
                if (temp_v1_3 >= 0x1F) {
                    var_a0 |= 0x800;
                }
                temp_v1_4 = temp_a2->button;
                if (!(temp_v1_4 & 0xF00)) {
                    temp_a2->button = temp_v1_4 | var_a0;
                }
                temp_v0 = temp_a2->button ^ temp_a1->unk_E;
                temp_a1->unk_4 = temp_v0;
                temp_v0_2 = temp_v0 & temp_a2->button;
                temp_a1->unk_4 = temp_v0_2;
                temp_a1->unk_6 = temp_v0_2;
                if (temp_a2->button != temp_a1->unk_E) {
                    temp_a1->unk_8 = 0xA;
                } else {
                    temp_v0_3 = temp_a1->unk_8 - 1;
                    temp_a1->unk_8 = temp_v0_3;
                    if (temp_v0_3 <= 0) {
                        temp_a1->unk_6 = (u16) temp_a2->button;
                        temp_a1->unk_8 = (s32) (temp_a1->unk_8 + 3);
                    }
                }
                temp_a1->unk_E = (u16) temp_a2->button;
            }
        }
        var_a3 += 1;
        var_v0 = var_a3 & 0xFFFF;
    } while ((u32) (var_a3 & 0xFFFF) < 2U);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/controller", UpdateMenuController);
#endif
#endif
