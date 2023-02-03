################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6/EXTI.c \
../STM32F103C6/GPIO.c \
../STM32F103C6/RCC.c 

OBJS += \
./STM32F103C6/EXTI.o \
./STM32F103C6/GPIO.o \
./STM32F103C6/RCC.o 

C_DEPS += \
./STM32F103C6/EXTI.d \
./STM32F103C6/GPIO.d \
./STM32F103C6/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6/%.o STM32F103C6/%.su: ../STM32F103C6/%.c STM32F103C6/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL/USART_DRIVER/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL/KEYPAD_DRIVER/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL/LCD_DRIVER/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/Inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6

clean-STM32F103C6:
	-$(RM) ./STM32F103C6/EXTI.d ./STM32F103C6/EXTI.o ./STM32F103C6/EXTI.su ./STM32F103C6/GPIO.d ./STM32F103C6/GPIO.o ./STM32F103C6/GPIO.su ./STM32F103C6/RCC.d ./STM32F103C6/RCC.o ./STM32F103C6/RCC.su

.PHONY: clean-STM32F103C6

