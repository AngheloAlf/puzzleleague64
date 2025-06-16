#include "074280.h"

#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "001F10.h"
#include "flic.h"

void func_80073680_usa(void) {
    void *segment;

    segment = Pon_Image_Heap;
    LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_581DF0, Pon_Image_Heap);

    InitTrack(segment, ntrue, 0, 2, 0, 0, 0);
}

void func_8007371C_usa(void) {
    void *segment;

    segment = Pon_Image_Heap;
    LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_58D730, Pon_Image_Heap);

    InitTrack(segment, ntrue, 0, 2, 0, 0, 0);
}

void func_800737B8_usa(ENUM_TYPE(enum_func_800737B8_usa_arg0, s32) arg0) {
    void *segment;

    segment = Pon_Image_Heap;
    switch (arg0) {
        case ENUM_FUNC_800737B8_USA_ARG0_1:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_599F70, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_2:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5A8C10, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_3:
            if (gTheGame.tetrisWell[0].unk_4420 == 5) {
                LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5F3090, Pon_Image_Heap);
            } else {
                LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5B6730, Pon_Image_Heap);
            }
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_4:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5C62D0, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_5:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5D4870, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800737B8_USA_ARG0_6:
            if (gTheGame.tetrisWell[0].unk_4420 == 5) {
                LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5FF430, Pon_Image_Heap);
            } else {
                LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_5E6490, Pon_Image_Heap);
            }
            break;
    }

    InitTrack(segment, ntrue, 0, 2, 0, 0, 0);
}

void func_800739F0_usa(ENUM_TYPE(enum_func_800739F0_usa_arg0, s32) arg0) {
    void *segment;

    segment = Pon_Image_Heap;
    switch (arg0) {
        case ENUM_FUNC_800739F0_USA_ARG0_1:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_60BBD0, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800739F0_USA_ARG0_2:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_615150, Pon_Image_Heap);
            break;

        case ENUM_FUNC_800739F0_USA_ARG0_3:
            LOAD_DATA_SEGMENT(segment, segment_flic_anime_bg_61DC70, Pon_Image_Heap);
            break;
    }

    InitTrack(segment, ntrue, 0, 2, 0, 0, 0);
}
