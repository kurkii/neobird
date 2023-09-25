#include <stdint.h>
#include "gdt.h"

extern void set_gdt();


gdtentry gdt[3];

gdtptr gdtp;

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{

    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_mid = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_init(){

    gdtp.limit = (sizeof(gdtentry) * 3 ) - 1;
    gdtp.base = (uint32_t)&gdt;

    gdt_set_gate(0, 0, 0, 0, 0); // null descriptor

    gdt_set_gate(1, 0, 0x003FFFFF, 0x9A, 0xCF); // code segment

    gdt_set_gate(2, 0, 0x003FFFFF, 0x92, 0xCF); // data segment

    set_gdt();
}

