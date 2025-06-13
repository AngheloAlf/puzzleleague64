#include "074280.h"

#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "001F10.h"
#include "flic.h"

#define LOAD_DATA_SEGMENT(dst, segment, heap)                                        \
    osInvalDCache(SEGMENT_VRAM_START(segment), SEGMENT_VRAM_SIZE(segment));          \
    func_80001310_usa(SEGMENT_ROM_START(segment), (dst), SEGMENT_ROM_SIZE(segment)); \
    heap = (void *)((uintptr_t)heap + SEGMENT_ROM_SIZE(segment))

void func_80073680_usa(void) {
    void *temp_s1;

    temp_s1 = Pon_Image_Heap;
    LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_581DF0, Pon_Image_Heap);

    func_8004E4E4_usa(temp_s1, -1, 0, 2, 0, 0, 0);
}

void func_8007371C_usa(void) {
    void *temp_s1;

    temp_s1 = Pon_Image_Heap;
    LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_58D730, Pon_Image_Heap);

    func_8004E4E4_usa(temp_s1, -1, 0, 2, 0, 0, 0);
}

void func_800737B8_usa(enum_func_800737B8_usa_arg0 arg0) {
    void *temp_s1;

    temp_s1 = Pon_Image_Heap;
    switch (arg0) {
        case ENUM_FUNC_800737B8_USA_ARG0_1:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_599F70, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_2:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5A8C10, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_3:
            if (gTheGame.tetrisWell[0].unk_4420 == 5) {
                LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5F3090, Pon_Image_Heap);
            } else {
                LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5B6730, Pon_Image_Heap);
            }
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_4:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5C62D0, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_5:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5D4870, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_6:
            if (gTheGame.tetrisWell[0].unk_4420 == 5) {
                LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5FF430, Pon_Image_Heap);
            } else {
                LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_5E6490, Pon_Image_Heap);
            }
            break;
    }

    func_8004E4E4_usa(temp_s1, -1, 0, 2, 0, 0, 0);
}

void func_800739F0_usa(enum_func_800739F0_usa_arg0 arg0) {
    void *temp_s1;

    temp_s1 = Pon_Image_Heap;
    switch (arg0) {
        case ENUM_FUNC_800739F0_USA_ARG0_1:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_60BBD0, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800739F0_USA_ARG0_2:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_615150, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800739F0_USA_ARG0_3:
            LOAD_DATA_SEGMENT(temp_s1, segment_assets_074280_61DC70, Pon_Image_Heap);
            break;
    }

    func_8004E4E4_usa(temp_s1, -1, 0, 2, 0, 0, 0);
}
