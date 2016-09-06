OUTPUT_ARCH(i386)
ENTRY(_start)
SECTIONS
{
	. = 0x00100000;

    .text   :
	{
		*(.text .text.*)
        *(.rodata .rodata.*)
        _etext = .;
	}

    .data   :
	{
		*(.data .data.*)
		*(.tdata .tdata.*)
		_edata = .;
	}

    .bss    :
	{
		*(.bss .bss.*)
		*(.tss .tss.*)
		*(COMMON)
		_end = . ;
	}

	PROVIDE (end = .);


	/* Discard comment and note (but not debugging) sections.  Some
	* versions of GNU ld would otherwise automatically place the
	* ".note.gnu.build-id" section before _start!  */
	/DISCARD/ : {
    *(.comment .comment.* .note .note.*)
    }
}
