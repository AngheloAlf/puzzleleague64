#include "assets_variables.h"

#include "alignment.h"
#include "libc/assert.h"
#include "macros_defines.h"

Vp D_01000000_usa = { {
    { 0x0280, 0x01E0, 0x01FF, 0x0000 },
    { 0x0280, 0x01E0, 0x01FF, 0x0000 },
} };

Gfx initRDPstart[] = {
    gsDPSetEnvColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0x00),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetFogColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetFillColor(0x00000000),
    gsDPSetPrimDepth(0, 0),
    gsDPSetConvert(0, 0, 0, 0, 0, 0),
    gsDPSetKeyR(0x00000000, 0x00, 0),
    gsDPSetKeyGB(0x00000000, 0x00, 0, 0x00000000, 0x00, 0),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTileSize(2, 0, 0, 0, 0),
    gsDPSetTileSize(3, 0, 0, 0, 0),
    gsDPSetTileSize(4, 0, 0, 0, 0),
    gsDPSetTileSize(5, 0, 0, 0, 0),
    gsDPSetTileSize(6, 0, 0, 0, 0),
    gsDPSetTileSize(G_TX_LOADTILE, 0, 0, 0, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

Gfx initRDP_dl[] = {
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsSPEndDisplayList(),
};

Gfx init2D_dl[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x01),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPEndDisplayList(),
};

Gfx init3D_dl[] = {
    gsDPPipeSync(),
    gsSPViewport(&D_01000000_usa),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetTexturePersp(G_TP_NONE),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

u16 D_010001F0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/blockn.palette.inc"
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

u16 D_01000408_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo01.palette.inc"
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

// TODO find CI textures
u16 colorTable[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/colorTable.rgba16.inc"
};

uObjTxtr colorLUT = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)colorTable,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01000838_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01000838_usa.i8.inc"
};

u8 D_01000E38_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01000E38_usa.i8.inc"
};

uObjTxtr cursorBig = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01000838_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

uObjTxtr cursorSmall = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01000E38_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01001468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01001468_usa.i8.inc"
};

u8 D_01001C68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01001C68_usa.i8.inc"
};

u8 D_01002468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01002468_usa.i8.inc"
};

u8 D_01002C68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01002C68_usa.i8.inc"
};

u8 D_01003468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01003468_usa.i8.inc"
};

u8 block6[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/block6.ci8.inc"
};
static_assert(sizeof(block6) == BLOCK_TEX_WIDTH * BLOCK_TEX_HEIGHT * sizeof(u8), "");

u8 block7[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/block7.ci8.inc"
};
static_assert(sizeof(block7) == BLOCK_TEX_WIDTH * BLOCK_TEX_HEIGHT * sizeof(u8), "");

u8 block8[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/block8.ci8.inc"
};
static_assert(sizeof(block8) == BLOCK_TEX_WIDTH * BLOCK_TEX_HEIGHT * sizeof(u8), "");

u8 block9[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/block9.ci8.inc"
};
static_assert(sizeof(block9) == BLOCK_TEX_WIDTH * BLOCK_TEX_HEIGHT * sizeof(u8), "");

u8 D_01005C68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01005C68_usa.i8.inc"
};

u8 D_01006468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01006468_usa.i8.inc"
};

u8 D_01006C68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01006C68_usa.i8.inc"
};

u8 D_01007468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01007468_usa.i8.inc"
};

u8 blockn[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/blockn.ci8.inc"
};
static_assert(sizeof(blockn) == BLOCK_TEX_WIDTH * BLOCK_TEX_HEIGHT * sizeof(u8), "");

u8 D_01008468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01008468_usa.i8.inc"
};

u8 D_01008C68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01008C68_usa.i8.inc"
};

u8 D_01009468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01009468_usa.i8.inc"
};

u8 D_01009C68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01009C68_usa.i8.inc"
};

u8 D_0100A468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0100A468_usa.i8.inc"
};

u8 D_0100AC68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0100AC68_usa.i8.inc"
};

u8 D_0100B468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0100B468_usa.i8.inc"
};

u8 D_0100BC68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0100BC68_usa.i8.inc"
};

u8 D_0100C468_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0100C468_usa.i8.inc"
};

u8 D_0100CC68_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0100CC68_usa.i8.inc"
};

/* palette: D_01000408_usa */
u8 combo01[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo01.ci8.inc"
};
static_assert(sizeof(combo01) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo02[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo02.ci8.inc"
};
static_assert(sizeof(combo02) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo03[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo03.ci8.inc"
};
static_assert(sizeof(combo03) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo04[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo04.ci8.inc"
};
static_assert(sizeof(combo04) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo05[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo05.ci8.inc"
};
static_assert(sizeof(combo05) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo06[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo06.ci8.inc"
};
static_assert(sizeof(combo06) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo07[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo07.ci8.inc"
};
static_assert(sizeof(combo07) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo08[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo08.ci8.inc"
};
static_assert(sizeof(combo08) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 combo09[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/combo09.ci8.inc"
};
static_assert(sizeof(combo09) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain01[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain01.ci8.inc"
};
static_assert(sizeof(chain01) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain02[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain02.ci8.inc"
};
static_assert(sizeof(chain02) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain03[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain03.ci8.inc"
};
static_assert(sizeof(chain03) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain04[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain04.ci8.inc"
};
static_assert(sizeof(chain04) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain05[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain05.ci8.inc"
};
static_assert(sizeof(chain05) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain06[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain06.ci8.inc"
};
static_assert(sizeof(chain06) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain07[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain07.ci8.inc"
};
static_assert(sizeof(chain07) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain08[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain08.ci8.inc"
};
static_assert(sizeof(chain08) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain09[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain09.ci8.inc"
};
static_assert(sizeof(chain09) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain010[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain010.ci8.inc"
};
static_assert(sizeof(chain010) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain011[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain011.ci8.inc"
};
static_assert(sizeof(chain011) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain012[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain012.ci8.inc"
};
static_assert(sizeof(chain012) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/* palette: D_01000408_usa */
u8 chain013[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/chain013.ci8.inc"
};
static_assert(sizeof(chain013) == COMBO_CHAIN_TEX_WIDTH * COMBO_CHAIN_TEX_HEIGHT * sizeof(u8), "");

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo1Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo01,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo2Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo02,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo3Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo03,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo4Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo04,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo5Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo05,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo6Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo06,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo7Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo07,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo8Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo08,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr combo9Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)combo09,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain1Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain01,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain2Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain02,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain3Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain03,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain4Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain04,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain5Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain05,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain6Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain06,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain7Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain07,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain8Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain08,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain9Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain09,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain10Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain010,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain11Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain011,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain12Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain012,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: D_01000608_usa
*/
uObjTxtr chain13Block = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)chain013,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01018678_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01018678_usa.i8.inc"
};

u32 D_01018E78_usa[] = {
    0x00001033, (u32)D_01018678_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 smokesmoke[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/smokesmoke.i8.inc"
};
static_assert(sizeof(smokesmoke) == SMOKESMOKE_TEX_WIDTH * SMOKESMOKE_TEX_HEIGHT * sizeof(u8), "");

/*
height: 16
widht: 64
*/
uObjTxtr deadsmoke = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)smokesmoke,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(SMOKESMOKE_TEX_WIDTH * SMOKESMOKE_TEX_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(SMOKESMOKE_TEX_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u16 D_010192A8_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101E4C0_usa.palette.inc"
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
#include "assets/misc/segment_0CA4A0/D_010194C0_usa.i8.inc"
};

u8 D_010196C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_010196C0_usa.i8.inc"
};

u8 D_01019CC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01019CC0_usa.i8.inc"
};

u8 D_01019EC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01019EC0_usa.i8.inc"
};

u8 D_0101A0C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101A0C0_usa.i8.inc"
};

u8 D_0101A4C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101A4C0_usa.i8.inc"
};

u8 D_0101ACC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101ACC0_usa.i8.inc"
};

u8 D_0101B4C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101B4C0_usa.i8.inc"
};

u8 D_0101BCC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101BCC0_usa.i8.inc"
};

u8 D_0101C4C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101C4C0_usa.ci8.inc"
};
static_assert(sizeof(D_0101C4C0_usa) == D_0101C4C0_USA_WIDTH * D_0101C4C0_USA_HEIGHT * sizeof(u8), "");

u8 D_0101CCC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101CCC0_usa.ci8.inc"
};
static_assert(sizeof(D_0101CCC0_usa) == D_0101CCC0_USA_WIDTH * D_0101CCC0_USA_HEIGHT * sizeof(u8), "");

u8 D_0101D4C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101D4C0_usa.i8.inc"
};

u8 D_0101DCC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101DCC0_usa.i8.inc"
};

u8 D_0101E4C0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101E4C0_usa.ci8.inc"
};

u8 D_0101E940_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101E940_usa.ci8.inc"
};

u8 D_0101EDC0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0101EDC0_usa.ci8.inc"
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

uObjTxtr D_0101F2B8_usa = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101CCC0_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
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

/*
width: 48
height: 24
*/
uObjTxtr otherTexture9 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101E4C0_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(48 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(48, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
width: 48
height: 24
*/
uObjTxtr otherTexture10 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101E940_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(48 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(48, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
width: 48
height: 24
*/
uObjTxtr otherTexture11 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_0101EDC0_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(48 * 24, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(48, G_IM_SIZ_8b),
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

u16 numberTable[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text1.palette.inc"
};

uObjTxtr numberLUT = {
    /* type  */ G_OBJLT_TLUT,
    /* image */ (u64 *)numberTable,
    /* phead */ GS_PAL_HEAD(0),
    /* pnum  */ GS_PAL_NUM(256),
    /* zero  */ 0,
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 w_text1[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text1.ci8.inc"
};
static_assert(ARRAY_COUNT(w_text1) == W_TEXT_WIDTH * W_TEXT_HEIGHT, "");

u8 w_text2[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text2.ci8.inc"
};
static_assert(ARRAY_COUNT(w_text2) == W_TEXT_WIDTH * W_TEXT_HEIGHT, "");

u8 w_text3[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text3.ci8.inc"
};
static_assert(ARRAY_COUNT(w_text3) == W_TEXT_WIDTH * W_TEXT_HEIGHT, "");

u8 w_text4[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text4.ci8.inc"
};
static_assert(ARRAY_COUNT(w_text4) == W_TEXT_WIDTH * W_TEXT_HEIGHT, "");

u8 w_text5[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text5.ci8.inc"
};
static_assert(ARRAY_COUNT(w_text5) == W_TEXT_WIDTH * W_TEXT_HEIGHT, "");

u8 w_text6[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/w_text6.ci8.inc"
};
static_assert(ARRAY_COUNT(w_text6) == W_TEXT_WIDTH * W_TEXT_HEIGHT, "");

uObjTxtr numberTexture1 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)w_text1,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(W_TEXT_WIDTH *W_TEXT_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(W_TEXT_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

uObjTxtr numberTexture2 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)w_text2,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(W_TEXT_WIDTH *W_TEXT_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(W_TEXT_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

uObjTxtr numberTexture3 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)w_text3,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(W_TEXT_WIDTH *W_TEXT_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(W_TEXT_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

uObjTxtr numberTexture4 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)w_text4,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(W_TEXT_WIDTH *W_TEXT_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(W_TEXT_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

uObjTxtr numberTexture5 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)w_text5,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(W_TEXT_WIDTH *W_TEXT_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(W_TEXT_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

uObjTxtr numberTexture6 = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)w_text6,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(W_TEXT_WIDTH *W_TEXT_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(W_TEXT_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01022620_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01022620_usa.i8.inc"
};

u32 D_01022E20_usa[] = {
    0x00001033, (u32)D_01022620_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u8 clear[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/clear.ci8.inc"
};
static_assert(ARRAY_COUNT(clear) == CLEAR_TEX_WIDTH * CLEAR_TEX_HEIGHT * sizeof(u8), "");

/*
height: 32
width: 64
palette: numberTable
*/
uObjTxtr clearTexture = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)clear,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(CLEAR_TEX_WIDTH *CLEAR_TEX_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(CLEAR_TEX_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01023650_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01023650_usa.ci8.inc"
};

uObjTxtr transTexture = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)D_01023650_usa,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(64 * 16, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(64, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 arrow[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/arrow.ci8.inc"
};
static_assert(ARRAY_COUNT(arrow) == ARROW_WIDTH * ARROW_HEIGHT * sizeof(u8), "");

uObjTxtr arrowTexture = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)arrow,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(ARROW_WIDTH *ARROW_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(ARROW_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 stars1[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/stars1.ci8.inc"
};
static_assert(sizeof(stars1) == STARS1_TEX_WIDTH * STARS1_TEX_HEIGHT * sizeof(u8), "");


u8 stars2[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/stars2.ci8.inc"
};
static_assert(sizeof(stars2) == STARS2_TEX_WIDTH * STARS2_TEX_HEIGHT * sizeof(u8), "");

/*
height: 32
width: 64
palette: numberTable
*/
uObjTxtr stars1Texture = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)stars1,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(STARS1_TEX_WIDTH * 32, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(STARS1_TEX_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

/*
height: 32
width: 64
palette: numberTable
*/
uObjTxtr stars2Texture = {
    /* type  */ G_OBJLT_TXTRBLOCK,
    /* image */ (u64 *)stars2,
    /* tmem  */ GS_PIX2TMEM(0, G_IM_SIZ_8b),
    /* tsize */ GS_TB_TSIZE(STARS2_TEX_WIDTH * STARS2_TEX_HEIGHT, G_IM_SIZ_8b),
    /* tline */ GS_TB_TLINE(STARS2_TEX_WIDTH, G_IM_SIZ_8b),
    /* sid   */ 0,
    /* flag  */ (u32)-1,
    /* mask  */ 0x0,
};

u8 D_01024CB0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_01024CB0_usa.i8.inc"
};

u8 D_0102AB30_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0102AB30_usa.i8.inc"
};

u8 D_0102CE30_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0102CE30_usa.i8.inc"
};

u8 D_0102EEB0_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0102EEB0_usa.i8.inc"
};

u32 D_0102F0B0_usa[] = {
    0x00000030, (u32)D_0102EEB0_usa, 0x010000FF, 0x00000000, 0xFFFFFFFF, 0x00000000,
};

u8 D_0102F0C8_usa[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/D_0102F0C8_usa.i8.inc"
};

u32 D_0102F8C8_usa[] = {
    0x00001033, (u32)D_0102F0C8_usa, 0x000000FF, 0x01000000, 0xFFFFFFFF, 0x00000000,
};

u16 big_c[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/big_c.rgba16.inc"
};
static_assert(sizeof(big_c) == CURSOR_TEX_WIDTH * CURSOR_TEX_HEIGHT * sizeof(u16), "");

u16 small_c[] ALIGNED(8) = {
#include "assets/misc/segment_0CA4A0/small_c.rgba16.inc"
};
static_assert(sizeof(small_c) == CURSOR_TEX_WIDTH * CURSOR_TEX_HEIGHT * sizeof(u16), "");

static_assert(CURSOR_TEX_REAL_WIDTH <= CURSOR_TEX_WIDTH, "");
