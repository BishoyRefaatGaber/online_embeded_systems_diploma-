#@BIRG16
CC=arm-none-eabi-
CFLAGS=-c -mcpu=cortex-m3 -g 
INCS=-I .
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)	
Project_Name=learn_in_depth
learn_in_depth:learn_in_depth.bin
		@echo "=====Done====="
		
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -mthumb  $< -o $@


%.o: %.s
	$(CC)as.exe $(CFLAGS) $(INCS) $< -o $@


$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T $(OBJ) $(ASOBJ) linkerscript.ld -o $@ 
	

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy -O $<  $@


clean_all:
	rm *.bin *.map *.o *.elf