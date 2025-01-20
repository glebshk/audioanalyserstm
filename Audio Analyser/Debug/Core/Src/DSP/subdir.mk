################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/DSP/arm_bitreversal.c \
../Core/Src/DSP/arm_bitreversal2.c \
../Core/Src/DSP/arm_bitreversal_f16.c \
../Core/Src/DSP/arm_cfft_f32.c \
../Core/Src/DSP/arm_cfft_init_f32.c \
../Core/Src/DSP/arm_cfft_q31.c \
../Core/Src/DSP/arm_cfft_radix4_f32.c \
../Core/Src/DSP/arm_cfft_radix4_init_f32.c \
../Core/Src/DSP/arm_cfft_radix4_q31.c \
../Core/Src/DSP/arm_cfft_radix8_f32.c \
../Core/Src/DSP/arm_cmplx_mag_f32.c \
../Core/Src/DSP/arm_cmplx_mag_q31.c \
../Core/Src/DSP/arm_common_tables.c \
../Core/Src/DSP/arm_const_structs.c \
../Core/Src/DSP/arm_cos_q31.c \
../Core/Src/DSP/arm_float_to_q31.c \
../Core/Src/DSP/arm_mve_tables.c \
../Core/Src/DSP/arm_rfft_f32.c \
../Core/Src/DSP/arm_rfft_fast_f32.c \
../Core/Src/DSP/arm_rfft_fast_init_f32.c \
../Core/Src/DSP/arm_rfft_init_f32.c \
../Core/Src/DSP/arm_rfft_init_q31.c \
../Core/Src/DSP/arm_rfft_q31.c \
../Core/Src/DSP/arm_shift_q31.c \
../Core/Src/DSP/arm_sin_f32.c \
../Core/Src/DSP/arm_sin_q31.c \
../Core/Src/DSP/arm_sqrt_q31.c 

OBJS += \
./Core/Src/DSP/arm_bitreversal.o \
./Core/Src/DSP/arm_bitreversal2.o \
./Core/Src/DSP/arm_bitreversal_f16.o \
./Core/Src/DSP/arm_cfft_f32.o \
./Core/Src/DSP/arm_cfft_init_f32.o \
./Core/Src/DSP/arm_cfft_q31.o \
./Core/Src/DSP/arm_cfft_radix4_f32.o \
./Core/Src/DSP/arm_cfft_radix4_init_f32.o \
./Core/Src/DSP/arm_cfft_radix4_q31.o \
./Core/Src/DSP/arm_cfft_radix8_f32.o \
./Core/Src/DSP/arm_cmplx_mag_f32.o \
./Core/Src/DSP/arm_cmplx_mag_q31.o \
./Core/Src/DSP/arm_common_tables.o \
./Core/Src/DSP/arm_const_structs.o \
./Core/Src/DSP/arm_cos_q31.o \
./Core/Src/DSP/arm_float_to_q31.o \
./Core/Src/DSP/arm_mve_tables.o \
./Core/Src/DSP/arm_rfft_f32.o \
./Core/Src/DSP/arm_rfft_fast_f32.o \
./Core/Src/DSP/arm_rfft_fast_init_f32.o \
./Core/Src/DSP/arm_rfft_init_f32.o \
./Core/Src/DSP/arm_rfft_init_q31.o \
./Core/Src/DSP/arm_rfft_q31.o \
./Core/Src/DSP/arm_shift_q31.o \
./Core/Src/DSP/arm_sin_f32.o \
./Core/Src/DSP/arm_sin_q31.o \
./Core/Src/DSP/arm_sqrt_q31.o 

C_DEPS += \
./Core/Src/DSP/arm_bitreversal.d \
./Core/Src/DSP/arm_bitreversal2.d \
./Core/Src/DSP/arm_bitreversal_f16.d \
./Core/Src/DSP/arm_cfft_f32.d \
./Core/Src/DSP/arm_cfft_init_f32.d \
./Core/Src/DSP/arm_cfft_q31.d \
./Core/Src/DSP/arm_cfft_radix4_f32.d \
./Core/Src/DSP/arm_cfft_radix4_init_f32.d \
./Core/Src/DSP/arm_cfft_radix4_q31.d \
./Core/Src/DSP/arm_cfft_radix8_f32.d \
./Core/Src/DSP/arm_cmplx_mag_f32.d \
./Core/Src/DSP/arm_cmplx_mag_q31.d \
./Core/Src/DSP/arm_common_tables.d \
./Core/Src/DSP/arm_const_structs.d \
./Core/Src/DSP/arm_cos_q31.d \
./Core/Src/DSP/arm_float_to_q31.d \
./Core/Src/DSP/arm_mve_tables.d \
./Core/Src/DSP/arm_rfft_f32.d \
./Core/Src/DSP/arm_rfft_fast_f32.d \
./Core/Src/DSP/arm_rfft_fast_init_f32.d \
./Core/Src/DSP/arm_rfft_init_f32.d \
./Core/Src/DSP/arm_rfft_init_q31.d \
./Core/Src/DSP/arm_rfft_q31.d \
./Core/Src/DSP/arm_shift_q31.d \
./Core/Src/DSP/arm_sin_f32.d \
./Core/Src/DSP/arm_sin_q31.d \
./Core/Src/DSP/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/DSP/%.o Core/Src/DSP/%.su Core/Src/DSP/%.cyclo: ../Core/Src/DSP/%.c Core/Src/DSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DARM_MATH_CM4 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc/DSP -I../Core/Inc/DSP/dsp -I../Core/Inc/FFT -I../Core/Inc/Display -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-DSP

clean-Core-2f-Src-2f-DSP:
	-$(RM) ./Core/Src/DSP/arm_bitreversal.cyclo ./Core/Src/DSP/arm_bitreversal.d ./Core/Src/DSP/arm_bitreversal.o ./Core/Src/DSP/arm_bitreversal.su ./Core/Src/DSP/arm_bitreversal2.cyclo ./Core/Src/DSP/arm_bitreversal2.d ./Core/Src/DSP/arm_bitreversal2.o ./Core/Src/DSP/arm_bitreversal2.su ./Core/Src/DSP/arm_bitreversal_f16.cyclo ./Core/Src/DSP/arm_bitreversal_f16.d ./Core/Src/DSP/arm_bitreversal_f16.o ./Core/Src/DSP/arm_bitreversal_f16.su ./Core/Src/DSP/arm_cfft_f32.cyclo ./Core/Src/DSP/arm_cfft_f32.d ./Core/Src/DSP/arm_cfft_f32.o ./Core/Src/DSP/arm_cfft_f32.su ./Core/Src/DSP/arm_cfft_init_f32.cyclo ./Core/Src/DSP/arm_cfft_init_f32.d ./Core/Src/DSP/arm_cfft_init_f32.o ./Core/Src/DSP/arm_cfft_init_f32.su ./Core/Src/DSP/arm_cfft_q31.cyclo ./Core/Src/DSP/arm_cfft_q31.d ./Core/Src/DSP/arm_cfft_q31.o ./Core/Src/DSP/arm_cfft_q31.su ./Core/Src/DSP/arm_cfft_radix4_f32.cyclo ./Core/Src/DSP/arm_cfft_radix4_f32.d ./Core/Src/DSP/arm_cfft_radix4_f32.o ./Core/Src/DSP/arm_cfft_radix4_f32.su ./Core/Src/DSP/arm_cfft_radix4_init_f32.cyclo ./Core/Src/DSP/arm_cfft_radix4_init_f32.d ./Core/Src/DSP/arm_cfft_radix4_init_f32.o ./Core/Src/DSP/arm_cfft_radix4_init_f32.su ./Core/Src/DSP/arm_cfft_radix4_q31.cyclo ./Core/Src/DSP/arm_cfft_radix4_q31.d ./Core/Src/DSP/arm_cfft_radix4_q31.o ./Core/Src/DSP/arm_cfft_radix4_q31.su ./Core/Src/DSP/arm_cfft_radix8_f32.cyclo ./Core/Src/DSP/arm_cfft_radix8_f32.d ./Core/Src/DSP/arm_cfft_radix8_f32.o ./Core/Src/DSP/arm_cfft_radix8_f32.su ./Core/Src/DSP/arm_cmplx_mag_f32.cyclo ./Core/Src/DSP/arm_cmplx_mag_f32.d ./Core/Src/DSP/arm_cmplx_mag_f32.o ./Core/Src/DSP/arm_cmplx_mag_f32.su ./Core/Src/DSP/arm_cmplx_mag_q31.cyclo ./Core/Src/DSP/arm_cmplx_mag_q31.d ./Core/Src/DSP/arm_cmplx_mag_q31.o ./Core/Src/DSP/arm_cmplx_mag_q31.su ./Core/Src/DSP/arm_common_tables.cyclo ./Core/Src/DSP/arm_common_tables.d ./Core/Src/DSP/arm_common_tables.o ./Core/Src/DSP/arm_common_tables.su ./Core/Src/DSP/arm_const_structs.cyclo ./Core/Src/DSP/arm_const_structs.d ./Core/Src/DSP/arm_const_structs.o ./Core/Src/DSP/arm_const_structs.su ./Core/Src/DSP/arm_cos_q31.cyclo ./Core/Src/DSP/arm_cos_q31.d ./Core/Src/DSP/arm_cos_q31.o ./Core/Src/DSP/arm_cos_q31.su ./Core/Src/DSP/arm_float_to_q31.cyclo ./Core/Src/DSP/arm_float_to_q31.d ./Core/Src/DSP/arm_float_to_q31.o ./Core/Src/DSP/arm_float_to_q31.su ./Core/Src/DSP/arm_mve_tables.cyclo ./Core/Src/DSP/arm_mve_tables.d ./Core/Src/DSP/arm_mve_tables.o ./Core/Src/DSP/arm_mve_tables.su ./Core/Src/DSP/arm_rfft_f32.cyclo ./Core/Src/DSP/arm_rfft_f32.d ./Core/Src/DSP/arm_rfft_f32.o ./Core/Src/DSP/arm_rfft_f32.su ./Core/Src/DSP/arm_rfft_fast_f32.cyclo ./Core/Src/DSP/arm_rfft_fast_f32.d ./Core/Src/DSP/arm_rfft_fast_f32.o ./Core/Src/DSP/arm_rfft_fast_f32.su ./Core/Src/DSP/arm_rfft_fast_init_f32.cyclo ./Core/Src/DSP/arm_rfft_fast_init_f32.d ./Core/Src/DSP/arm_rfft_fast_init_f32.o ./Core/Src/DSP/arm_rfft_fast_init_f32.su ./Core/Src/DSP/arm_rfft_init_f32.cyclo ./Core/Src/DSP/arm_rfft_init_f32.d ./Core/Src/DSP/arm_rfft_init_f32.o ./Core/Src/DSP/arm_rfft_init_f32.su ./Core/Src/DSP/arm_rfft_init_q31.cyclo ./Core/Src/DSP/arm_rfft_init_q31.d ./Core/Src/DSP/arm_rfft_init_q31.o ./Core/Src/DSP/arm_rfft_init_q31.su ./Core/Src/DSP/arm_rfft_q31.cyclo ./Core/Src/DSP/arm_rfft_q31.d ./Core/Src/DSP/arm_rfft_q31.o ./Core/Src/DSP/arm_rfft_q31.su ./Core/Src/DSP/arm_shift_q31.cyclo ./Core/Src/DSP/arm_shift_q31.d ./Core/Src/DSP/arm_shift_q31.o ./Core/Src/DSP/arm_shift_q31.su ./Core/Src/DSP/arm_sin_f32.cyclo ./Core/Src/DSP/arm_sin_f32.d ./Core/Src/DSP/arm_sin_f32.o ./Core/Src/DSP/arm_sin_f32.su ./Core/Src/DSP/arm_sin_q31.cyclo ./Core/Src/DSP/arm_sin_q31.d ./Core/Src/DSP/arm_sin_q31.o ./Core/Src/DSP/arm_sin_q31.su ./Core/Src/DSP/arm_sqrt_q31.cyclo ./Core/Src/DSP/arm_sqrt_q31.d ./Core/Src/DSP/arm_sqrt_q31.o ./Core/Src/DSP/arm_sqrt_q31.su

.PHONY: clean-Core-2f-Src-2f-DSP

