#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>
#include "stdio.c"

#define FORMAT_LENGTH       1
#define NORMAL              0
#define STATE_SHORT         2
#define STATE_LONG          3
#define FORMAT_SPECIFIER    1

#define LENGTH_DEFAULT      0
#define LENGTH_SHORT_SHORT  1
#define LENGTH_SHORT        2
#define LENGTH_LONG         3
#define LENGTH_LONG_LONG    4

/* 
    printf()
    params:
        string
        arguments
    
    available format specifiers:
        {i}, {d} - interger
        {s}      - string
        {c}      - char
        {k}      - color
 */
int printf(const char *format_string, ...){

    int state = NORMAL;
    va_list a_list;
    va_start(a_list, format_string);
    for(int i = 0; i < strlen(format_string); i++){
        char current = format_string[i]; // current char in string
        switch (state){
            case NORMAL:
                switch (current) {
                    case '{':
                        state = FORMAT_SPECIFIER;
                        break;
                    default:
                        terminal_putchar(current);
                        break;                     
                }
                break;
            case FORMAT_SPECIFIER:
                switch (current) {
                    case 'n':
                        terminal_puts("\n");
                        break;
                    case 'k':
                        terminal_color = (va_arg(a_list, int));
                        break;
                    case 'd':
                    case 'i':
                        //terminal_puti((va_arg(a_list, int)));
                    case 's':
                        terminal_puts(va_arg(a_list, char*));
                        break;
                    case 'c':
                        ;
                        int ch = va_arg(a_list, int);
                        terminal_putchar(ch);
                        break;
                    case '}':
                        state = NORMAL;
                        break;

                }
                break;
        }

    }
    
    va_end(a_list);


    return 0;
}