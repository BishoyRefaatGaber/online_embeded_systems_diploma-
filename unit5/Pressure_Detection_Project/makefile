CC = arm-none-eabi-
CFlAGS = -mcpu=arm926ej-s -mthumb -g -gdwarf-2
INCS = -I .
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project_Name = Pressure_Detection

ALL: $(Project_Name).bin $(Project_Name).axf $(Project_Name).hex

%.o: %.c
	$(CC)gcc.exe -c $(CFlAGS) $(INCS) $< -o $@
%.o: %.s 
	$(CC)as.exe -c $(CFlAGS) $(INCS) $< -o $@
$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(OBJ) $(ASOBJ) -o $@ -Map=mapfile.map
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
$(Project_Name).hex: $(Project_Name).elf
	$(CC)objcopy.exe -O ihex $< $@
	

$(Project_Name).axf: $(Project_Name).elf
	cp $< $@
clean :
	rm *.bin *.elf *.map *.o *.hex *.axf
