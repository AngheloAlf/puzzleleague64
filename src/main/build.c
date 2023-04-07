#include "build.h"

// Date format: MM/DD/YY

#if VERSION_USA
#define BUILD_DATE "08/14/00"
#define BUILD_TIME "12:29AM"
#endif

#if VERSION_EUR
#define BUILD_DATE "10/20/00"
#define BUILD_TIME "7:10PM"
#endif

#if VERSION_GER
#define BUILD_DATE "12/08/00"
#define BUILD_TIME "6:25PM"
#endif

#if VERSION_FRA
#define BUILD_DATE "12/12/00"
#define BUILD_TIME "10:29AM"
#endif

#if !defined(BUILD_DATE) || MODDING
#undef BUILD_DATE
#define BUILD_DATE __DATE__
#endif

#if !defined(BUILD_TIME) || MODDING
#undef BUILD_TIME
#define BUILD_TIME __TIME__
#endif

const char *gBuildDate = "Created at " BUILD_TIME " on " BUILD_DATE;
