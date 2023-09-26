
global asm_set_gdt
extern gdtp
asm_set_gdt:
    lgdt [gdtp]
    mov ax, 0x10    ; offset in GDT to data seg
    mov ds, ax
    mov es, ax
    mov gs ,ax
    mov fs, ax
    mov ss, ax
    jmp 0x08:flush2 ; far jump
flush2:
    ret             ; return to kernel

