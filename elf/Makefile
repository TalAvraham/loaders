# The loader (main) needs to be position-independent, otherwise the loader and the file to
# load (dummy) would be loaded onto the same offset => crash!
# If it can not be position-independent (say you're compiling with an antique toolchain
# which does not support -static-pie) then it can be set to be loaded at a different address
# using the linker -Ttext-segment option.

ARM_TOOLCHAIN_PREFIX=/home/user/cross-compilers/armv5-eabi--uclibc--stable/bin/arm-linux-
ARM_TOOLCHAIN_CC=$(ARM_TOOLCHAIN_PREFIX)gcc
BIN_DIR=./bin

all: build test

build:
	@echo "============ Building ============"
	gcc -DOS_LINUX -DARCH_X86_64 elf.c main.c -o $(BIN_DIR)/loader_x64 -static -g3 -O0 -Wl,-Ttext-segment=0x800000
	gcc dummy.c -o $(BIN_DIR)/dummy_x64 -static -g3
	$(ARM_TOOLCHAIN_CC) -DOS_LINUX -DARCH_ARMEL elf.c main.c -o $(BIN_DIR)/loader_arm -static -g3 -O0 -Wl,-Ttext-segment=0x800000
	$(ARM_TOOLCHAIN_CC) dummy.c -o $(BIN_DIR)/dummy_arm -static -g3
	@echo "============== Done ==============\n"

test:
	@echo "======= Running basic test ======="
	$(BIN_DIR)/loader_x64 $(BIN_DIR)/dummy_x64 Hello World!
	$(BIN_DIR)/loader_arm $(BIN_DIR)/dummy_arm Hello World!
	@echo "============== Done =============="


clean:
	rm bin/*

