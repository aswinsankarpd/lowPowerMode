################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/RTC/realtimeclock.c 

OBJS += \
./HAL/RTC/realtimeclock.o 

C_DEPS += \
./HAL/RTC/realtimeclock.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/RTC/%.o HAL/RTC/%.su HAL/RTC/%.cyclo: ../HAL/RTC/%.c HAL/RTC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/RTC" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/HAL/UART" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface/DebugUart" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Interface" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/Low Power Mode - Office/Application/SysInit" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-RTC

clean-HAL-2f-RTC:
	-$(RM) ./HAL/RTC/realtimeclock.cyclo ./HAL/RTC/realtimeclock.d ./HAL/RTC/realtimeclock.o ./HAL/RTC/realtimeclock.su

.PHONY: clean-HAL-2f-RTC

