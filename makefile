AS=nasm
CC=gcc
LD=ld
CFLAGS=-ffreestanding -m32 -nostdlib -fno-pie -fno-stack-protector
LDFLAGS=-Ttext=0x0000 --oformat binary

BIN=bin
SRC=src

prepare:
	mkdir -p $(BIN)
	dd if=/dev/zero of=$(BIN)/floppy.img bs=512 count=2880

bootloader:
	$(AS) $(SRC)/bootloader.asm -f bin -o $(BIN)/bootloader.bin

stdlib:
	$(CC) $(CFLAGS) -c $(SRC)/std_lib.c -o $(BIN)/std_lib.o

shell:
	$(CC) $(CFLAGS) -c $(SRC)/shell.c -o $(BIN)/shell.o

kernel:
	$(CC) $(CFLAGS) -c $(SRC)/kernel.c -o $(BIN)/kernel.o
	nasm $(SRC)/kernel.asm -f elf -o $(BIN)/kernel_asm.o

link:
	$(LD) $(LDFLAGS) -o $(BIN)/kernel.bin $(BIN)/kernel.o $(BIN)/kernel_asm.o $(BIN)/std_lib.o $(BIN)/shell.o
	cat $(BIN)/bootloader.bin $(BIN)/kernel.bin > $(BIN)/floppy.img

build: prepare bootloader stdlib shell kernel link
