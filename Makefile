BUILD_DIR = build
KERN = kern
ISO_DIR = iso/boot

all:

	
	# remove previous build of the iso (if exists) as mkrescue does not overwrite it
	rm -f $(BUILD_DIR)/neobird.iso 	

	# make build directory
	mkdir -p $(BUILD_DIR)

	# build & link boot and kernel files
	# asm goes first:

	i386-elf-as boot/boot.asm -o $(BUILD_DIR)/boot.o
	nasm -f elf32 $(KERN)/sys/gdt.asm -o $(BUILD_DIR)/gdt.asm.o
	nasm -f elf32 $(KERN)/sys/idt.asm -o $(BUILD_DIR)/idt.asm.o
	nasm -f elf32 $(KERN)/sys/isr.asm -o $(BUILD_DIR)/isr.asm.o


	i386-elf-gcc -c $(KERN)/kernel.c -o $(BUILD_DIR)/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c $(KERN)/sys/gdt.c -o $(BUILD_DIR)/gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c $(KERN)/sys/idt.c -o $(BUILD_DIR)/idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c $(KERN)/sys/isr.c -o $(BUILD_DIR)/isr.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

	i386-elf-gcc -c $(KERN)/include/kernmsg.c -o $(BUILD_DIR)/kernmsg.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c $(KERN)/include/string.c -o $(BUILD_DIR)/string.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra


	i386-elf-gcc -T linker.ld -o $(BUILD_DIR)/neobird.bin -ffreestanding -O2 -nostdlib $(BUILD_DIR)/*.o  -lgcc

	# create iso/boot directory
	mkdir -p $(ISO_DIR)
	mkdir -p $(ISO_DIR)/grub

	# copy everything to the iso directory to be used by mkrescue
	cp $(BUILD_DIR)/neobird.bin iso/boot/neobird.bin
	cp boot/grub/grub.cfg iso/boot/grub/grub.cfg

	# make the iso file
	@grub-mkrescue -o $(BUILD_DIR)/neobird.iso iso > /dev/null 2>&1