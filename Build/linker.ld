
/*-----Initialization of stack------*/
_stack_start = ORIGIN(RAM) + LENGTH(RAM);
_Stack_Size  = 1024;
_Stack_Limit = _stack_start - _Stack_Size;

/*-----Initialization of heap------*/
_Heap_Start  = _end_noinit;
_Healp_limit = _stack_start - _Stack_Size;

/*---------Entry Point----------*/
ENTRY(Reset_Handler)

MEMORY
{
	RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 128K
/*  	CCMRAM (xrw) : ORIGIN = 0x10000000, LENGTH = 64K */
  	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
}

SECTIONS
{	
	.isr_vector : ALIGN(4)
	{
		FILL(0xFF)
		__vectors_start = ABSOLUTE(.);
		KEEP(*(.isr_vector))
	} >FLASH
	
	.text : ALIGN(4)
	{
		*(.text .text.*)
		*(.rodata .rodata.* .constdata .constdata.*)
	} >FLASH
	
	_sidata = LOADADDR(.data);
	
	.data : ALIGN(4)
	{
		_sdata = .;
		*(.data_begin .data_begin.*)
		*(.data .data.*)
		*(.data_end .data_end.*)
	    . = ALIGN(4);
		_edata = .;
	
	} >RAM AT>FLASH
	
	.bss (NOLOAD) : ALIGN(4)
	{
		__bss_start__ = .; 
		_sbss = .;
		*(.bss_begin .bss_begin.*)
		*(.bss .bss.*)
		*(COMMON)
		
		*(.bss_end .bss_end.*)
	    . = ALIGN(4);
		_ebss = .;
		__bss_end__ = .;
	} >RAM
	
	.noinit (NOLOAD) : ALIGN(4)
	{
        _noinit = .;
        
        *(.noinit .noinit.*) 
        
         . = ALIGN(4) ;
        _end_noinit = .; 
	} >RAM
}

PROVIDE ( end = _end_noinit ); /* was _ebss */
PROVIDE ( _end = _end_noinit );
PROVIDE ( __end = _end_noinit );
PROVIDE ( __end__ = _end_noinit );
    




