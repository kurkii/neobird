#include "stdint.h"

typedef struct {
    uint16_t offset1;       // first 16 bits of offset
    uint16_t segselector;   // segment selector, points to code segment in GDT / kernel segment
    uint8_t reserved;       // 8bit unused zero region used for nefarious reasons by the CPU
    uint8_t type;           // stores the: 4 bit gate type - the type of gate this descriptor represents, the 2 bit DPL - defines which rings can access this interrupt and P - 1 bit which is always set to 1.
    uint16_t offset2;       // last 16 bits of offset
}  __attribute__((packed)) idtentry;

typedef struct{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_r;

extern void *isr_stub_table[];
__attribute__((noreturn)) void exception_handler(void);

void idt_set_gate(unsigned char num, unsigned long base, unsigned char type);
void idt_init(void);
extern void asm_idt_load();




