################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/UART/uart.c 

OBJS += \
./HAL/UART/uart.o 

C_DEPS += \
./HAL/UART/uart.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/UART/%.o HAL/UART/%.su HAL/UART/%.cyclo: ../HAL/UART/%.c HAL/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/HAL/UART" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application/SysInit" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface/circularBuffer" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface/DebugUart" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application/DebugCLI" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/HAL/RTC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-UART

clean-HAL-2f-UART:
	-$(RM) ./HAL/UART/uart.cyclo ./HAL/UART/uart.d ./HAL/UART/uart.o ./HAL/UART/uart.su

.PHONY: clean-HAL-2f-UART

