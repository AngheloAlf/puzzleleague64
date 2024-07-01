MAKEFLAGS += --no-builtin-rules


# Set prefix to mips binutils binaries (mips-linux-gnu-ld => 'mips-linux-gnu-') - Change at your own risk!
# In nearly all cases, not having 'mips-linux-gnu-*' binaries on the PATH is indicative of missing dependencies
CROSS ?= mips-linux-gnu-

### Output ###

BUILD_DIR := ../build/$(VERSION)/lib


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

MAKE = make

UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	DETECTED_OS := windows
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := macos
	MAKE := gmake
endif

#### Tools ####
ifneq ($(shell type $(CROSS)ld >/dev/null 2>/dev/null; echo $$?), 0)
	$(error Please install or build $(CROSS))
endif

WORKING_DIR     := $(shell pwd)


COMPILER_DIR    := ../tools/gcc_kmc/$(DETECTED_OS)/2.7.2
CC              := COMPILER_PATH=$(WORKING_DIR)/$(COMPILER_DIR) $(WORKING_DIR)/$(COMPILER_DIR)/gcc


IINC            := -I $(WORKING_DIR)/ultralib/include -I $(WORKING_DIR)/ultralib/include/gcc -I $(WORKING_DIR)/ultralib/include/PR -I $(WORKING_DIR)/ultralib/src

CFLAGS          := -nostdinc -fno-PIC -G 0 -mgp32 -mfp32 -mabi=32
CFLAGS          += -funsigned-char
MIPS_VERSION    := -mips3
WARNINGS        := -w
COMMON_DEFINES  := -D_MIPS_SZLONG=32 -D__USE_ISOC99
GBI_DEFINES     := -DF3DEX_GBI
# RELEASE_DEFINES := -DNDEBUG -D_FINALROM
RELEASE_DEFINES :=
AS_DEFINES      := -D_LANGUAGE_ASSEMBLY -DMIPSEB -D_ULTRA64 -D_MIPS_SIM=1
C_DEFINES       := -D_LANGUAGE_C
# libultra 2.0J
LIBULTRA_VERSION:= 7

ifeq ($(VERSION),$(filter $(VERSION), usa eur fra))
OPTFLAGS        := -O0
DBGFLAGS        :=
RELEASE_DEFINES := -D_DEBUG
else ifeq ($(VERSION),ger)
OPTFLAGS        := -O3
DBGFLAGS        :=
RELEASE_DEFINES := -DNDEBUG
endif

BUILD_DEFINES   += -DBUILD_VERSION=$(LIBULTRA_VERSION)

#### Files ####

SRC_DIRS      := $(shell find ultralib/src -type d -not -path "ultralib/src/voice")

C_FILES       := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES       := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.s))
O_FILES       := $(foreach f,$(C_FILES:.c=.o),$(BUILD_DIR)/$f) \
                 $(foreach f,$(S_FILES:.s=.o),$(BUILD_DIR)/$f)

# create build directories
$(shell mkdir -p $(foreach dir,$(SRC_DIRS),$(BUILD_DIR)/$(dir)))


# directory flags

# per-file flags


#### Main Targets ###

all: $(O_FILES)

clean:
	$(RM) -r $(BUILD_DIR)/lib

distclean: clean

.PHONY: all clean distclean
.DEFAULT_GOAL := all
# Prevent removing intermediate files
.SECONDARY:

$(BUILD_DIR)/%.o: %.s
	cd $(<D) && $(CC) -c $(IINC) -I $(dir $*) $(WARNINGS) $(BUILD_DEFINES) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(AS_DEFINES) $(CFLAGS) $(MIPS_VERSION) -x assembler-with-cpp -o $(WORKING_DIR)/$@ $(<F)

$(BUILD_DIR)/%.o: %.c
	cd $(<D) && $(CC) -c $(IINC) -I $(dir $*) $(WARNINGS) $(BUILD_DEFINES) $(COMMON_DEFINES) $(RELEASE_DEFINES) $(GBI_DEFINES) $(C_DEFINES) $(CFLAGS) $(MIPS_VERSION) $(OPTFLAGS) $(DBGFLAGS) -o $(WORKING_DIR)/$@ $(<F)
