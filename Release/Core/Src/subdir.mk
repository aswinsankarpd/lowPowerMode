################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/dma.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/memorymap.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/dma.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/memorymap.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/dma.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/memorymap.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/SysInit" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Drivers/CMSIS" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Drivers/STM32H7xx_HAL_Driver" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/RTC" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/UART" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/DebugUart" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/GpioInt" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/LowPowerMode" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/RTC" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/HAL/UART" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/circularBuffer" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Interface/DebugUart" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/DebugCLI" -I"D:/Tismo_Projects/Experiments/LowPowerMode/lowPowerMode/Application/SysInit" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/memorymap.cyclo ./Core/Src/memorymap.d ./Core/Src/memorymap.o ./Core/Src/memorymap.su ./Core/Src/stm32h7xx_hal_msp.cyclo ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.cyclo ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.cyclo ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src
