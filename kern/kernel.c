
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "printf.c"
/* Hardware text mode color constants. */

 





void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
	char duck[5] = "Ilov";
	printf("Hello {s}", "There");

}