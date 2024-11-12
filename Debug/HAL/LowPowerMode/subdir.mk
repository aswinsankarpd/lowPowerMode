################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LowPowerMode/lowPowerMode.c 

OBJS += \
./HAL/LowPowerMode/lowPowerMode.o 

C_DEPS += \
./HAL/LowPowerMode/lowPowerMode.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LowPowerMode/%.o HAL/LowPowerMode/%.su HAL/LowPowerMode/%.cyclo: ../HAL/LowPowerMode/%.c HAL/LowPowerMode/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/AswinSankar/Downloads/q/w/HAL" -I"C:/Users/AswinSankar/Downloads/q/w/HAL/GpioInt" -I"C:/Users/AswinSankar/Downloads/q/w/HAL/LowPowerMode" -I"C:/Users/AswinSankar/Downloads/q/w/HAL/RTC" -I"C:/Users/AswinSankar/Downloads/q/w/HAL/UART" -I"C:/Users/AswinSankar/Downloads/q/w/Interface/circularBuffer" -I"C:/Users/AswinSankar/Downloads/q/w/Interface/DebugUart" -I"C:/Users/AswinSankar/Downloads/q/w/Interface" -I"C:/Users/AswinSankar/Downloads/q/w/Application" -I"C:/Users/AswinSankar/Downloads/q/w/Application/DebugCLI" -I"C:/Users/AswinSankar/Downloads/q/w/Application/SysInit" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-LowPowerMode

clean-HAL-2f-LowPowerMode:
	-$(RM) ./HAL/LowPowerMode/lowPowerMode.cyclo ./HAL/LowPowerMode/lowPowerMode.d ./HAL/LowPowerMode/lowPowerMode.o ./HAL/LowPowerMode/lowPowerMode.su

.PHONY: clean-HAL-2f-LowPowerMode

