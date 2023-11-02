.section .data, "wa"

#if VERSION_USA
.incbin "build/bin/usa/bin_file.archive"
#endif

#if VERSION_EUR
.incbin "build/bin/eur/bin_file.archive"
#endif

#if VERSION_FRA
.incbin "build/bin/fra/bin_file.archive"
#endif

#if VERSION_GER
.incbin "build/bin/ger/bin_file.archive"
#endif
