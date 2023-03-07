# Build options can be changed by modifying the makefile or by building with 'make SETTING=value'.
# It is also possible to override the settings in Defaults in a file called .make_options as 'SETTING=value'.

-include .make_options

MAKEFLAGS += --no-builtin-rules

# Set prefix to mips binutils binaries (mips-linux-gnu-ld => 'mips-linux-gnu-') - Change at your own risk!
# In nearly all cases, not having 'mips-linux-gnu-*' binaries on the PATH is indicative of missing dependencies
MIPS_BINUTILS_PREFIX ?= mips-linux-gnu-


VERSION ?= usa

BASEROM              := baserom.$(VERSION).z64
BASEROM_UNCOMPRESSED := baserom_uncompressed.$(VERSION).z64
TARGET               := puzzleleague


#### Tools ####
ifneq ($(shell type $(MIPS_BINUTILS_PREFIX)ld >/dev/null 2>/dev/null; echo $$?), 0)
$(error Unable to find $(MIPS_BINUTILS_PREFIX)ld. Please install or build MIPS binutils, commonly mips-linux-gnu. (or set MIPS_BINUTILS_PREFIX if your MIPS binutils install uses another prefix))
endif


SPLAT             ?= tools/splat/split.py
SPLAT_YAML        ?= $(TARGET).$(VERSION).yaml



#### Files ####

$(shell mkdir -p asm bin linker_scripts/$(VERSION)/auto)



#### Main Targets ###


extract:
	$(RM) -r asm/$(VERSION) bin/$(VERSION)
	$(SPLAT) $(SPLAT_YAML)


.PHONY: extract
# Prevent removing intermediate files
.SECONDARY:



# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
