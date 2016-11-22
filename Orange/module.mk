KNLSRC += $(shell find Orange/arch/$(ARCH)/ -name '*.c') \
$(shell find Orange/arch/$(ARCH)/ -name '*.S') \
$(shell find Orange/arch/$(ARCH)/ -name '*.asm') \
$(shell find Orange/common/ -name '*.c') \
$(shell find Orange/common/ -name '*.S') \
$(shell find Orange/common/ -name '*.asm')