.section .data, "wa"

#if VERSION_USA
.incbin "build/usa/bin/usa/bin_file.archive"
#elif VERSION_EUR
.incbin "build/eur/bin/eur/bin_file.archive"
#elif VERSION_FRA
.incbin "build/fra/bin/fra/bin_file.archive"
#elif VERSION_GER
.incbin "build/ger/bin/ger/bin_file.archive"
#else
.error ""
#endif
