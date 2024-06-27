# Build options can be changed by modifying the makefile or by building with 'make SETTING=value'.
# It is also possible to override the settings in Defaults in a file called .make_options as 'SETTING=value'.

-include .make_options

MAKEFLAGS += --no-builtin-rules

#### Defaults ####

# If COMPARE is 1, check the output md5sum after building
COMPARE ?= 1
# If NON_MATCHING is 1, define the NON_MATCHING C flag when building
NON_MATCHING ?= 0
# if WERROR is 1, pass -Werror to CC_CHECK, so warnings would be treated as errors
WERROR ?= 0
# Check code syntax with host compiler
RUN_CC_CHECK ?= 1
CC_CHECK_COMP ?= clang
# Dump build object files
OBJDUMP_BUILD ?= 1
# 
MULTISTEP_BUILD ?= 0
# 
MODDING ?= 0
# If non-zero, passes -v to compiler
COMPILER_VERBOSE ?= 0
# If non-zero touching an assembly file will rebuild any file that depends on it
DEP_ASM ?= 1
# If non-zero touching an included file will rebuild any file that depends on it
DEP_INCLUDE ?= 1

# Set prefix to mips binutils binaries (mips-linux-gnu-ld => 'mips-linux-gnu-') - Change at your own risk!
# In nearly all cases, not having 'mips-linux-gnu-*' binaries on the PATH is indicative of missing dependencies
MIPS_BINUTILS_PREFIX ?= mips-linux-gnu-


VERSION ?= usa

BASEROM              := baserom.$(VERSION).z64
TARGET               := puzzleleague64


# TODO: add to splat
export SPIMDISASM_ASM_EMIT_SIZE_DIRECTIVE=True
# export SPIMDISASM_ASM_REFERENCEE_SYMBOLS=True

### Output ###

BUILD_DIR := build/$(VERSION)
ROM       := $(BUILD_DIR)/$(TARGET).$(VERSION).z64
BIN       := $(BUILD_DIR)/$(TARGET).$(VERSION).bin
ELF       := $(BUILD_DIR)/$(TARGET).$(VERSION).elf
LD_MAP    := $(BUILD_DIR)/$(TARGET).$(VERSION).map
LD_SCRIPT := linker_scripts/$(VERSION)/$(TARGET).ld


#### Setup ####

BUILD_DEFINES ?=

ifeq ($(VERSION),usa)
	BUILD_DEFINES   += -DVERSION_USA=1 -DVERSION_STR=\"usa\"
else ifeq ($(VERSION),eur)
	BUILD_DEFINES   += -DVERSION_EUR=1 -DVERSION_STR=\"eur\"
else ifeq ($(VERSION),fra)
	BUILD_DEFINES   += -DVERSION_FRA=1 -DVERSION_STR=\"fra\"
else ifeq ($(VERSION),ger)
	BUILD_DEFINES   += -DVERSION_GER=1 -DVERSION_STR=\"ger\"
else
$(error Invalid VERSION variable detected. Please use either 'usa', 'eur', 'fra' or 'ger')
endif

ifneq ($(MODDING),0)
	BUILD_DEFINES   += -DMODDING=1
	NON_MATCHING := 1
endif

ifneq ($(NON_MATCHING),0)
	BUILD_DEFINES   += -DNON_MATCHING -DAVOID_UB
	COMPARE  := 0
endif

MAKE = make
CPPFLAGS += -fno-dollars-in-identifiers -P
LDFLAGS  := --no-check-sections --emit-relocs

UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	DETECTED_OS := windows
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := mac
	MAKE := gmake
	CPPFLAGS += -xc++
endif

#### Tools ####
ifneq ($(shell type $(MIPS_BINUTILS_PREFIX)ld >/dev/null 2>/dev/null; echo $$?), 0)
$(error Unable to find $(MIPS_BINUTILS_PREFIX)ld. Please install or build MIPS binutils, commonly mips-linux-gnu. (or set MIPS_BINUTILS_PREFIX if your MIPS binutils install uses another prefix))
endif

COMPILER_DIR    := tools/gcc_kmc/$(DETECTED_OS)/2.7.2
CC              := COMPILER_PATH=$(COMPILER_DIR) $(COMPILER_DIR)/gcc

AS              := $(MIPS_BINUTILS_PREFIX)as
LD              := $(MIPS_BINUTILS_PREFIX)ld
OBJCOPY         := $(MIPS_BINUTILS_PREFIX)objcopy
OBJDUMP         := $(MIPS_BINUTILS_PREFIX)objdump
GCC             := $(MIPS_BINUTILS_PREFIX)gcc
CPP             := $(MIPS_BINUTILS_PREFIX)cpp
STRIP           := $(MIPS_BINUTILS_PREFIX)strip
# ICONV           := iconv

PYTHON            ?= python3
SPLAT             ?= $(PYTHON) -m splat split
SPLAT_YAML        ?= $(TARGET).$(VERSION).yaml
CHECKSUMMER       ?= tools/checksummer.py
PIGMENT64         ?= pigment64

export SPIMDISASM_PANIC_RANGE_CHECK="True"


IINC       := -I include -I bin/$(VERSION) -I $(BUILD_DIR)/bin/$(VERSION) -I .
IINC       += -I lib -I lib/libultra_j/include -I lib/libultra_j/include/PR -I lib/libhvqm/include -I lib/libmus/include

# Check code syntax with host compiler
CHECK_WARNINGS := -Wall -Wextra -Wimplicit-fallthrough -Wno-unknown-pragmas -Wno-missing-braces -Wno-sign-compare -Wno-uninitialized
# Have CC_CHECK pretend to be a MIPS compiler
MIPS_BUILTIN_DEFS := -D_MIPS_ISA_MIPS2=2 -D_MIPS_ISA=_MIPS_ISA_MIPS2 -D_ABIO32=1 -D_MIPS_SIM=_ABIO32 -D_MIPS_SZINT=32 -D_MIPS_SZPTR=32
ifneq ($(RUN_CC_CHECK),0)
#	The -MMD flags additionaly creates a .d file with the same name as the .o file.
	CC_CHECK          := $(CC_CHECK_COMP)
	CC_CHECK_FLAGS    := -MMD -MP -fno-builtin -fsyntax-only -fdiagnostics-color -std=gnu89 -m32 -DNON_MATCHING -DAVOID_UB -DCC_CHECK=1
	ifneq ($(WERROR), 0)
		CHECK_WARNINGS += -Werror
	endif
else
	CC_CHECK          := @:
endif

CFLAGS          += -nostdinc -fno-PIC -G 0 -mgp32 -mfp32 -fno-common

WARNINGS        := -w

ASFLAGS         := -march=vr4300 -mabi=32 -G0 -no-pad-sections
COMMON_DEFINES  := -D_MIPS_SZLONG=32 -D__USE_ISOC99
GBI_DEFINES     := -DF3DEX_GBI

ifeq ($(VERSION),usa)
	RELEASE_DEFINES :=
else ifeq ($(VERSION),eur)
	RELEASE_DEFINES := -DNDEBUG -D_FINALROM
else ifeq ($(VERSION),fra)
	RELEASE_DEFINES := -DNDEBUG -D_FINALROM
else ifeq ($(VERSION),ger)
	RELEASE_DEFINES := -DNDEBUG -D_FINALROM
endif

AS_DEFINES      := -DMIPSEB -D_LANGUAGE_ASSEMBLY -D_ULTRA64
C_DEFINES       := -D_LANGUAGE_C
ENDIAN          := -EB

OPTFLAGS        := -O2
OPTFLAGS        += -g
MIPS_VERSION    := -mips3
# ICONV_FLAGS     := --from-code=UTF-8 --to-code=Shift-JIS

# Variable to simplify C compiler invocation
C_COMPILER_FLAGS = $(CFLAGS) $(BUILD_DEFINES) $(IINC) $(WARNINGS) $(MIPS_VERSION) $(ENDIAN) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(C_DEFINES) $(OPTFLAGS)

# Use relocations and abi fpr names in the dump
OBJDUMP_FLAGS := --disassemble --reloc --disassemble-zeroes -Mreg-names=32 -Mno-aliases

ifneq ($(OBJDUMP_BUILD), 0)
	OBJDUMP_CMD = $(OBJDUMP) $(OBJDUMP_FLAGS) $@ > $(@:.o=.dump.s)
else
	OBJDUMP_CMD = @:
endif

ifneq ($(COMPILER_VERBOSE), 0)
	COMP_VERBOSE_FLAG := -v
else
	COMP_VERBOSE_FLAG :=
endif


#### Files ####

$(shell mkdir -p asm/$(VERSION) bin/$(VERSION)/assets linker_scripts/$(VERSION)/auto)

ASSETS_DIRS   := $(shell find bin/$(VERSION)/assets -type d)
SRC_DIRS      := $(shell find src -type d)
ASM_DIRS      := $(shell find asm/$(VERSION) -type d -not -path "asm/$(VERSION)/nonmatchings/*")
BIN_DIRS      := $(shell find bin/$(VERSION) -type d)

PNG_FILES     := $(foreach dir,$(ASSETS_DIRS),$(wildcard $(dir)/*.png))

BINFILE_DIR   := bin/$(VERSION)/bin_file

BINFILE_FILES := $(shell find $(BINFILE_DIR) -type f)

ARCHIVE_FILES := $(BUILD_DIR)/bin/$(VERSION)/bin_file.archive

C_FILES       := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES       := $(foreach dir,$(ASM_DIRS) $(SRC_DIRS),$(wildcard $(dir)/*.s))
O_FILES       := $(foreach f,$(C_FILES:.c=.o),$(BUILD_DIR)/$f) \
                 $(foreach f,$(S_FILES:.s=.o),$(BUILD_DIR)/$f)


PNG_INC_FILES := $(foreach f,$(PNG_FILES:.png=.inc),$(BUILD_DIR)/$f)

SEGMENTS_SCRIPTS := $(wildcard linker_scripts/$(VERSION)/partial/*.ld)
SEGMENTS_D       := $(SEGMENTS_SCRIPTS:.ld=.d)
SEGMENTS         := $(foreach f, $(SEGMENTS_SCRIPTS:.ld=), $(notdir $f))
SEGMENTS_O       := $(foreach f, $(SEGMENTS), $(BUILD_DIR)/segments/$f.o)

LINKER_SCRIPTS   := $(LD_SCRIPT) $(BUILD_DIR)/linker_scripts/hardware_regs.ld $(BUILD_DIR)/linker_scripts/libultra_syms.ld $(BUILD_DIR)/linker_scripts/$(VERSION)/undefined_syms.ld $(BUILD_DIR)/linker_scripts/common_undef_syms.ld


# Automatic dependency files
DEP_FILES := $(LD_SCRIPT:.ld=.d) $(SEGMENTS_D)

ifneq ($(DEP_ASM), 0)
	DEP_FILES += $(O_FILES:.o=.asmproc.d)
endif

ifneq ($(DEP_INCLUDE), 0)
	DEP_FILES += $(O_FILES:.o=.d)
endif

# create build directories
$(shell mkdir -p $(BUILD_DIR)/linker_scripts/$(VERSION) $(BUILD_DIR)/segments)
$(shell mkdir -p $(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(BUILD_DIR)/$(dir)))


# directory flags

# per-file flags

$(BUILD_DIR)/src/bin_file/bin_file.o: $(ARCHIVE_FILES)


#### Main Targets ###

all: $(ROM)
ifneq ($(COMPARE),0)
	@md5sum $(ROM)
	@md5sum -c $(TARGET).$(VERSION).md5
endif

clean:
	$(RM) -r $(BUILD_DIR)/asm $(BUILD_DIR)/bin $(BUILD_DIR)/src $(ROM) $(BIN) $(ELF)

distclean: clean
	$(RM) -r $(BUILD_DIR) asm/ bin/ .splat/
	$(RM) -r linker_scripts/$(VERSION)/auto $(LD_SCRIPT)

setup:
	$(MAKE) -C tools

extract:
	$(RM) -r asm/$(VERSION) bin/$(VERSION)
	$(SPLAT) $(SPLAT_YAML)

diff-init: all
	$(RM) -rf expected/$(BUILD_DIR)
	mkdir -p expected/$(BUILD_DIR)
	cp -r $(BUILD_DIR)/* expected/$(BUILD_DIR)

init:
	$(MAKE) distclean
	$(MAKE) setup
	$(MAKE) extract
	$(MAKE) all
	$(MAKE) diff-init

format:
	clang-format-11 -i -style=file $(C_FILES)

tidy:
	clang-tidy-11 -p . --fix --fix-errors $(C_FILES) -- $(CC_CHECK_FLAGS) $(IINC) $(CHECK_WARNINGS) $(BUILD_DEFINES) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(C_DEFINES) $(MIPS_BUILTIN_DEFS)

.PHONY: all clean distclean setup extract diff-init init format tidy
.DEFAULT_GOAL := all
# Prevent removing intermediate files
.SECONDARY:


#### Various Recipes ####

$(ROM): $(BIN)
	$(OBJCOPY) -I binary -O binary --pad-to=0x2000000 --gap-fill=0xFF $< $(@:.z64=.bin_no_checksum)
	$(CHECKSUMMER) $(@:.z64=.bin_no_checksum) $@

# Copy without pad-to to fill the gaps with zeroes
$(BIN): $(ELF)
	$(OBJCOPY) -O binary --gap-fill=0x00 $< $@

$(ELF): $(LINKER_SCRIPTS)
	$(file >$(BUILD_DIR)/o_files, $(filter %.o, $^))
	$(LD) $(ENDIAN) $(LDFLAGS) -Map $(LD_MAP) $(foreach ld, $(LINKER_SCRIPTS), -T $(ld)) -o $@ @$(BUILD_DIR)/o_files

## Order-only prerequisites
# These ensure e.g. the PNG_INC_FILES are built before the O_FILES.
# The intermediate phony targets avoid quadratically-many dependencies between the targets and prerequisites.

asset_files: $(PNG_INC_FILES)
$(O_FILES): | asset_files

.PHONY: asset_files


$(BUILD_DIR)/%.ld: %.ld
	$(CPP) $(CPPFLAGS) $(BUILD_DEFINES) $(IINC) $(COMP_VERBOSE_FLAG) $< > $@

%.archive: $(BINFILE_FILES)
	./tools/package_bin_file.py $(BINFILE_DIR) $@

$(BUILD_DIR)/%.o: %.s
	$(CPP) $(CPPFLAGS) $(BUILD_DEFINES) $(IINC) -I $(dir $*) -I $(BUILD_DIR)/$(dir $*) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(AS_DEFINES) $(COMP_VERBOSE_FLAG) $< | $(AS) $(ASFLAGS) $(ENDIAN) $(IINC) -I $(dir $*) $(COMP_VERBOSE_FLAG) -o $@
	$(OBJDUMP_CMD)

$(BUILD_DIR)/%.o: %.c
	$(CC_CHECK) $(CC_CHECK_FLAGS) $(IINC) -I $(dir $*) -I $(BUILD_DIR)/$(dir $*) $(CHECK_WARNINGS) $(BUILD_DEFINES) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(C_DEFINES) $(MIPS_BUILTIN_DEFS) -o $@ $<
ifeq ($(MULTISTEP_BUILD), 0)
	$(CC) $(C_COMPILER_FLAGS) -I $(dir $*) -I $(BUILD_DIR)/$(dir $*) $(COMP_VERBOSE_FLAG) -E $< | $(CC) -x c $(C_COMPILER_FLAGS) -I $(dir $*) -c $(COMP_VERBOSE_FLAG) -o $@ -
else
	$(CC) $(C_COMPILER_FLAGS) -I $(dir $*) -I $(BUILD_DIR)/$(dir $*) $(COMP_VERBOSE_FLAG) -E $< -o $(@:.o=.i)
	$(CC) $(C_COMPILER_FLAGS) -I $(dir $*) -I $(BUILD_DIR)/$(dir $*) $(COMP_VERBOSE_FLAG) -S -o $(@:.o=.s) $(@:.o=.i)
	$(CC) $(C_COMPILER_FLAGS) -I $(dir $*) -I $(BUILD_DIR)/$(dir $*) $(COMP_VERBOSE_FLAG) -c -o $@ $(@:.o=.s)
endif
	$(STRIP) $@ -N dummy-symbol-name
	$(OBJDUMP_CMD)


# Make inc files from assets

$(BUILD_DIR)/%.inc: %.png
	$(PIGMENT64) to-bin --c-array --format $(subst .,,$(suffix $*)) -o $@ $<


-include $(DEP_FILES)

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
