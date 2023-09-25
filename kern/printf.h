#include <stdarg.h>
#include <stddef.h>

int printf(const char *format_string, ...);


typedef int (*pfnStreamWriteBuf)(char*);
 
struct Stream {
    size_t buf_len;
    size_t buf_i;
    char *buf;
    pfnStreamWriteBuf pfn_write_all;
};
