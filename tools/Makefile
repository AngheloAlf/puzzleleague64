MAKE = make


UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	DETECTED_OS := windows
	HOST_TRIPLE := x86_64-pc-windows-msvc
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
	HOST_TRIPLE := x86_64-unknown-linux-musl
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := mac
	MAKE := gmake
	CPPFLAGS += -xc++
	HOST_TRIPLE := x86_64-apple-darwin
endif


ifeq ($(DETECTED_OS),windows)
$(error This repo does not support compiling on native Windows yet, please use WSL instead.)
endif


KMC_DIR         := gcc_kmc/$(DETECTED_OS)/2.7.2
KMC_GCC         := $(KMC_DIR)/gcc
KMC_BINUTILS    := $(KMC_DIR)/as

IDO_53_DIR      := ido_recomp/$(DETECTED_OS)/5.3
IDO_53_CC       := $(IDO_53_DIR)/cc

SLINKY_DIR      := slinky
SLINKY          := $(SLINKY_DIR)/slinky-cli

PIGMENT64_DIR   := pigment64
PIGMENT64       := $(PIGMENT64_DIR)/pigment64

FIRST_DIFF      := rstools/target/release/first_diff
FIX_RELOCS      := rstools/target/release/fix_relocs


all: $(KMC_GCC) $(KMC_BINUTILS) $(IDO_53_CC) $(SLINKY) $(PIGMENT64) $(FIRST_DIFF) $(FIX_RELOCS)

clean:
	$(RM) -rf $(KMC_DIR) gcc_kmc $(IDO_53_DIR) ido_recomp $(SLINKY_DIR)

distclean: clean
	cargo clean --manifest-path rstools/Cargo.toml

.PHONY: all clean distclean

$(KMC_GCC): | $(KMC_DIR)
	wget https://github.com/decompals/mips-gcc-2.7.2/releases/latest/download/gcc-2.7.2-$(DETECTED_OS).tar.gz
	tar xf gcc-2.7.2-$(DETECTED_OS).tar.gz -C $(KMC_DIR)
	$(RM) gcc-2.7.2-$(DETECTED_OS).tar.gz

$(KMC_BINUTILS): | $(KMC_DIR)
	wget https://github.com/decompals/mips-binutils-2.6/releases/latest/download/binutils-2.6-$(DETECTED_OS).tar.gz
	tar xf binutils-2.6-$(DETECTED_OS).tar.gz -C $(KMC_DIR)
	$(RM) binutils-2.6-$(DETECTED_OS).tar.gz

$(IDO_53_CC): | $(IDO_53_DIR)
	wget https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-5.3-recomp-$(DETECTED_OS).tar.gz
	tar xf ido-5.3-recomp-$(DETECTED_OS).tar.gz -C $(IDO_53_DIR)
	$(RM) ido-5.3-recomp-$(DETECTED_OS).tar.gz

$(SLINKY): | $(SLINKY_DIR)
	wget https://github.com/decompals/slinky/releases/download/0.3.0/slinky-cli-$(HOST_TRIPLE).tar.gz
	tar xf slinky-cli-$(HOST_TRIPLE).tar.gz -C $(SLINKY_DIR)
	$(RM) slinky-cli-$(HOST_TRIPLE).tar.gz

$(PIGMENT64): | $(PIGMENT64_DIR)
	wget https://github.com/decompals/pigment64/releases/download/0.6.3/pigment64-$(HOST_TRIPLE).tar.gz
	tar xf pigment64-$(HOST_TRIPLE).tar.gz -C $(PIGMENT64_DIR)
	$(RM) pigment64-$(HOST_TRIPLE).tar.gz

$(FIRST_DIFF) $(FIX_RELOCS): rstools/Cargo.toml
	cargo build --release --manifest-path rstools/Cargo.toml

$(KMC_DIR) $(IDO_53_DIR) $(SLINKY_DIR) $(PIGMENT64_DIR):
	mkdir -p $@

-include $(FIRST_DIFF).d $(FIX_RELOCS).d
