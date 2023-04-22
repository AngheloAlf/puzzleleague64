/**
 * Original filename: editor.c
 */

#include "editor.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "screen.h"
#include "sound.h"
#include "file.h"
#include "image.h"

typedef struct struct_800B6470_usa {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ UNK_FUN_PTR unk_4;
} struct_800B6470_usa; // size = 0x8
extern struct_800B6470_usa gaEditData[9];

extern void *Pon_Image_Heap;
extern void *gpHeapEdit;

extern s32 B_8018E9C0_usa; // geMode?
extern s32 B_8018E9CC_usa; // gnFlushCount?
extern s32 giScreenEdit;
extern s32 B_8018E9F0_usa; // gnCursorData?

extern s32 B_8018E9C8_usa;
extern s16 B_8018E9D0_usa;
extern s16 B_8018E9D2_usa;
extern s32 B_8018E9DC_usa;
extern s32 B_8018E9E0_usa;
extern s32 B_8018E9E4_usa;
extern s32 B_801AB808_usa;
extern s32 B_801C6BD8_usa;

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002DC00_usa);
#endif

#if VERSION_USA
s32 func_8002EDF0_usa(s32 arg0) {
    if (arg0 != 0) {
        return -1;
    }

    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002EDFC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F194_usa);
#endif

#if VERSION_USA
void func_8002F2E0_usa(void) {
}
#endif

#if VERSION_USA
void func_8002F2E8_usa(void) {
}
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/editor", RO_800C4470_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F2F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F464_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F73C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F984_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002FCF0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002FF38_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_80030278_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_800304FC_usa);
#endif

#if VERSION_USA
STATIC_INLINE s32 inlined_func(s32 arg0, struct_800B6470_usa **sp10) {
    s32 i;

    for (i = 0; i < ARRAY_COUNTU(gaEditData); i++) {
        if (gaEditData[i].unk_0 == arg0) {
            *sp10 = &gaEditData[i];
            return -1;
        }
    }

    return 0;
}

INLINE s32 func_800306B0_usa(s32 arg0) {
    struct_800B6470_usa *sp10;

    if (arg0 == 0) {
        return 0;
    }

    if ((arg0 < 12) && (arg0 >= 10)) {
        B_8018E9CC_usa = 1;
    } else {
        if (inlined_func(arg0, &sp10) == 0) {
            return 0;
        }
        screenHideText(giScreenEdit, 0x812B80C8);
    }

    B_8018E9C0_usa = arg0;
    if (arg0 == 1) {
        B_8018E9F0_usa = -1;
    }

    return -1;
}
#endif

#if VERSION_USA
#if 0
//? func_80024C54_usa(Gfx **, ? *);                   /* extern */
//? func_8002C2C0_usa(Gfx **);                        /* extern */
//? func_8008937C_usa(Gfx *);                         /* extern */
extern s32 B_801AD9BC_usa;
extern s32 B_801ADAE8_usa;
extern UNK_FUN_PTR func_80030E08_usa;

void DrawEditor(Gfx *gfx) {
    s32 temp_v0;

    if (B_8018E9CC_usa > 0) {
        temp_v0 = B_8018E9CC_usa - 1;
        B_8018E9CC_usa = temp_v0;
        if (temp_v0 == 0) {
            gReset = -1;
            if (B_8018E9C0_usa == 0xA) {
                gMain = GMAIN_2BC;
            } else if (B_8018E9C0_usa == 0xB) {
                gMain = GMAIN_384;
                gSelection = 0x82;
                gTheGame.unk_9C08 = 1;
                gTheGame.unk_9C0C = 1;
                gTheGame.unk_9C28 = 0;
                gTheGame.unk_9C30 = 0;
                gTheGame.unk_0000[0].unk_4404 = 0;
                gTheGame.unk_0000[1].unk_4404 = 0;
                B_801AD9BC_usa = -1;
                B_801ADAE8_usa = -1;
                gTheGame.unk_9C2C = B_801AB808_usa;
            }
        }
    }
    if (func_80024C2C_usa() == 0) {
        func_8008937C_usa(gfx); // DrawPuzzleEditor
    }
    func_80024C54_usa(&glistp, &func_80030E08_usa); // screenDraw
    if (func_80024C2C_usa() == 0) {
        func_8002C2C0_usa(&glistp);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", DrawEditor);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", DoEditor);
#endif

#if VERSION_USA
void InitEditor(void) {
    B_8018E9C0_usa = 0;
    B_8018E9C8_usa = 0;
    B_8018E9CC_usa = -1;
    B_8018E9F0_usa = -1;
    giScreenEdit = -1;
    func_80089318_usa(-1);
    func_8008913C_usa(B_801AB808_usa);
    gTheGame.unk_9C34 = 0;
    B_8018E9DC_usa = 3;
    B_8018E9E0_usa = 1;
    B_8018E9E4_usa = 1;
    B_8018E9D2_usa = 0;
    B_8018E9D0_usa = 0;
    gpHeapEdit = Pon_Image_Heap;

    if (screenLoad("EDITOR.SBF", &gpHeapEdit) != 0) {
        giScreenEdit = screenSet("MAIN", 0xFF001);

        switch (B_801C6BD8_usa) {
            case 0:
                func_800306B0_usa(9);
                break;

            case 1:
                func_800306B0_usa(1);
                break;

            case 3:
                func_800306B0_usa(4);
                break;

            case 2:
                func_800306B0_usa(8);
                break;

            default:
                func_800306B0_usa(10);
                break;
        }
    }

    func_80002A10_usa(0);
}
#endif
