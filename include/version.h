#ifndef VERSION_HEADER_H
#define VERSION_HEADER_H

/**
 * Macros for checking specific compiler
 */

#ifndef __IS_KMC__
#define __IS_KMC__ ((__GNUC__== 2) && (__GNUC_MINOR__ == 7))
#endif


/**
 * Version macros
 */

#if defined(VERSION_USA) + defined(VERSION_EUR) + defined(VERSION_FRA) + defined(VERSION_GER) == 0
#error "A version must be selected"
#endif

#if defined(VERSION_USA) + defined(VERSION_EUR) + defined(VERSION_FRA) + defined(VERSION_GER) != 1
#error "Only one version must be defined"
#endif


#if VERSION_USA
#define REGION_NTSC 1
#endif

#if VERSION_EUR || VERSION_FRA || VERSION_GER
#define REGION_PAL 1
#endif


#endif
