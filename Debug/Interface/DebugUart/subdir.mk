################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Interface/DebugUart/debugUart.c 

OBJS += \
./Interface/DebugUart/debugUart.o 

C_DEPS += \
./Interface/DebugUart/debugUart.d 


# Each subdirectory must supply rules for building sources it contributes
Interface/DebugUart/%.o Interface/DebugUart/%.su Interface/DebugUart/%.cyclo: ../Interface/DebugUart/%.c Interface/DebugUart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/RTC" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/UART" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface/DebugUart" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application/SysInit" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Interface-2f-DebugUart

clean-Interface-2f-DebugUart:
	-$(RM) ./Interface/DebugUart/debugUart.cyclo ./Interface/DebugUart/debugUart.d ./Interface/DebugUart/debugUart.o ./Interface/DebugUart/debugUart.su

.PHONY: clean-Interface-2f-DebugUart

