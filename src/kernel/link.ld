ENTRY(kmain)
SECTIONS
{
	. = 0x10000;

	.text : {
		*(.multiboot)
		*(.text);
		*(.rodata)
		*(.bootstrap_stack)
	}

	/* Kernel construictor function pointer table */
	kconstructor_first = .;
	kconstructor_pointers : { *(kconstructor_pointers) }
	kconstructor_last = .;
	kconstructor_code     : { *(kconstructor_code)     } 

	.data : {
		*(.data)
	}

	.bss : {
		*(.bss)
	}

	end = .;
}


