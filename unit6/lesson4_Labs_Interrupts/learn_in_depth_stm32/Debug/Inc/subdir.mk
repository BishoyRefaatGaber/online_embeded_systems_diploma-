################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/learn_in_depth.c 

OBJS += \
./Inc/learn_in_depth.o 

C_DEPS += \
./Inc/learn_in_depth.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/learn_in_depth.o: ../Inc/learn_in_depth.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Inc/learn_in_depth.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

