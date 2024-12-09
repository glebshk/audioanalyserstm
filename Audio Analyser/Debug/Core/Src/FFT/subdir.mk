################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/FFT/fft.c \
../Core/Src/FFT/fft_test.c 

OBJS += \
./Core/Src/FFT/fft.o \
./Core/Src/FFT/fft_test.o 

C_DEPS += \
./Core/Src/FFT/fft.d \
./Core/Src/FFT/fft_test.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/FFT/%.o Core/Src/FFT/%.su Core/Src/FFT/%.cyclo: ../Core/Src/FFT/%.c Core/Src/FFT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/DSP -I../Core/Inc/DSP/dsp -I../Core/Inc/FFT -I../Core/Inc/Display -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-FFT

clean-Core-2f-Src-2f-FFT:
	-$(RM) ./Core/Src/FFT/fft.cyclo ./Core/Src/FFT/fft.d ./Core/Src/FFT/fft.o ./Core/Src/FFT/fft.su ./Core/Src/FFT/fft_test.cyclo ./Core/Src/FFT/fft_test.d ./Core/Src/FFT/fft_test.o ./Core/Src/FFT/fft_test.su

.PHONY: clean-Core-2f-Src-2f-FFT

