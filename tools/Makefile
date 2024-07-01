MAKE = make


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


ifeq ($(DETECTED_OS),windows)
$(error This repo does not support compiling on native Windows yet, please use WSL instead.)
endif


KMC_DIR         := gcc_kmc/$(DETECTED_OS)/2.7.2
KMC_GCC         := $(KMC_DIR)/gcc
KMC_BINUTILS    := $(KMC_DIR)/as

IDO_53_DIR      := ido_recomp/$(DETECTED_OS)/5.3
IDO_53_CC       := $(IDO_53_DIR)/cc


all: $(KMC_GCC) $(KMC_BINUTILS) $(IDO_53_CC)

clean:
	$(RM) -rf $(KMC_DIR) gcc_kmc $(IDO_53_DIR) ido_recomp

distclean: clean

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

$(KMC_DIR):
	mkdir -p $@

$(IDO_53_DIR):
	mkdir -p $@
