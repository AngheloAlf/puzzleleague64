#include "assets_variables.h"
#include "libultra.h"
#include "alignment.h"

Vp D_01000000_usa = { {
    { 0x0280, 0x01E0, 0x01FF, 0x0000 },
    { 0x0280, 0x01E0, 0x01FF, 0x0000 },
} };

Gfx initRDPstart[] = {
#include "assets/segment_0CA4A0/initRDPstart.gfx.inc.c"
};

Gfx D_010000F8_usa[] = {
#include "assets/segment_0CA4A0/D_010000F8_usa.gfx.inc.c"
};

Gfx D_01000160_usa[] = {
#include "assets/segment_0CA4A0/D_01000160_usa.gfx.inc.c"
};

Gfx D_010001A8_usa[] = {
#include "assets/segment_0CA4A0/D_010001A8_usa.gfx.inc.c"
};

u8 D_010001F0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_010001F0_usa.i8.inc"
};

uObjTxtr D_010003F0_usa = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)D_010001F0_usa,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01000408_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01000408_usa.i8.inc"
};

uObjTxtr D_01000608_usa = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)D_01000408_usa,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01000620_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01000620_usa.i8.inc"
};

uObjTxtr colorLUT = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)D_01000620_usa,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01000838_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01000838_usa.i8.inc"
};

u8 D_01000E38_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01000E38_usa.i8.inc"
};

#if 0
height: 24

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 24, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 24, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 24, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr cursorBig = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01000838_usa,
    /* tmem  */ 0,
    /* tsize */ 191,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 24

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 24, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 24, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 24, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr cursorSmall = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01000E38_usa,
    /* tmem  */ 0,
    /* tsize */ 191,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01001468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01001468_usa.i8.inc"
};

u8 D_01001C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01001C68_usa.i8.inc"
};

u8 D_01002468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01002468_usa.i8.inc"
};

u8 D_01002C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01002C68_usa.i8.inc"
};

u8 D_01003468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01003468_usa.i8.inc"
};

u8 D_01003C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01003C68_usa.i8.inc"
};

u8 D_01004468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01004468_usa.i8.inc"
};

u8 D_01004C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01004C68_usa.i8.inc"
};

u8 D_01005468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01005468_usa.i8.inc"
};

u8 D_01005C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01005C68_usa.i8.inc"
};

u8 D_01006468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01006468_usa.i8.inc"
};

u8 D_01006C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01006C68_usa.i8.inc"
};

u8 D_01007468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01007468_usa.i8.inc"
};

u8 D_01007C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01007C68_usa.i8.inc"
};

u8 D_01008468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01008468_usa.i8.inc"
};

u8 D_01008C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01008C68_usa.i8.inc"
};

u8 D_01009468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01009468_usa.i8.inc"
};

u8 D_01009C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01009C68_usa.i8.inc"
};

u8 D_0100A468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100A468_usa.i8.inc"
};

u8 D_0100AC68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100AC68_usa.i8.inc"
};

u8 D_0100B468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100B468_usa.i8.inc"
};

u8 D_0100BC68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100BC68_usa.i8.inc"
};

u8 D_0100C468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100C468_usa.i8.inc"
};

u8 D_0100CC68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100CC68_usa.i8.inc"
};

u8 D_0100D468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100D468_usa.i8.inc"
};

u8 D_0100DC68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100DC68_usa.i8.inc"
};

u8 D_0100E468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100E468_usa.i8.inc"
};

u8 D_0100EC68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100EC68_usa.i8.inc"
};

u8 D_0100F468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100F468_usa.i8.inc"
};

u8 D_0100FC68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0100FC68_usa.i8.inc"
};

u8 D_01010468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01010468_usa.i8.inc"
};

u8 D_01010C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01010C68_usa.i8.inc"
};

u8 D_01011468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01011468_usa.i8.inc"
};

u8 D_01011C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01011C68_usa.i8.inc"
};

u8 D_01012468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01012468_usa.i8.inc"
};

u8 D_01012C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01012C68_usa.i8.inc"
};

u8 D_01013468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01013468_usa.i8.inc"
};

u8 D_01013C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01013C68_usa.i8.inc"
};

u8 D_01014468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01014468_usa.i8.inc"
};

u8 D_01014C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01014C68_usa.i8.inc"
};

u8 D_01015468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01015468_usa.i8.inc"
};

u8 D_01015C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01015C68_usa.i8.inc"
};

u8 D_01016468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01016468_usa.i8.inc"
};

u8 D_01016C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01016C68_usa.i8.inc"
};

u8 D_01017468_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01017468_usa.i8.inc"
};

u8 D_01017C68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01017C68_usa.i8.inc"
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_01018468_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0100D468_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_01018480_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0100DC68_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_01018498_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0100E468_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_010184B0_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0100EC68_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u32 D_010184C8_usa[] = {
    0x00001033, (u32)D_0100F468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_010184E0_usa[] = {
    0x00001033, (u32)D_0100FC68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_010184F8_usa[] = {
    0x00001033, (u32)D_01010468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018510_usa[] = {
    0x00001033, (u32)D_01010C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018528_usa[] = {
    0x00001033, (u32)D_01011468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018540_usa[] = {
    0x00001033, (u32)D_01011C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018558_usa[] = {
    0x00001033, (u32)D_01012468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018570_usa[] = {
    0x00001033, (u32)D_01012C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018588_usa[] = {
    0x00001033, (u32)D_01013468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_010185A0_usa[] = {
    0x00001033, (u32)D_01013C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_010185B8_usa[] = {
    0x00001033, (u32)D_01014468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_010185D0_usa[] = {
    0x00001033, (u32)D_01014C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_010185E8_usa[] = {
    0x00001033, (u32)D_01015468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018600_usa[] = {
    0x00001033, (u32)D_01015C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018618_usa[] = {
    0x00001033, (u32)D_01016468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018630_usa[] = {
    0x00001033, (u32)D_01016C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018648_usa[] = {
    0x00001033, (u32)D_01017468_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01018660_usa[] = {
    0x00001033, (u32)D_01017C68_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01018678_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01018678_usa.i8.inc"
};

u32 D_01018E78_usa[] = {
    0x00001033, (u32)D_01018678_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01018E90_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01018E90_usa.i8.inc"
};

u32 D_01019290_usa[] = {
    0x00001033, (u32)D_01018E90_usa, 0x0000007F, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_010192A8_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_010192A8_usa.i8.inc"
};

uObjTxtr otherLUT = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)D_010192A8_usa,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_010194C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_010194C0_usa.i8.inc"
};

u8 D_010196C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_010196C0_usa.i8.inc"
};

u8 D_01019CC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01019CC0_usa.i8.inc"
};

u8 D_01019EC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01019EC0_usa.i8.inc"
};

u8 D_0101A0C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101A0C0_usa.i8.inc"
};

u8 D_0101A4C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101A4C0_usa.i8.inc"
};

u8 D_0101ACC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101ACC0_usa.i8.inc"
};

u8 D_0101B4C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101B4C0_usa.i8.inc"
};

u8 D_0101BCC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101BCC0_usa.i8.inc"
};

u8 D_0101C4C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101C4C0_usa.i8.inc"
};

u8 D_0101CCC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101CCC0_usa.i8.inc"
};

u8 D_0101D4C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101D4C0_usa.i8.inc"
};

u8 D_0101DCC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101DCC0_usa.i8.inc"
};

u8 D_0101E4C0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101E4C0_usa.i8.inc"
};

u8 D_0101E940_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101E940_usa.i8.inc"
};

u8 D_0101EDC0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101EDC0_usa.i8.inc"
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F240_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_010194C0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F258_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101A4C0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F270_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101ACC0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F288_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101B4C0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F2A0_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01019CC0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F2B8_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101CCC0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F2D0_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101D4C0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F2E8_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101DCC0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u32 D_0101F300_usa[] = {
    0x00001033, (u32)D_0101E4C0_usa, 0x0000008F, 0x01560000, 0xFFFFFFFF, 0x00000000,
};

u32 D_0101F318_usa[] = {
    0x00001033, (u32)D_0101E940_usa, 0x0000008F, 0x01560000, 0xFFFFFFFF, 0x00000000,
};

u32 D_0101F330_usa[] = {
    0x00001033, (u32)D_0101EDC0_usa, 0x0000008F, 0x01560000, 0xFFFFFFFF, 0x00000000,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F348_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101BCC0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr D_0101F360_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101C4C0_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_0101F378_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101F378_usa.i8.inc"
};

uObjTxtr numberLUT = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)D_0101F378_usa,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_0101F590_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101F590_usa.i8.inc"
};

u8 D_0101FD90_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0101FD90_usa.i8.inc"
};

u8 D_01020590_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01020590_usa.i8.inc"
};

u8 D_01020D90_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01020D90_usa.i8.inc"
};

u8 D_01021590_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01021590_usa.i8.inc"
};

u8 D_01021D90_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01021D90_usa.i8.inc"
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr numberTexture1 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101F590_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr numberTexture2 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101FD90_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr numberTexture3 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01020590_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr numberTexture4 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01020D90_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr numberTexture5 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01021590_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

#if 0
height: 32

Possible widths:
    128 (G_IM_SIZ_4b)
    64 (G_IM_SIZ_8b)
    32 (G_IM_SIZ_16b)
    16 (G_IM_SIZ_32b)

Possible combinations:
    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_4b),
    /* tsize */ GS_TB_TSIZE(128 * 32, G_IM_SIZ_4b),
    /* tline */ GS_TB_TLINE(128,      G_IM_SIZ_4b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64,      G_IM_SIZ_8b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_16b),
    /* tsize */ GS_TB_TSIZE(32 * 32, G_IM_SIZ_16b),
    /* tline */ GS_TB_TLINE(32,      G_IM_SIZ_16b),

    /* tmem  */ GS_PIX2TMEM(0,       G_IM_SIZ_32b),
    /* tsize */ GS_TB_TSIZE(16 * 32, G_IM_SIZ_32b),
    /* tline */ GS_TB_TLINE(16,      G_IM_SIZ_32b),
#endif
uObjTxtr numberTexture6 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01021D90_usa,
    /* tmem  */ 0,
    /* tsize */ 255,
    /* tline */ 256,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01022620_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01022620_usa.i8.inc"
};

u32 D_01022E20_usa[] = {
    0x00001033, (u32)D_01022620_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01022E38_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01022E38_usa.i8.inc"
};

u32 D_01023638_usa[] = {
    0x00001033, (u32)D_01022E38_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01023650_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01023650_usa.i8.inc"
};

u32 D_01023A50_usa[] = {
    0x00001033, (u32)D_01023650_usa, 0x0000007F, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01023A68_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01023A68_usa.i8.inc"
};

u32 D_01023C68_usa[] = {
    0x00001033, (u32)D_01023A68_usa, 0x0000003F, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01023C80_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01023C80_usa.i8.inc"
};

u8 D_01024480_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01024480_usa.i8.inc"
};

u32 D_01024C80_usa[] = {
    0x00001033, (u32)D_01023C80_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u32 D_01024C98_usa[] = {
    0x00001033, (u32)D_01024480_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_01024CB0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01024CB0_usa.i8.inc"
};

u8 D_0102AB30_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0102AB30_usa.i8.inc"
};

u8 D_0102CE30_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0102CE30_usa.i8.inc"
};

u8 D_0102EEB0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0102EEB0_usa.i8.inc"
};

u32 D_0102F0B0_usa[] = {
    0x00000030, (u32)D_0102EEB0_usa, 0x010000FF, 0x00000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_0102F0C8_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0102F0C8_usa.i8.inc"
};

u32 D_0102F8C8_usa[] = {
    0x00001033, (u32)D_0102F0C8_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_0102F8E0_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_0102F8E0_usa.i8.inc"
};

u8 D_01030460_usa[] ALIGNED(8) = {
#include "build/bin/usa/assets/segment_0CA4A0/D_01030460_usa.i8.inc"
};
