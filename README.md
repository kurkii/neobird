# ABANDONED
check my new [64 bit continuation](https://github.com/kurkii/neobird64)


# neobird
x86 32-bit kernel & operating system

# checklist
- [x] GDT
- [x] IDT 
- [ ] PICs
- [ ] Keyboard I/O

# how to compile
- get i386 cross compiler
- get grub
- `make all`

# how to run
from base directory
`qemu-system-i386 -cdrom build/neobird.iso`
  
  
