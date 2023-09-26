#include "printf.h"
#include "stdio.h"

/* 
    kernel_msg() 

    params:
        type:
        - i - info
        - e - error
        - w - warning
        - s - success
 */



void kernel_msg(char type, char* message){
    switch (type) {
        case 'i':
            printf("[{ksk}] {s}{n}", VGA_COLOR_LIGHT_BLUE, "info", VGA_COLOR_WHITE, message);
            break;
        case 's':
            printf("[{ksk}] {s}{n}", VGA_COLOR_LIGHT_GREEN, "success", VGA_COLOR_WHITE, message);
            break;
        case 'e':
            printf("[{ksk}] {s}{n}", VGA_COLOR_LIGHT_RED, "error", VGA_COLOR_WHITE, message);
            break;
        case 'w':
            printf("[{ksk}] {s}{n}", VGA_COLOR_LIGHT_MAGENTA, "warn", VGA_COLOR_WHITE, message);
            break;
        break;
    }    

}        