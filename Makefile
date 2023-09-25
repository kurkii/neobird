all:
	# remove previous build of the iso as mkrescue does not overwrite it
	rm -f build/neobird.iso 	

	# build & link boot and kernel files
	i386-elf-as boot/boot.asm -o build/boot.o
	nasm -f elf32 kern/gdt.asm -o build/gdt.asm.o
	i386-elf-gcc -c kern/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -c kern/gdt.c -o build/gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	i386-elf-gcc -T linker.ld -o build/neobird.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o build/gdt.o build/gdt.asm.o  -lgcc

	# copy everything to the iso directory to be used by mkrescue
	cp build/neobird.bin iso/boot/neobird.bin
	cp boot/grub/grub.cfg iso/boot/grub/grub.cfg

	# make the iso file
	@grub-mkrescue -o build/neobird.iso iso > /dev/null 2>&1