################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/USART_DRIVER/USART.c 

OBJS += \
./HAL/USART_DRIVER/USART.o 

C_DEPS += \
./HAL/USART_DRIVER/USART.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/USART_DRIVER/%.o HAL/USART_DRIVER/%.su: ../HAL/USART_DRIVER/%.c HAL/USART_DRIVER/subdir.mk
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL/USART_DRIVER/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL/KEYPAD_DRIVER/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/HAL/LCD_DRIVER/inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/Inc" -I"C:/Users/refaa/STM32CubeIDE/workspace_1.4.0/DRIVERS/STM32F103C6/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-USART_DRIVER

clean-HAL-2f-USART_DRIVER:
	-$(RM) ./HAL/USART_DRIVER/USART.d ./HAL/USART_DRIVER/USART.o ./HAL/USART_DRIVER/USART.su

.PHONY: clean-HAL-2f-USART_DRIVER

