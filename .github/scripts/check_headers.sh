#!/bin/bash

# Build every header from `includes/` individually, to ensure everyone is
# properly selfcontained.
# Uses KMC and flags similar to a real build.


MIPS_FLAGS="-fno-PIC -G 0 -mgp32 -mfp32 -Wa,--force-n64align -mips3 -EB"
MIPS_DEFINES="-D_MIPS_SZLONG=32 -D__USE_ISOC99  -DF3DEX_GBI -D_LANGUAGE_C"
IINCLUDES="-I lib/ultralib/include -I lib/ultralib/include/PR -I lib/ultralib/include/gcc -I lib/libhvqm/include -I include"
VERSION="-DVERSION_USA=1 -DVERSION_STR=\"usa\""
WARNINGS="-Wall -Werror"
OPTS="-O2 -g3"


HEADERS=$(find include/ -type f -name "*.h" | grep -v "/libmus/")
mkdir -p build/header_dummy/

# Count errors instead of failing at the first bad header.
ERRORS=0

for i in $HEADERS;
do
    echo $i
    mkdir -p build/header_dummy/$(dirname $i)
    COMPILER_PATH=tools/gcc_kmc/linux/2.7.2 tools/gcc_kmc/linux/2.7.2/gcc -x c -nostdinc $MIPS_FLAGS $IINCLUDES $MIPS_DEFINES $VERSION $WARNINGS $OPTS -c -o build/header_dummy/$i.o $i
    ERRORS=$[$ERRORS + $?]
    echo
done

exit $ERRORS
