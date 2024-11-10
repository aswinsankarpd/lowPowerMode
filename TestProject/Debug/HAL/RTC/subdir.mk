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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/HAL/UART" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application/SysInit" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface/circularBuffer" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface/DebugUart" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application/DebugCLI" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/HAL/RTC" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/HAL/GpioInt" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-RTC

clean-HAL-2f-RTC:
	-$(RM) ./HAL/RTC/realtimeclock.cyclo ./HAL/RTC/realtimeclock.d ./HAL/RTC/realtimeclock.o ./HAL/RTC/realtimeclock.su

.PHONY: clean-HAL-2f-RTC

