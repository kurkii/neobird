#include "string.h"
#include <stddef.h>

void *memset(void *ptr, int value, size_t num){
    unsigned char* ptr_byte = (unsigned char*)ptr;

   for (size_t i = 0; i < num; ptr_byte[i] = (unsigned char)value, i++);   
   return ptr;
}