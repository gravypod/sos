#include <kernel/kconstructor.h>

#define ALIGN     (1<<0)
#define MEMINFO   (1<<1)
#define FLAGS     (ALIGN | MEMINFO)
#define MAGIC     (0x1BADB002)
#define CHECKSUM -(MAGIC + FLAGS)


/* Define multiboot header values to validate */
struct mflags {
	unsigned long magic;
	unsigned long flags;
	unsigned long checksum;
};

struct mflags flags __attribute__((unused, aligned(4), __section__(".multiboot"))) = {
	.magic    = MAGIC,
	.flags    = FLAGS,
	.checksum = CHECKSUM
};


extern void *stack_top, *stack_bottom;

void kmain()
{
	asm (
		"mov %0, %%esp"
		: /* out */
		: /* in  */ "r"(stack_top)
		: "%esp"
	);



	volatile unsigned char *videoram = (unsigned char *) 0xB8000;
	videoram[0] = 65;
	videoram[1] = 0x07;

	asm("hlt");
}
