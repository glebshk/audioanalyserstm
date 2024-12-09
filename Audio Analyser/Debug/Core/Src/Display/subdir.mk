################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Display/GFX_FUNCTIONS.c \
../Core/Src/Display/ST7735.c \
../Core/Src/Display/fonts.c 

OBJS += \
./Core/Src/Display/GFX_FUNCTIONS.o \
./Core/Src/Display/ST7735.o \
./Core/Src/Display/fonts.o 

C_DEPS += \
./Core/Src/Display/GFX_FUNCTIONS.d \
./Core/Src/Display/ST7735.d \
./Core/Src/Display/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Display/%.o Core/Src/Display/%.su Core/Src/Display/%.cyclo: ../Core/Src/Display/%.c Core/Src/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/DSP -I../Core/Inc/DSP/dsp -I../Core/Inc/FFT -I../Core/Inc/Display -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Display

clean-Core-2f-Src-2f-Display:
	-$(RM) ./Core/Src/Display/GFX_FUNCTIONS.cyclo ./Core/Src/Display/GFX_FUNCTIONS.d ./Core/Src/Display/GFX_FUNCTIONS.o ./Core/Src/Display/GFX_FUNCTIONS.su ./Core/Src/Display/ST7735.cyclo ./Core/Src/Display/ST7735.d ./Core/Src/Display/ST7735.o ./Core/Src/Display/ST7735.su ./Core/Src/Display/fonts.cyclo ./Core/Src/Display/fonts.d ./Core/Src/Display/fonts.o ./Core/Src/Display/fonts.su

.PHONY: clean-Core-2f-Src-2f-Display

