# The loader (main) needs to be position-independent, otherwise the loader and the file to
# load (dummy) would be loaded onto the same offset => crash!
# If it can not be position-independent (say you're compiling with an antique toolchain
# which does not support -static-pie) then it can be set to be loaded at a different address
# using the linker -Ttext-segment option.
all: build test

build:
	@echo "============ Building ============"
	gcc -DOS_LINUX -DARCH_X86_64 elf.c main.c -o main_64 -static -g3 -Wl,-Ttext-segment=0x800000
	gcc dummy.c -o dummy_64 -static -g3
	@echo "============== Done ==============\n"

test:
	@echo "======= Running basic test ======="
	./main_64 dummy_64 Hello World!
	@echo "============== Done =============="


clean:
	rm main_64 dummy_64

# Test with:
# ./main_64 ./dummy_64

