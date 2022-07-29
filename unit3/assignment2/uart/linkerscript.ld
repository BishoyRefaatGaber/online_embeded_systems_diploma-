ENTRY(reset)
MEMORY
{
	MEM (rwx): ORIGIN = 0X00000000 , LENGTH = 64M
}
 . = 0X10000;
SECTIONS
{
	.startup . :
	{
		startup.o (.text)
	}>MEM
	.text :
	{
		*(.text) 
	}>MEM
	.data :
	{
		*(.rodata)  *(.data)
	}>MEM
	.bss : 
	{
		*(.bss) *(COMMON)
	}>MEM
	. = . + 0x1000 ;
	stack_top = . ;
}