#include "idt.h"
#include "../include/kernmsg.h"
void exception_handler() {
    kernel_msg('e', "Oh noes!!!");
    __asm__ volatile ("cli; hlt"); // Completely hangs the computer
    for(;;);                       // Extra measure so the compiler wont complain
}