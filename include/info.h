#ifndef INFO_H
#define INFO_H

#include "ultra64.h"
#include "PR/sched.h"
#include "unk.h"

#include "unknown_defines.h"

#include "attack.h"
#include "block.h"
#include "cursor.h"
#include "explode.h"
#include "icon.h"
#include "text.h"


// TODO: Maybe make an enum for this?
#define STRUCT_GINFO_UNK_00068_UNK_10208_LEN (14)

typedef struct struct_gInfo_unk_00068 {
    /* 0x00000 */ Gfx unk_00000[UNK_SIZE];
    /* 0x00008 */ UNK_PAD unk_00008[0x10000-0x00008];
    /* 0x10000 */ Mtx unk_10000[GAME_BUFFER_LEN];
    /* 0x10080 */ Mtx unk_10080[GAME_BUFFER_LEN];
    /* 0x10100 */ Mtx unk_10100[GAME_BUFFER_LEN]; // trans?
    /* 0x10180 */ Mtx unk_10180[GAME_BUFFER_LEN]; // rotate?
    /* 0x10200 */ UNK_TYPE1 unk_10200[0x8];
    /* 0x10208 */ char unk_10208[GAME_BUFFER_LEN][STRUCT_GINFO_UNK_00068_UNK_10208_LEN];
    /* 0x10224 */ s8 unk_10224[GAME_BUFFER_LEN][0xE];
    /* 0x10240 */ UNK_TYPE unk_10240;
    /* 0x10244 */ block_t block[GAME_BUFFER_LEN][BLOCK_LEN_ROWS][BLOCK_LEN_B];
    /* 0x14C84 */ UNK_TYPE1 unk_14C84[0x4];
    /* 0x14C88 */ attack_t attack[GAME_BUFFER_LEN][ATTACK_COUNT];
    /* 0x157C8 */ icon_t icon[GAME_BUFFER_LEN][ICON_COUNT];
    /* 0x15FE8 */ explode_t explosion[GAME_BUFFER_LEN][EXPLOSION_COUNT];
    /* 0x172A8 */ cursor_t cursorBlock[GAME_BUFFER_LEN];
    /* 0x17408 */ uObjSprite block_rect[GAME_BUFFER_LEN][BLOCK_LEN_ROWS][TETWELL_OBJSPRITE_LEN_B];
    /* 0x18188 */ uObjSprite unk_18188[GAME_BUFFER_LEN][TETWELL_UNK_3EF0_LEN_6];
    /* 0x182A8 */ uObjSprite unk_182A8[GAME_BUFFER_LEN];
    /* 0x182D8 */ uObjSprite unk_182D8[GAME_BUFFER_LEN];
    /* 0x18308 */ char unk_18308[GAME_BUFFER_LEN][BLOCK_LEN_ROWS][BLOCK_LEN_B];
    /* 0x184B8 */ Mtx unk_184B8[GAME_BUFFER_LEN];
    /* 0x18538 */ Mtx unk_18538[GAME_BUFFER_LEN];
    /* 0x185B8 */ UNK_TYPE1 unk_185B8[0x140];
    /* 0x186F8 */ text_t drawText[DRAWTEXT_COUNT];
} struct_gInfo_unk_00068; // size = 0x18FB8

#if 0
typedef struct /* struct_pon_gc_draw_c_2466 */ {
    // total size: 0x31B88
    union {
        struct {
            // total size: 0x8
            unsigned int w0; // offset 0x0, size 0x4
            unsigned int w1; // offset 0x4, size 0x4
        } words; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int par : 8; // offset 0x0, size 0x4
            unsigned int len : 16; // offset 0x0, size 0x4
            unsigned int addr; // offset 0x4, size 0x4
        } dma; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad : 24; // offset 0x0, size 0x4
            struct {
                // total size: 0x4
                unsigned char flag; // offset 0x0, size 0x1
                unsigned char v[3]; // offset 0x1, size 0x3
            } tri; // offset 0x4, size 0x4
        } tri; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad : 24; // offset 0x0, size 0x4
            struct {
                // total size: 0x4
                unsigned char flag; // offset 0x0, size 0x1
                unsigned char v[3]; // offset 0x1, size 0x3
            } line; // offset 0x4, size 0x4
        } line; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad1 : 24; // offset 0x0, size 0x4
            int pad2 : 24; // offset 0x4, size 0x4
            unsigned int param : 8; // offset 0x4, size 0x4
        } popmtx; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad0 : 8; // offset 0x0, size 0x4
            int mw_index : 8; // offset 0x0, size 0x4
            int number : 8; // offset 0x0, size 0x4
            int pad1 : 8; // offset 0x4, size 0x4
            int base : 24; // offset 0x4, size 0x4
        } segment; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad0 : 8; // offset 0x0, size 0x4
            int sft : 8; // offset 0x0, size 0x4
            int len : 8; // offset 0x0, size 0x4
            unsigned int data : 32; // offset 0x4, size 0x4
        } setothermodeH; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad0 : 8; // offset 0x0, size 0x4
            int sft : 8; // offset 0x0, size 0x4
            int len : 8; // offset 0x0, size 0x4
            unsigned int data : 32; // offset 0x4, size 0x4
        } setothermodeL; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            unsigned char cmd; // offset 0x0, size 0x1
            unsigned char lodscale; // offset 0x1, size 0x1
            unsigned char tile; // offset 0x2, size 0x1
            unsigned char on; // offset 0x3, size 0x1
            unsigned short s; // offset 0x4, size 0x2
            unsigned short t; // offset 0x6, size 0x2
        } texture; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int pad1 : 24; // offset 0x0, size 0x4
            signed short pad2; // offset 0x4, size 0x2
            signed short scale; // offset 0x6, size 0x2
        } perspnorm; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int fmt : 3; // offset 0x0, size 0x4
            unsigned int siz : 2; // offset 0x0, size 0x4
            unsigned int pad : 7; // offset 0x0, size 0x4
            unsigned int wd : 12; // offset 0x0, size 0x4
            unsigned int dram; // offset 0x4, size 0x4
        } setimg; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int muxs0 : 24; // offset 0x0, size 0x4
            unsigned int muxs1 : 32; // offset 0x4, size 0x4
        } setcombine; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned char pad; // offset 0x1, size 0x1
            unsigned char prim_min_level; // offset 0x2, size 0x1
            unsigned char prim_level; // offset 0x3, size 0x1
            unsigned long color; // offset 0x4, size 0x4
        } setcolor; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            int x0 : 10; // offset 0x0, size 0x4
            int x0frac : 2; // offset 0x0, size 0x4
            int y0 : 10; // offset 0x0, size 0x4
            int y0frac : 2; // offset 0x0, size 0x4
            unsigned int pad : 8; // offset 0x4, size 0x4
            int x1 : 10; // offset 0x4, size 0x4
            int x1frac : 2; // offset 0x4, size 0x4
            int y1 : 10; // offset 0x4, size 0x4
            int y1frac : 2; // offset 0x4, size 0x4
        } fillrect; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int fmt : 3; // offset 0x0, size 0x4
            unsigned int siz : 2; // offset 0x0, size 0x4
            unsigned int pad0 : 1; // offset 0x0, size 0x4
            unsigned int line : 9; // offset 0x0, size 0x4
            unsigned int tmem : 9; // offset 0x0, size 0x4
            unsigned int pad1 : 5; // offset 0x4, size 0x4
            unsigned int tile : 3; // offset 0x4, size 0x4
            unsigned int palette : 4; // offset 0x4, size 0x4
            unsigned int ct : 1; // offset 0x4, size 0x4
            unsigned int mt : 1; // offset 0x4, size 0x4
            unsigned int maskt : 4; // offset 0x4, size 0x4
            unsigned int shiftt : 4; // offset 0x4, size 0x4
            unsigned int cs : 1; // offset 0x4, size 0x4
            unsigned int ms : 1; // offset 0x4, size 0x4
            unsigned int masks : 4; // offset 0x4, size 0x4
            unsigned int shifts : 4; // offset 0x4, size 0x4
        } settile; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int sl : 12; // offset 0x0, size 0x4
            unsigned int tl : 12; // offset 0x0, size 0x4
            int pad : 5; // offset 0x4, size 0x4
            unsigned int tile : 3; // offset 0x4, size 0x4
            unsigned int sh : 12; // offset 0x4, size 0x4
            unsigned int th : 12; // offset 0x4, size 0x4
        } loadtile; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int sl : 12; // offset 0x0, size 0x4
            unsigned int tl : 12; // offset 0x0, size 0x4
            int pad : 5; // offset 0x4, size 0x4
            unsigned int tile : 3; // offset 0x4, size 0x4
            unsigned int sh : 12; // offset 0x4, size 0x4
            unsigned int th : 12; // offset 0x4, size 0x4
        } settilesize; // offset 0x0, size 0x8
        struct {
            // total size: 0x8
            int cmd : 8; // offset 0x0, size 0x4
            unsigned int sl : 12; // offset 0x0, size 0x4
            unsigned int tl : 12; // offset 0x0, size 0x4
            int pad : 5; // offset 0x4, size 0x4
            unsigned int tile : 3; // offset 0x4, size 0x4
            unsigned int sh : 12; // offset 0x4, size 0x4
            unsigned int th : 12; // offset 0x4, size 0x4
        } loadtlut; // offset 0x0, size 0x8
        long long force_structure_alignment; // offset 0x0, size 0x8
    } glist[14336]; // offset 0x0, size 0x1C000
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } projection[4]; // offset 0x1C000, size 0x100
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } viewing[4]; // offset 0x1C100, size 0x100
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } trans[4]; // offset 0x1C200, size 0x100
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } rotate[4]; // offset 0x1C300, size 0x100
    float degree[4]; // offset 0x1C400, size 0x10
    char frontTexture[4][10]; // offset 0x1C410, size 0x28
    char backTexture[4][10]; // offset 0x1C438, size 0x28
    int overflow; // offset 0x1C460, size 0x4
    struct block_t block[4][12][18]; // offset 0x1C464, size 0x9480
    struct attack_t attack[4][40]; // offset 0x258E8, size 0x3200
    struct icon_t icon[4][10]; // offset 0x28AE8, size 0x1040
    struct explode_t explosion[4][50]; // offset 0x29B28, size 0x2580
    struct cursor_t cursorBlock[4]; // offset 0x2C0A8, size 0x440
    union {
        struct {
            // total size: 0x18
            signed short objX; // offset 0x0, size 0x2
            unsigned short scaleW; // offset 0x2, size 0x2
            unsigned short imageW; // offset 0x4, size 0x2
            unsigned short paddingX; // offset 0x6, size 0x2
            signed short objY; // offset 0x8, size 0x2
            unsigned short scaleH; // offset 0xA, size 0x2
            unsigned short imageH; // offset 0xC, size 0x2
            unsigned short paddingY; // offset 0xE, size 0x2
            unsigned short imageStride; // offset 0x10, size 0x2
            unsigned short imageAdrs; // offset 0x12, size 0x2
            unsigned char imageFmt; // offset 0x14, size 0x1
            unsigned char imageSiz; // offset 0x15, size 0x1
            unsigned char imagePal; // offset 0x16, size 0x1
            unsigned char imageFlags; // offset 0x17, size 0x1
        } s; // offset 0x0, size 0x18
        long long force_structure_alignment; // offset 0x0, size 0x8
    } block_rect[4][12][6]; // offset 0x2C4E8, size 0x1B00
    union {
        struct {
            // total size: 0x18
            signed short objX; // offset 0x0, size 0x2
            unsigned short scaleW; // offset 0x2, size 0x2
            unsigned short imageW; // offset 0x4, size 0x2
            unsigned short paddingX; // offset 0x6, size 0x2
            signed short objY; // offset 0x8, size 0x2
            unsigned short scaleH; // offset 0xA, size 0x2
            unsigned short imageH; // offset 0xC, size 0x2
            unsigned short paddingY; // offset 0xE, size 0x2
            unsigned short imageStride; // offset 0x10, size 0x2
            unsigned short imageAdrs; // offset 0x12, size 0x2
            unsigned char imageFmt; // offset 0x14, size 0x1
            unsigned char imageSiz; // offset 0x15, size 0x1
            unsigned char imagePal; // offset 0x16, size 0x1
            unsigned char imageFlags; // offset 0x17, size 0x1
        } s; // offset 0x0, size 0x18
        long long force_structure_alignment; // offset 0x0, size 0x8
    } new_block_rect[4][6]; // offset 0x2DFE8, size 0x240
    union {
        struct {
            // total size: 0x18
            signed short objX; // offset 0x0, size 0x2
            unsigned short scaleW; // offset 0x2, size 0x2
            unsigned short imageW; // offset 0x4, size 0x2
            unsigned short paddingX; // offset 0x6, size 0x2
            signed short objY; // offset 0x8, size 0x2
            unsigned short scaleH; // offset 0xA, size 0x2
            unsigned short imageH; // offset 0xC, size 0x2
            unsigned short paddingY; // offset 0xE, size 0x2
            unsigned short imageStride; // offset 0x10, size 0x2
            unsigned short imageAdrs; // offset 0x12, size 0x2
            unsigned char imageFmt; // offset 0x14, size 0x1
            unsigned char imageSiz; // offset 0x15, size 0x1
            unsigned char imagePal; // offset 0x16, size 0x1
            unsigned char imageFlags; // offset 0x17, size 0x1
        } s; // offset 0x0, size 0x18
        long long force_structure_alignment; // offset 0x0, size 0x8
    } left2D[4]; // offset 0x2E228, size 0x60
    union {
        struct {
            // total size: 0x18
            signed short objX; // offset 0x0, size 0x2
            unsigned short scaleW; // offset 0x2, size 0x2
            unsigned short imageW; // offset 0x4, size 0x2
            unsigned short paddingX; // offset 0x6, size 0x2
            signed short objY; // offset 0x8, size 0x2
            unsigned short scaleH; // offset 0xA, size 0x2
            unsigned short imageH; // offset 0xC, size 0x2
            unsigned short paddingY; // offset 0xE, size 0x2
            unsigned short imageStride; // offset 0x10, size 0x2
            unsigned short imageAdrs; // offset 0x12, size 0x2
            unsigned char imageFmt; // offset 0x14, size 0x1
            unsigned char imageSiz; // offset 0x15, size 0x1
            unsigned char imagePal; // offset 0x16, size 0x1
            unsigned char imageFlags; // offset 0x17, size 0x1
        } s; // offset 0x0, size 0x18
        long long force_structure_alignment; // offset 0x0, size 0x8
    } right2D[4]; // offset 0x2E288, size 0x60
    char visible[4][12][18]; // offset 0x2E2E8, size 0x360
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } left3D[4]; // offset 0x2E648, size 0x100
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } right3D[4]; // offset 0x2E748, size 0x100
    struct flic_t flic[340]; // offset 0x2E848, size 0x2A80
    struct text_t drawText[70]; // offset 0x312C8, size 0x8C0
} struct_pon_gc_draw_c_2466;
#endif


typedef struct struct_gInfo {
    /* 0x00000 */ OSScTask scTask;
    /* 0x00068 */ struct_gInfo_unk_00068 unk_00068; //dp?
    /* 0x19020 */ s16 msg;
    /* 0x19022 */ UNK_PAD unk_19022[0x2];
    /* 0x19024 */ UNK_PAD unk_19024[0x1C];
    /* 0x19040 */ void *unk_19040;
    /* 0x19044 */ UNK_PAD unk_19044[0x4];
} struct_gInfo; // size = 0x19048

#if 0
typedef struct /* struct_pon_gc_c_674 */ {
    // total size: 0x31B90
    struct {
        // total size: 0x31B88
        union {
            struct {
                // total size: 0x8
                unsigned int w0; // offset 0x0, size 0x4
                unsigned int w1; // offset 0x4, size 0x4
            } words; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int par : 8; // offset 0x0, size 0x4
                unsigned int len : 16; // offset 0x0, size 0x4
                unsigned int addr; // offset 0x4, size 0x4
            } dma; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad : 24; // offset 0x0, size 0x4
                struct {
                    // total size: 0x4
                    unsigned char flag; // offset 0x0, size 0x1
                    unsigned char v[3]; // offset 0x1, size 0x3
                } tri; // offset 0x4, size 0x4
            } tri; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad : 24; // offset 0x0, size 0x4
                struct {
                    // total size: 0x4
                    unsigned char flag; // offset 0x0, size 0x1
                    unsigned char v[3]; // offset 0x1, size 0x3
                } line; // offset 0x4, size 0x4
            } line; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad1 : 24; // offset 0x0, size 0x4
                int pad2 : 24; // offset 0x4, size 0x4
                unsigned int param : 8; // offset 0x4, size 0x4
            } popmtx; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad0 : 8; // offset 0x0, size 0x4
                int mw_index : 8; // offset 0x0, size 0x4
                int number : 8; // offset 0x0, size 0x4
                int pad1 : 8; // offset 0x4, size 0x4
                int base : 24; // offset 0x4, size 0x4
            } segment; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad0 : 8; // offset 0x0, size 0x4
                int sft : 8; // offset 0x0, size 0x4
                int len : 8; // offset 0x0, size 0x4
                unsigned int data : 32; // offset 0x4, size 0x4
            } setothermodeH; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad0 : 8; // offset 0x0, size 0x4
                int sft : 8; // offset 0x0, size 0x4
                int len : 8; // offset 0x0, size 0x4
                unsigned int data : 32; // offset 0x4, size 0x4
            } setothermodeL; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                unsigned char cmd; // offset 0x0, size 0x1
                unsigned char lodscale; // offset 0x1, size 0x1
                unsigned char tile; // offset 0x2, size 0x1
                unsigned char on; // offset 0x3, size 0x1
                unsigned short s; // offset 0x4, size 0x2
                unsigned short t; // offset 0x6, size 0x2
            } texture; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int pad1 : 24; // offset 0x0, size 0x4
                signed short pad2; // offset 0x4, size 0x2
                signed short scale; // offset 0x6, size 0x2
            } perspnorm; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int fmt : 3; // offset 0x0, size 0x4
                unsigned int siz : 2; // offset 0x0, size 0x4
                unsigned int pad : 7; // offset 0x0, size 0x4
                unsigned int wd : 12; // offset 0x0, size 0x4
                unsigned int dram; // offset 0x4, size 0x4
            } setimg; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int muxs0 : 24; // offset 0x0, size 0x4
                unsigned int muxs1 : 32; // offset 0x4, size 0x4
            } setcombine; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned char pad; // offset 0x1, size 0x1
                unsigned char prim_min_level; // offset 0x2, size 0x1
                unsigned char prim_level; // offset 0x3, size 0x1
                unsigned long color; // offset 0x4, size 0x4
            } setcolor; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                int x0 : 10; // offset 0x0, size 0x4
                int x0frac : 2; // offset 0x0, size 0x4
                int y0 : 10; // offset 0x0, size 0x4
                int y0frac : 2; // offset 0x0, size 0x4
                unsigned int pad : 8; // offset 0x4, size 0x4
                int x1 : 10; // offset 0x4, size 0x4
                int x1frac : 2; // offset 0x4, size 0x4
                int y1 : 10; // offset 0x4, size 0x4
                int y1frac : 2; // offset 0x4, size 0x4
            } fillrect; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int fmt : 3; // offset 0x0, size 0x4
                unsigned int siz : 2; // offset 0x0, size 0x4
                unsigned int pad0 : 1; // offset 0x0, size 0x4
                unsigned int line : 9; // offset 0x0, size 0x4
                unsigned int tmem : 9; // offset 0x0, size 0x4
                unsigned int pad1 : 5; // offset 0x4, size 0x4
                unsigned int tile : 3; // offset 0x4, size 0x4
                unsigned int palette : 4; // offset 0x4, size 0x4
                unsigned int ct : 1; // offset 0x4, size 0x4
                unsigned int mt : 1; // offset 0x4, size 0x4
                unsigned int maskt : 4; // offset 0x4, size 0x4
                unsigned int shiftt : 4; // offset 0x4, size 0x4
                unsigned int cs : 1; // offset 0x4, size 0x4
                unsigned int ms : 1; // offset 0x4, size 0x4
                unsigned int masks : 4; // offset 0x4, size 0x4
                unsigned int shifts : 4; // offset 0x4, size 0x4
            } settile; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int sl : 12; // offset 0x0, size 0x4
                unsigned int tl : 12; // offset 0x0, size 0x4
                int pad : 5; // offset 0x4, size 0x4
                unsigned int tile : 3; // offset 0x4, size 0x4
                unsigned int sh : 12; // offset 0x4, size 0x4
                unsigned int th : 12; // offset 0x4, size 0x4
            } loadtile; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int sl : 12; // offset 0x0, size 0x4
                unsigned int tl : 12; // offset 0x0, size 0x4
                int pad : 5; // offset 0x4, size 0x4
                unsigned int tile : 3; // offset 0x4, size 0x4
                unsigned int sh : 12; // offset 0x4, size 0x4
                unsigned int th : 12; // offset 0x4, size 0x4
            } settilesize; // offset 0x0, size 0x8
            struct {
                // total size: 0x8
                int cmd : 8; // offset 0x0, size 0x4
                unsigned int sl : 12; // offset 0x0, size 0x4
                unsigned int tl : 12; // offset 0x0, size 0x4
                int pad : 5; // offset 0x4, size 0x4
                unsigned int tile : 3; // offset 0x4, size 0x4
                unsigned int sh : 12; // offset 0x4, size 0x4
                unsigned int th : 12; // offset 0x4, size 0x4
            } loadtlut; // offset 0x0, size 0x8
            long long force_structure_alignment; // offset 0x0, size 0x8
        } glist[14336]; // offset 0x0, size 0x1C000
        union {
            long m[4][4]; // offset 0x0, size 0x40
            long long force_structure_alignment; // offset 0x0, size 0x8
        } projection[4]; // offset 0x1C000, size 0x100
        union {
            long m[4][4]; // offset 0x0, size 0x40
            long long force_structure_alignment; // offset 0x0, size 0x8
        } viewing[4]; // offset 0x1C100, size 0x100
        union {
            long m[4][4]; // offset 0x0, size 0x40
            long long force_structure_alignment; // offset 0x0, size 0x8
        } trans[4]; // offset 0x1C200, size 0x100
        union {
            long m[4][4]; // offset 0x0, size 0x40
            long long force_structure_alignment; // offset 0x0, size 0x8
        } rotate[4]; // offset 0x1C300, size 0x100
        float degree[4]; // offset 0x1C400, size 0x10
        char frontTexture[4][10]; // offset 0x1C410, size 0x28
        char backTexture[4][10]; // offset 0x1C438, size 0x28
        int overflow; // offset 0x1C460, size 0x4
        struct block_t block[4][12][18]; // offset 0x1C464, size 0x9480
        struct attack_t attack[4][40]; // offset 0x258E8, size 0x3200
        struct icon_t icon[4][10]; // offset 0x28AE8, size 0x1040
        struct explode_t explosion[4][50]; // offset 0x29B28, size 0x2580
        struct cursor_t cursorBlock[4]; // offset 0x2C0A8, size 0x440
        union {
            struct {
                // total size: 0x18
                signed short objX; // offset 0x0, size 0x2
                unsigned short scaleW; // offset 0x2, size 0x2
                unsigned short imageW; // offset 0x4, size 0x2
                unsigned short paddingX; // offset 0x6, size 0x2
                signed short objY; // offset 0x8, size 0x2
                unsigned short scaleH; // offset 0xA, size 0x2
                unsigned short imageH; // offset 0xC, size 0x2
                unsigned short paddingY; // offset 0xE, size 0x2
                unsigned short imageStride; // offset 0x10, size 0x2
                unsigned short imageAdrs; // offset 0x12, size 0x2
                unsigned char imageFmt; // offset 0x14, size 0x1
                unsigned char imageSiz; // offset 0x15, size 0x1
                unsigned char imagePal; // offset 0x16, size 0x1
                unsigned char imageFlags; // offset 0x17, size 0x1
            } s; // offset 0x0, size 0x18
            long long force_structure_alignment; // offset 0x0, size 0x8
        } block_rect[4][12][6]; // offset 0x2C4E8, size 0x1B00
        union {
            struct {
                // total size: 0x18
                signed short objX; // offset 0x0, size 0x2
                unsigned short scaleW; // offset 0x2, size 0x2
                unsigned short imageW; // offset 0x4, size 0x2
                unsigned short paddingX; // offset 0x6, size 0x2
                signed short objY; // offset 0x8, size 0x2
                unsigned short scaleH; // offset 0xA, size 0x2
                unsigned short imageH; // offset 0xC, size 0x2
                unsigned short paddingY; // offset 0xE, size 0x2
                unsigned short imageStride; // offset 0x10, size 0x2
                unsigned short imageAdrs; // offset 0x12, size 0x2
                unsigned char imageFmt; // offset 0x14, size 0x1
                unsigned char imageSiz; // offset 0x15, size 0x1
                unsigned char imagePal; // offset 0x16, size 0x1
                unsigned char imageFlags; // offset 0x17, size 0x1
            } s; // offset 0x0, size 0x18
            long long force_structure_alignment; // offset 0x0, size 0x8
        } new_block_rect[4][6]; // offset 0x2DFE8, size 0x240
        union {
            struct {
                // total size: 0x18
                signed short objX; // offset 0x0, size 0x2
                unsigned short scaleW; // offset 0x2, size 0x2
                unsigned short imageW; // offset 0x4, size 0x2
                unsigned short paddingX; // offset 0x6, size 0x2
                signed short objY; // offset 0x8, size 0x2
                unsigned short scaleH; // offset 0xA, size 0x2
                unsigned short imageH; // offset 0xC, size 0x2
                unsigned short paddingY; // offset 0xE, size 0x2
                unsigned short imageStride; // offset 0x10, size 0x2
                unsigned short imageAdrs; // offset 0x12, size 0x2
                unsigned char imageFmt; // offset 0x14, size 0x1
                unsigned char imageSiz; // offset 0x15, size 0x1
                unsigned char imagePal; // offset 0x16, size 0x1
                unsigned char imageFlags; // offset 0x17, size 0x1
            } s; // offset 0x0, size 0x18
            long long force_structure_alignment; // offset 0x0, size 0x8
        } left2D[4]; // offset 0x2E228, size 0x60
        union {
            struct {
                // total size: 0x18
                signed short objX; // offset 0x0, size 0x2
                unsigned short scaleW; // offset 0x2, size 0x2
                unsigned short imageW; // offset 0x4, size 0x2
                unsigned short paddingX; // offset 0x6, size 0x2
                signed short objY; // offset 0x8, size 0x2
                unsigned short scaleH; // offset 0xA, size 0x2
                unsigned short imageH; // offset 0xC, size 0x2
                unsigned short paddingY; // offset 0xE, size 0x2
                unsigned short imageStride; // offset 0x10, size 0x2
                unsigned short imageAdrs; // offset 0x12, size 0x2
                unsigned char imageFmt; // offset 0x14, size 0x1
                unsigned char imageSiz; // offset 0x15, size 0x1
                unsigned char imagePal; // offset 0x16, size 0x1
                unsigned char imageFlags; // offset 0x17, size 0x1
            } s; // offset 0x0, size 0x18
            long long force_structure_alignment; // offset 0x0, size 0x8
        } right2D[4]; // offset 0x2E288, size 0x60
        char visible[4][12][18]; // offset 0x2E2E8, size 0x360
        union {
            long m[4][4]; // offset 0x0, size 0x40
            long long force_structure_alignment; // offset 0x0, size 0x8
        } left3D[4]; // offset 0x2E648, size 0x100
        union {
            long m[4][4]; // offset 0x0, size 0x40
            long long force_structure_alignment; // offset 0x0, size 0x8
        } right3D[4]; // offset 0x2E748, size 0x100
        struct flic_t flic[340]; // offset 0x2E848, size 0x2A80
        struct text_t drawText[70]; // offset 0x312C8, size 0x8C0
    } dp; // offset 0x0, size 0x31B88
    union {
        struct {
            // total size: 0x2
            signed short type; // offset 0x0, size 0x2
        } gen; // offset 0x0, size 0x2
        struct {
            // total size: 0x2
            signed short type; // offset 0x0, size 0x2
        } done; // offset 0x0, size 0x2
    } msg; // offset 0x31B88, size 0x2
    unsigned short * cfb; // offset 0x31B8C, size 0x4
} struct_pon_gc_c_674;
#endif

extern struct struct_gInfo gInfo[2];

#endif
