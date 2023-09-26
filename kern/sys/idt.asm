
global asm_idt_load
extern idtpr

asm_idt_load:
    lidt [idtpr]
    ret


