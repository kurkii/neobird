#include <stdint.h>

typedef struct
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_mid;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed, aligned(4))) gdtentry;

typedef struct
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) gdtptr;

void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_init();
