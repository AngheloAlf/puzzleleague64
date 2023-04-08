/**
 * Original filename: gfx.c
 */

#include "gfx.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "segment_symbols.h"
#include "the_game.h"
#include "buffers.h"

extern UNK_PTR D_800B3AB0_usa;

extern STACK(B_80219E30_usa, 0xC00);
extern STACK(B_8021BAA0_usa, SP_DRAM_STACK_SIZE8);
extern STACK(B_8021BF30_usa, 0x2000);

#if VERSION_USA
void InitGFX(void) {
    D_800B3AB0_usa = gBufferHeap;
    func_80001310_usa(SEGMENT_ROM_START(segment_0CA4A0), D_800B3AB0_usa, SEGMENT_ROM_SIZE(segment_0CA4A0));
    gInfo[0].unk_19020 = 2;
    gInfo[0].unk_19040 = gFramebuffers[0];
    gInfo[1].unk_19020 = 2;
    gInfo[1].unk_19040 = gFramebuffers[1];
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_ON | OS_VI_GAMMA_DITHER_OFF | OS_VI_GAMMA_OFF);
}
#endif

#if VERSION_USA
#if 0
//? DrawMT(s8 *);                                     /* extern */
//? DrawTitle(s32);                                   /* extern */
//? InitTitle(s32);                                   /* extern */
//? InitTutorial(s32);                                /* extern */
//? BuildTask(struct_gInfo *);                /* extern */
//? DrawMenu(s8 *);                          /* extern */
//? InitMenu(s32);                           /* extern */
//s32 func_80024C2C_usa();                            /* extern */
//? DrawStory(s8 *);                          /* extern */
//? InitStory(s32);                           /* extern */
//? DrawEditor(s8 *);                          /* extern */
//? InitEditor(s32);                           /* extern */
//? InitBonus(s32);                           /* extern */
//? DrawBonus(s8 *);                          /* extern */
//? InitStageClearIntro(s32);                           /* extern */
//? DrawStageClearIntro(s8 *);                          /* extern */
//? InitDisplayList(struct_gInfo *);                /* extern */
//? DrawTetris(s8 *);                          /* extern */
//? InitMimic(s32);                           /* extern */
//? InitTetrisWell(s32);                           /* extern */
extern struct_gInfo **B_801C6E54_usa;
extern s8 *glistp;
extern UNK_TYPE D_1000010;

s32 CreateMenuGfxTask(struct_gInfo *arg0) {
    s32 var_v0;
    s8 *temp_s1;
    s8 *temp_s2;
    s8 *temp_v1;
    s8 *temp_v1_2;

    glistp = &arg0->unk_00000[0x70];
    B_801C6E54_usa = &arg0;
    arg0->unk_68 = 0xBC000006;
    arg0->unk_6C = 0;
    glistp = &arg0->unk_00000[0x78];
    arg0->unk_70 = 0xBC000406;
    temp_s1 = glistp;
    temp_s2 = &arg0->unk_00000[0x68];
    arg0->unk_74 = osVirtualToPhysical(D_800B3AB0_usa);
    glistp = temp_s1 + 8;
    temp_s1->unk_0 = 0xBC000806;
    temp_s1->unk_4 = osVirtualToPhysical(temp_s2);
    if (gReset != 0) {
        temp_v1 = glistp;
        gReset = 0;
        glistp = temp_v1 + 8;
        temp_v1->unk_0 = 0x06000000;
        temp_v1->unk_4 = &D_1000010;
        if (gMain == 0x1F4) {
            InitTitle(gMain);
        } else if ((((gMain == 0x258) | (gMain == 0x28A)) != 0) || (gMain == 0x2BC)) {
            InitMenu(gMain);
        } else {
            switch (gMain) {                        /* irregular */
                case 0x36D:
                    InitBonus(gMain);
                    break;
                case 0x378:
                    InitEditor(gMain);
                    break;
                case 0x383:
                    InitStory(gMain);
                    break;
                case 0x341:
                    InitMimic(gMain);
                    break;
                case 0x34C:
                    InitTutorial(gMain);
                    break;
                case 0x357:
                    InitStageClearIntro(gMain);
                    break;
                default:
                    InitTetrisWell(gMain);
                    break;
            }
        }
    }
    InitDisplayList(arg0);
    if (gMain == 0x1F4) {
        DrawTitle(gMain);
    } else if ((((gMain == 0x258) | (gMain == 0x28A)) != 0) || (gMain == 0x2BC)) {
        DrawMenu(temp_s2);
    } else {
        switch (gMain) {                            /* switch 1; irregular */
            case 0x36D:                             /* switch 1 */
                DrawBonus(temp_s2);
                break;
            case 0x378:                             /* switch 1 */
                DrawEditor(temp_s2);
                break;
            case 0x383:                             /* switch 1 */
                DrawStory(temp_s2);
                break;
            default:                                /* switch 1 */
                if (((gMain == 0x341) | (gMain == 0x34C)) != 0) {
                    DrawMT(temp_s2);
                } else if (gMain == 0x357) {
                    DrawStageClearIntro(temp_s2);
                } else {
                    DrawTetris(temp_s2);
                }
                break;
        }
    }
    temp_v1_2 = glistp;
    glistp = temp_v1_2 + 8;
    temp_v1_2->unk_0 = 0xE9000000;
    glistp = temp_v1_2 + 0x10;
    temp_v1_2->unk_4 = 0;
    temp_v1_2->unk_8 = 0xB8000000;
    temp_v1_2->unk_C = 0;
    osWritebackDCacheAll();
    var_v0 = 0;
    if (func_80024C2C_usa() == 0) {
        BuildTask(arg0);
        var_v0 = -1;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", CreateMenuGfxTask);
#endif
#endif

#if VERSION_USA
void CreateGameGfxTask1(struct_gInfo *info) {
    glistp = info->unk_00068;

    gSPSegment(glistp++, 0x00, 0x00000000);
    gSPSegment(glistp++, 0x01, osVirtualToPhysical(D_800B3AB0_usa));
    gSPSegment(glistp++, 0x02, osVirtualToPhysical(info->unk_00068));

    InitDisplayList(info);
}
#endif

#if VERSION_USA
s32 CreateGameGfxTask2(struct_gInfo *info) {
    Gfx *temp_a0 = info->unk_00068;

    B_801C6E54_usa = &info;

    if (B_801F9CF8_usa < 0x6F) {
        DrawMT(temp_a0);
    } else {
        DrawTetris(temp_a0);
    }

    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    osWritebackDCacheAll();

    if (func_80024C2C_usa() == 0) {
        BuildTask(info);
        return -1;
    }
    return 0;
}
#endif

#if VERSION_USA
void BuildTask(struct_gInfo *info) {
    Gfx *v1 = info->unk_00068;
    OSScTask *scTask = &info->scTask;

    scTask->list.t.data_ptr = (void *)v1;
    scTask->list.t.data_size = (glistp - v1) * sizeof(Gfx);
    if (gTheGame.unk_9C0C == 2) {
        scTask->list.t.type = M_GFXTASK;
        scTask->list.t.flags = OS_SC_NEEDS_RSP | OS_SC_DRAM_DLIST;

        scTask->list.t.ucode_boot = (void *)rspbootTextStart;
        scTask->list.t.ucode_boot_size = (u8 *)rspbootTextEnd - (u8 *)rspbootTextStart;

        scTask->list.t.ucode = (void *)gspF3DEX_fifoTextStart;
        scTask->list.t.ucode_data = (void *)gspF3DEX_fifoDataStart;
        scTask->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;

        scTask->list.t.dram_stack = B_8021BAA0_usa;
        scTask->list.t.dram_stack_size = sizeof(B_8021BAA0_usa);

        scTask->list.t.output_buff = B_8021BF30_usa;
        scTask->list.t.output_buff_size = STACK_TOP(B_8021BF30_usa);

        scTask->list.t.yield_data_ptr = B_80219E30_usa;
        scTask->list.t.yield_data_size = sizeof(B_80219E30_usa);
    } else {
        scTask->list.t.type = M_GFXTASK;
        scTask->list.t.flags = OS_SC_NEEDS_RSP | OS_SC_DRAM_DLIST;

        scTask->list.t.ucode_boot = (void *)rspbootTextStart;
        scTask->list.t.ucode_boot_size = 0xD0;

        scTask->list.t.ucode = gspS2DEX_fifoTextStart;
        scTask->list.t.ucode_size = SP_UCODE_SIZE;
        scTask->list.t.ucode_data = gspS2DEX_fifoDataStart;
        scTask->list.t.ucode_data_size = SP_UCODE_DATA_SIZE;

        scTask->list.t.output_buff = B_8021FF50_usa;
        scTask->list.t.output_buff_size = STACK_TOP(B_8021FF50_usa);

        scTask->list.t.dram_stack = NULL;
        scTask->list.t.dram_stack_size = 0;

        scTask->list.t.yield_data_ptr = B_80219E30_usa;
        scTask->list.t.yield_data_size = sizeof(B_80219E30_usa);
    }

    scTask->flags = OS_SC_SWAPBUFFER | OS_SC_LAST_TASK | OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP;
    scTask->next = NULL;
    scTask->msgQ = &B_801C7058_usa;
    scTask->msg = &info->unk_19020;
    scTask->framebuffer = info->unk_19040;
    osSendMesg(B_801AAB9C_usa, scTask, OS_MESG_BLOCK);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", func_800019C0_usa);
#endif
