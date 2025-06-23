/**
 * Original filename: gfx.c
 */

#include "gfx.h"

#include "main_functions.h"
#include "main_variables.h"

#include "assets_variables.h"

#include "bonus.h"
#include "buffers.h"
#include "dlist.h"
#include "draw2d.h"
#include "editor.h"
#include "menu.h"
#include "mimic.h"
#include "screen.h"
#include "stack.h"
#include "story.h"
#include "tetris.h"
#include "the_game.h"
#include "title.h"
#include "tutorial.h"

#include "001F10.h"

void *staticSegment = NULL;

extern STACK(B_80219E30_usa, 0xC00);
extern STACK(B_8021BAA0_usa, SP_DRAM_STACK_SIZE8);
extern STACK(B_8021BF30_usa, 0x2000);

void InitGFX(void) {
    staticSegment = gBufferHeap;
    func_80001310_usa(SEGMENT_ROM_START(segment_0CA4A0), staticSegment, SEGMENT_ROM_SIZE(segment_0CA4A0));

    gInfo[0].unk_19020 = 2;
    gInfo[0].unk_19040 = gFramebuffers[0];
    gInfo[1].unk_19020 = 2;
    gInfo[1].unk_19040 = gFramebuffers[1];
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_ON | OS_VI_GAMMA_DITHER_OFF | OS_VI_GAMMA_OFF);
}

s32 CreateMenuGfxTask(struct_gInfo *info) {
    struct_gInfo_unk_00068 *temp_s2 = &info->unk_00068;

    fb = &info;
    glistp = info->unk_00068.unk_00000;

    gSPSegment(glistp++, 0x00, 0x00000000);

    gSPSegment(glistp++, 0x01, osVirtualToPhysical(staticSegment));
    gSPSegment(glistp++, 0x02, osVirtualToPhysical(temp_s2->unk_00000));

    if (gReset != 0) {
        gReset = 0;

        gSPDisplayList(glistp++, initRDPstart);
        if (gMain == GMAIN_TITLE) {
            InitTitle();
        } else if ((gMain == GMAIN_258) || (gMain == GMAIN_28A) || (gMain == GMAIN_2BC)) {
            InitMenu();
        } else if (gMain == GMAIN_BONUS) {
            InitBonus();
        } else if (gMain == GMAIN_EDITOR) {
            InitEditor();
        } else if (gMain == GMAIN_STORY) {
            InitStory();
        } else if (gMain == GMAIN_MIMIC) {
            InitMimic();
        } else if (gMain == GMAIN_TUTORIAL) {
            InitTutorial();
        } else if (gMain == GMAIN_STAGE_CLEAR_INTRO) {
            InitStageClearIntro();
        } else {
            InitTetrisWell();
        }
    }

    InitDisplayList(info);

    if (gMain == GMAIN_TITLE) {
        DrawTitle();
    } else if (((gMain == GMAIN_258) || (gMain == GMAIN_28A)) || (gMain == GMAIN_2BC)) {
        DrawMenu(temp_s2);
    } else if (gMain == GMAIN_BONUS) {
        DrawBonus(temp_s2);
    } else if (gMain == GMAIN_EDITOR) {
        DrawEditor(temp_s2);
    } else if (gMain == GMAIN_STORY) {
        DrawStory(temp_s2);
    } else if ((gMain == GMAIN_MIMIC) || (gMain == GMAIN_TUTORIAL)) {
        DrawMT(temp_s2);
    } else if (gMain == GMAIN_STAGE_CLEAR_INTRO) {
        DrawStageClearIntro(temp_s2);
    } else {
        DrawTetris(temp_s2);
    }

    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    osWritebackDCacheAll();

    if (!screenFlushing()) {
        BuildTask(info);
        return -1;
    }
    return 0;
}

void CreateGameGfxTask1(struct_gInfo *info) {
    glistp = info->unk_00068.unk_00000;

    gSPSegment(glistp++, 0x00, 0x00000000);
    gSPSegment(glistp++, 0x01, osVirtualToPhysical(staticSegment));
    gSPSegment(glistp++, 0x02, osVirtualToPhysical(info->unk_00068.unk_00000));

    InitDisplayList(info);
}

s32 CreateGameGfxTask2(struct_gInfo *info) {
    struct_gInfo_unk_00068 *temp_a0 = &info->unk_00068;

    fb = &info;

    if (gSelection < 0x6F) {
        DrawMT(temp_a0);
    } else {
        DrawTetris(temp_a0);
    }

    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    osWritebackDCacheAll();

    if (!screenFlushing()) {
        BuildTask(info);
        return -1;
    }
    return 0;
}

void BuildTask(struct_gInfo *info) {
    Gfx *v1 = info->unk_00068.unk_00000;
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
    scTask->msgQ = &gfxFrameMsgQ;
    scTask->msg = &info->unk_19020;
    scTask->framebuffer = info->unk_19040;
    osSendMesg(B_801AAB9C_usa, scTask, OS_MESG_BLOCK);
}
