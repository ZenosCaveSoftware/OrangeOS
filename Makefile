MODULES = LibOC Orange
ARCH ?= i686

CFLAGS += -IOrange/include \
          -ILibOC/include \
          -O3 \
		  -ffreestanding \
		  -fno-common \
		  -fpic \
		  -nostdlib \
		  -nodefaultlibs \
		  -nostartfiles \
		  -std=c11 \
		  -DNDEBUG


ARCHDIR := Orange/arch/$(ARCH)

PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

KNLSRC  :=
LIBSRC  :=
BOOTSRC := Clementine/arch/$(ARCH)/Stage1/Stage1.asm
LDRSRC  := Clementine/arch/$(ARCH)/Stage2/Stage2.asm
LIBS	:=

include $(patsubst %,\
	%/module.mk,$(MODULES))

include $(ARCHDIR)/flags.mk

KNLOBJ :=								\
		$(patsubst %.c,build/%.c.o,		\
			$(filter %.c,$(KNLSRC)))	\
		$(patsubst %.S,build/%.S.o,		\
			$(filter %.S,$(KNLSRC)))	\
		$(patsubst %.asm,build/%.asm.o,	\
   			$(filter %.asm,$(KNLSRC)))

LIBOBJ :=								\
		$(patsubst %.c,build/%.c.o,		\
			$(filter %.c,$(LIBSRC)))	\
		$(patsubst %.S,build/%.S.o,		\
			$(filter %.S,$(LIBSRC)))	\
		$(patsubst %.asm,build/%.asm.o, \
			$(filter %.asm,$(KNLSRC)))


all: build/Boot.bin build/KRNLDR.SYS build/KRNL.SYS

.PHONY: all clean

build/Boot.bin:
	$(NASM) -i Clementine/arch/$(ARCH)/inc/ -f bin $(BOOTSRC) -o $@
	@echo "--- BOOT Stage1 BUILT ---"

build/KRNLDR.SYS:
	$(NASM) -i Clementine/arch/$(ARCH)/inc/ -f bin $(LDRSRC) -o $@
	@echo "--- LOADER Stage2 BUILT ---"

build/KRNL.SYS: $(KNLOBJ) $(LIBOBJ) $(ARCHDIR)/linker.ld
	@echo $(shell echo "Linking: $(KNLSRC)$(LIBSRC)" | sed 's/\s+/ /')
	$(CC) -Wl,--build-id=none -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) -gc-sections $(KNLOBJ) $(LIBOBJ) $(LIBS) 2>&1 |tee log/$@.log
	@echo "--- KERNEL LINKED ---"

build/%.c.o: %.c
	$(CC) -c $< -o $@ -std=c11 $(CFLAGS) 2>&1 | tee log/$(shell basename $@ .o).log
	@echo "--- COMPILED $(shell basename $<) ---"

build/%.S.o: %.S
	$(CC) -c $< -o $@ $(CFLAGS) 2>&1 | tee log/$(shell basename $@ .o).log
	@echo "--- ASSEMBLED $(shell basename $<) ---"

build/%.asm.o: %.asm
	$(NASM) -f elf $< -o $@ 2>&1 | tee log/$(shell basename $@ .o).log
	@echo "--- ASSEMBLED $(shell basename $<) ---"

clean:
	find build -name "*.o" -exec rm {} \;
	find build -name "*.d" -exec rm {} \;
	@echo "--- CLEANED DIRS ---"