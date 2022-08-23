CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS  = $(wildcard *.s)
ASOBJ = $(AS:.s=.o) 	
project = learn_in_depth
ALL:$(project).bin $(project).hex
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
%.o: %.s	
	$(CC)as.exe -c $(CFLAGS) $(INCS) $< -o $@
$(project).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(OBJ) $(ASOBJ) -o $@ -Map=mapfile.map

$(project).hex: $(project).elf
	$(CC)objcopy.exe -O ihex $< $@


$(project).bin: $(project).elf
	$(CC)objcopy.exe -O binary $< $@

	
	
clean:
	rm *.o *.map *.elf *.bin *.hex	 	  	