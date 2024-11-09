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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/HAL/UART" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application/SysInit" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface/circularBuffer" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Interface/DebugUart" -I"C:/Users/Aswin/STM32CubeIDE/workspace_1.16.1/LowPowerMode/lowPowerMode/TestProject/Application/DebugCLI" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Interface-2f-circularBuffer

clean-Interface-2f-circularBuffer:
	-$(RM) ./Interface/circularBuffer/circularBuffer.cyclo ./Interface/circularBuffer/circularBuffer.d ./Interface/circularBuffer/circularBuffer.o ./Interface/circularBuffer/circularBuffer.su

.PHONY: clean-Interface-2f-circularBuffer

