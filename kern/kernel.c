
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "printf.c"
#include "gdt.h"

void kernel_main(void) 
{
	gdt_init();
	/* Initialize terminal interface */
	terminal_initialize(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
	 
	printf("Hello {s}", "World");

}

