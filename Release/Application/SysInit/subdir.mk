################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/SysInit/sysInit.c 

OBJS += \
./Application/SysInit/sysInit.o 

C_DEPS += \
./Application/SysInit/sysInit.d 


# Each subdirectory must supply rules for building sources it contributes
Application/SysInit/%.o Application/SysInit/%.su Application/SysInit/%.cyclo: ../Application/SysInit/%.c Application/SysInit/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/SysInit" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Drivers/CMSIS" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Drivers/STM32H7xx_HAL_Driver" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/RTC" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/UART" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/DebugUart" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/RTC" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/UART" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/DebugUart" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/SysInit" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-SysInit

clean-Application-2f-SysInit:
	-$(RM) ./Application/SysInit/sysInit.cyclo ./Application/SysInit/sysInit.d ./Application/SysInit/sysInit.o ./Application/SysInit/sysInit.su

.PHONY: clean-Application-2f-SysInit

