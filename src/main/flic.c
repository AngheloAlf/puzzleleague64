/**
 * Original name: flic.c
 */

#include "flic.h"

#include "include_asm.h"

#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "bg_screen_load.h"

#include "075630.h"

#include "assets/flic_anime_bg.h"

extern s8 FlicLayer[6];

s32 InitAnimeColor(char *currSegment, s32 offset, s32 base, s32 count);
s32 InitAnimeBG(char *currSegment, s32 offset, s32 base, s32 count);
s32 InitAnimeText(char *currSegment, s32 offset, s32 base, s32 count);
s32 InitAnimeSprite(char *currSegment, s32 offset, s32 base, s32 count);
void InitAnimeFlic(char *arg0, s32 arg1, s32 arg2, s32 arg3);

void InitFlic(void) {
    s32 i;

    for (i = 0; i < FLIC_COUNT; i++) {
        flic_t *frame = &gTheGame.flic[i];

        frame->unk_00 = -1;
        frame->unk_04 = -1;
        frame->unk_08 = -1;
        frame->unk_0C = 0xA;
        frame->unk_10 = -1;
        frame->index = -1;
        frame->unk_18 = -1;
        frame->unk_1C = -1;
    }

    for (i = 0; i < ACTION_COUNT; i++) {
        action_t *action = &gTheGame.action[i];

        action->unk_0 = 0;
        action->unk_4 = 0;
        action->unk_8 = 0;
    }

    for (i = 0; i < ARRAY_COUNT(FlicLayer); i++) {
        FlicLayer[i] = 0xA;
    }
}

void InitTrack(char *currSegment, nbool first, s32 color, s32 bg, s32 text, s32 sprite, s32 track) {
    s32 offset = 0;

    if (color != 0) {
        offset = InitAnimeColor(currSegment, offset, !first ? 5 : 0, color);
    }
    if (bg != 0) {
        offset = InitAnimeBG(currSegment, offset, !first ? 6 : 0, bg);
    }
    if (text != 0) {
        offset = InitAnimeText(currSegment, offset, !first ? 5 : 0, text);
    }
    if (sprite != 0) {
        offset = InitAnimeSprite(currSegment, offset, !first ? 5 : 0, sprite);
    }
    if (track != 0) {
        InitAnimeFlic(currSegment, offset, !first ? 5 : 0, track);
    }
}

s32 InitAnimeColor(char *currSegment, s32 offset, s32 base, s32 count) {
    s16 *infor = (void *)(currSegment + offset);
    s32 i;

    offset += count * sizeof(s16);

    for (i = base; i < base + count; i++, infor++) {
        if (*infor != 0) {
            uObjTxtr *lut = &gTheGame.unk_8B98[i];

            lut->tlut.type = G_OBJLT_TLUT;
            lut->tlut.image = (void *)(currSegment + offset);
            lut->tlut.phead = GS_PAL_HEAD(0);
            lut->tlut.pnum = GS_PAL_NUM(*infor);
            lut->tlut.zero = 0;
            lut->tlut.sid = 0;
            lut->tlut.flag = (u32)-1;
            lut->tlut.mask = 0;
            offset += *infor * sizeof(s16);
        }
    }

    return offset;
}

s32 InitAnimeBG(char *currSegment, s32 offset, s32 base, s32 count) {
    FlicAnimeBGHeader *infor = (void *)(currSegment + offset);
    s32 i;

    offset += count * sizeof(FlicAnimeBGHeader);

    for (i = base; i < base + count; i++, infor++) {
        uObjBg *bg = &gTheGame.unk_8C88[i];

        bg->b.imageX = 0;
        bg->b.imageW = infor->width << 2;
        bg->b.frameX = infor->x << 2;
        bg->b.frameW = infor->width << 2;
        bg->b.imageY = 0;
        bg->b.imageH = infor->height << 2;
        bg->b.frameY = infor->y << 2;
        bg->b.frameH = infor->height << 2;
        bg->b.imagePtr = (void *)(currSegment + offset);
        bg->b.imageLoad = G_BGLT_LOADTILE;

        if (infor->bpp == 8) {
            if (infor->is_intensity == 0) {
                bg->b.imageFmt = G_IM_FMT_CI;
            } else {
                bg->b.imageFmt = G_IM_FMT_I;
            }
            bg->b.imageSiz = G_IM_SIZ_8b;
        } else {
            bg->b.imageFmt = G_IM_FMT_RGBA;
            bg->b.imageSiz = G_IM_SIZ_16b;
        }

        bg->b.imagePal = 0;
        bg->b.imageFlip = 0;

        guS2DInitBg(bg);

        if (infor->bpp == 8) {
            offset += infor->width * infor->height * sizeof(u8);
        } else {
            offset += infor->width * infor->height * sizeof(u16);
        }
    }

    return offset;
}

void InitAnimeBGTransparent(void) {
    s32 i;

    for (i = 0; i < FLIC_COUNT; i++) {
        flic_t *frame = &gTheGame.flic[i];

        if ((frame->unk_08 < 0) && (frame->unk_08 != -0xFF)) {
            s32 index = frame->index;

            gTheGame.unk_8C88[index].s.imageYorig = 0;
            gTheGame.unk_8C88[index].s.scaleW = 1 << 10;
            gTheGame.unk_8C88[index].s.scaleH = 1 << 10;
        }
    }
}

typedef struct struct_InitAnimeText_var {
    /* 0x0 */ s16 width;
    /* 0x2 */ s16 height;
} struct_InitAnimeText_var; // size = 0x4

s32 InitAnimeText(char *currSegment, s32 offset, s32 base, s32 count) {
    struct_InitAnimeText_var *infor = (void *)(currSegment + offset);
    s32 i;

    offset += count * sizeof(struct_InitAnimeText_var);

    for (i = base; i < base + count; i++, infor++) {
        uObjTxtr *txtr = &gTheGame.unk_8EE0[i];

        txtr->block.type = G_OBJLT_TXTRBLOCK;
        txtr->block.image = (void *)(currSegment + offset);
        txtr->block.tmem = 0;
        txtr->block.tsize = GS_TB_TSIZE(infor->width * infor->height, G_IM_SIZ_8b);
        txtr->block.tline = GS_TB_TLINE(infor->width, G_IM_SIZ_8b);
        txtr->block.sid = 0;
        txtr->block.flag = (u32)-1;
        txtr->block.mask = 0;

        offset += infor->width * infor->height;
    }

    return offset;
}

typedef struct struct_InitAnimeSprite_var {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 unk_2;
    /* 0x4 */ s16 unk_4;
    /* 0x6 */ s16 unk_6;
    /* 0x8 */ s16 unk_8;
    /* 0xA */ s16 unk_A;
} struct_InitAnimeSprite_var; // size = 0xC

s32 InitAnimeSprite(char *currSegment, s32 offset, s32 base, s32 count) {
    struct_InitAnimeSprite_var *infor = (void *)(currSegment + offset);
    s32 i;

    offset += count * sizeof(struct_InitAnimeSprite_var);

    for (i = base; i < base + count; i++, infor++) {
        uObjSprite *sp = &gTheGame.unk_8FD0[i];

        sp->s.objX = infor->unk_4 << 2;
        sp->s.scaleW = 1 << 10;
        sp->s.imageW = infor->unk_0 << 5;
        sp->s.paddingX = 0;
        sp->s.objY = infor->unk_6 << 2;
        sp->s.scaleH = 1 << 10;
        sp->s.imageH = infor->unk_2 << 5;
        sp->s.paddingY = 0;
        sp->s.imageStride = infor->unk_8 >> 0x3;
        sp->s.imageAdrs = infor->unk_A >> 0x3;
        sp->s.imageFmt = G_IM_FMT_CI;
        sp->s.imageSiz = G_IM_SIZ_8b;
        sp->s.imagePal = 0;
        sp->s.imageFlags = 0;
    }

    return offset;
}

typedef struct struct_InitAnimeFlic_var {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 unk_2;
    /* 0x4 */ s16 unk_4;
    /* 0x6 */ s16 unk_6;
    /* 0x8 */ s16 unk_8;
    /* 0xA */ s16 unk_A;
    /* 0xC */ s16 unk_C;
    /* 0xE */ s16 unk_E;
} struct_InitAnimeFlic_var; // size = 0x10

#if VERSION_USA
#ifdef NON_MATCHING
void InitAnimeFlic(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    flic_t *var_v1;
    struct_InitAnimeFlic_var *var_a0;
    s32 var_a2;
    s32 var_t0;
    s32 var_t1;

    var_a0 = (void *)(arg0 + arg1);
    var_a2 = arg2;

    for (var_t1 = 0; var_t1 < arg3; var_t1++, var_a0++) {
        for (var_t0 = 0; var_t0 < var_a0->unk_0; var_t0++, var_a2++) {
            var_v1 = &gTheGame.flic[var_a2];

            var_v1->unk_08 = var_a0->unk_2;
            var_v1->unk_0C = var_a0->unk_4;
            var_v1->unk_00 = var_a0->unk_6;
            var_v1->unk_10 = var_a0->unk_8;
            var_v1->index = var_a0->unk_A + var_t0;
            var_v1->unk_18 = var_a0->unk_C;
            var_v1->unk_1C = var_a0->unk_4;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", InitAnimeFlic);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/flic", InitAnimeFlic);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/flic", InitAnimeFlic);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/flic", InitAnimeFlic);
#endif

void Draw2DAnimation(struct_gInfo_unk_00068 *dynamicp UNUSED, s32 from UNUSED, s32 to UNUSED) {
    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    if ((gSelection == 0xAA) && (gTheGame.unk_9C28 == 5)) {
        func_80074D4C_usa();
    }
}

void Draw3DAnimation(struct struct_gInfo_unk_00068 *dynamicp UNUSED, s32 arg1 UNUSED, s32 arg2 UNUSED) {
    if ((gSelection == 0xAA) && (gTheGame.unk_9C28 == 5)) {
        func_80074D4C_usa();
    }
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void func_8004EC4C_usa(TexturePtr arg0, bool arg1, s32 main_height, s32 top_height) {
    s32 sp10[4];
    s32 var_a0;
    s32 var_s2;
    s32 var_v0;
    uObjBg *var_s0;
    s32 i;

    sp10[0] = main_height;
    sp10[1] = top_height;
    sp10[2] = top_height;
    sp10[3] = top_height;
    var_s2 = 0;

    if (arg1) {
        var_a0 = 0;
        var_v0 = 24;
    } else {
        var_a0 = 6;
        var_v0 = 188;
    }

    for (i = 0; i < 4; i++) {
        var_s0 = &gTheGame.unk_8C88[var_a0 + i];

        var_s0->b.imageX = 0;
        var_s0->b.imageW = BGSCREEN_TEX_WIDTH << 2;
        var_s0->b.frameX = var_v0 << 2;
        var_s0->b.frameW = (BGSCREEN_TEX_WIDTH - 4) << 2;

        var_s0->b.imageY = 0;
        var_s0->b.imageH = sp10[i] << 2;
        if (i == 0) {
            var_s0->b.frameY = (216 - sp10[i]) << 2;
        } else {
            var_s0->b.frameY = 24 << 2;
        }
        var_s0->b.frameH = sp10[i] << 2;

        var_s0->b.imagePtr = (TexturePtr)((uintptr_t)arg0 + var_s2);
        var_s0->b.imageLoad = G_BGLT_LOADTILE;
        var_s0->b.imageFmt = G_IM_FMT_RGBA;
        var_s0->b.imageSiz = G_IM_SIZ_16b;
        var_s0->b.imagePal = 0;
        var_s0->b.imageFlip = 0;

        guS2DInitBg(var_s0);
        var_s2 += sp10[i] * 224;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004EC4C_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/flic", func_8004EC4C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/flic", func_8004EC4C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/flic", func_8004EC4C_usa);
#endif
