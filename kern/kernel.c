
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "include/printf.c"
#include "include/kernmsg.h"
#include "sys/gdt.h"
#include "sys/idt.h"

void kernel_main(void) 
{
	terminal_initialize(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	printf("{k}Neobird v1.0{kn}", VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_WHITE);
	kernel_msg('i', "Loading GDT");
	gdt_init();
	kernel_msg('s', "GDT Loaded");
	kernel_msg('i', "Loading IDT");
	idt_init();
	kernel_msg('s', "IDT Loaded");

	/* Initialize terminal interface */

}

