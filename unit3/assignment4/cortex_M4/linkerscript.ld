MEMORY
{
	flash(RX) : ORIGIN = 0X00000000, LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}
SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		_E_text = .;
	}> flash
	.data : {
		_S_DATA = .;
		*(.data*)
		*(.rodata)
		. = ALIGN(4);
		_E_DATA = .;
	}> sram AT> flash
	.bss : {
		_S_bss = .;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = .;
	}> sram
}