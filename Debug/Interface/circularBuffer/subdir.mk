################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Interface/circularBuffer/circularBuffer.c 

OBJS += \
./Interface/circularBuffer/circularBuffer.o 

C_DEPS += \
./Interface/circularBuffer/circularBuffer.d 


# Each subdirectory must supply rules for building sources it contributes
Interface/circularBuffer/%.o Interface/circularBuffer/%.su Interface/circularBuffer/%.cyclo: ../Interface/circularBuffer/%.c Interface/circularBuffer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/RTC" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/UART" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface/DebugUart" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application/SysInit" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Interface-2f-circularBuffer

clean-Interface-2f-circularBuffer:
	-$(RM) ./Interface/circularBuffer/circularBuffer.cyclo ./Interface/circularBuffer/circularBuffer.d ./Interface/circularBuffer/circularBuffer.o ./Interface/circularBuffer/circularBuffer.su

.PHONY: clean-Interface-2f-circularBuffer

