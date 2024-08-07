#ifndef GDT_H
#define GDT_H

#define SEGMENTATION_GDT_ENTRYS		6
#define KERNEL_NULL_SEL				0x00
#define KERNEL_CODE_SEL				0x08
#define KERNEL_DATA_SEL				0x10
#define USER_CODE_SEL				0x18
#define USER_DATA_SEL				0x20
#define KERNEL_TSS_SEL				0x28


typedef struct tss_entry
{
   uint32_t prev_tss;   // The previous TSS - if we used hardware task switching this would form a linked list.
   uint32_t esp0;       // The stack pointer to load when we change to kernel mode.
   uint32_t ss0;        // The stack segment to load when we change to kernel mode.
   uint32_t esp1;       // Unused
   uint32_t ss1;
   uint32_t esp2;
   uint32_t ss2;
   uint32_t cr3;
   uint32_t eip;
   uint32_t eflags;
   uint32_t eax;
   uint32_t ecx;
   uint32_t edx;
   uint32_t ebx;
   uint32_t esp;
   uint32_t ebp;
   uint32_t esi;
   uint32_t edi;
   uint32_t es;         // The value to load into ES when we change to kernel mode.
   uint32_t cs;         // The value to load into CS when we change to kernel mode.
   uint32_t ss;         // The value to load into SS when we change to kernel mode.
   uint32_t ds;         // The value to load into DS when we change to kernel mode.
   uint32_t fs;         // The value to load into FS when we change to kernel mode.
   uint32_t gs;         // The value to load into GS when we change to kernel mode.
   uint32_t ldt;        // Unused...
   uint16_t trap;
   uint16_t iomap_base;
} __attribute__((packed)) tss_entry_t;

void gdt_setup(void);
void gdt_flush(uint32_t);
void tss_flush();

void set_kernel_stack(uint32_t stack);

#endif