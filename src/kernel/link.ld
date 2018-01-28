ENTRY(kmain)
SECTIONS
{
	. = 0x10000;
	.text BLOCK(4K) : ALIGN(4K) {
		*(.multiboot) 

		*(.text)
		*(.rodata)
		*(.bootstrap_stack)
	}

	/* Kernel construictor function pointer table */
	kconstructor_first = .;
	kconstructor_pointers : { *(kconstructor_pointers) }
	kconstructor_last = .;
	kconstructor_code     : { *(kconstructor_code)     } 

	.rodata            BLOCK(4K) : ALIGN(4K) { *(.rodata)            }
	.data              BLOCK(4K) : ALIGN(4K) { *(.data)              }

	.bss : {
		*(.bss)
		*(.bootstrap_stack)
	}

	stack_bottom = .;
	.stack BLOCK(4K) : {}
	stack_top = .;

	.else : { *(.*) }

	end = .;


}


