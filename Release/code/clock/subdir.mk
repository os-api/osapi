################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/clock/clock_posix.c 

OBJS += \
./code/clock/clock_posix.o 

C_DEPS += \
./code/clock/clock_posix.d 


# Each subdirectory must supply rules for building sources it contributes
code/clock/%.o: ../code/clock/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -D_DEFAULT_SOURCE -I"../code" -I/usr/include -O3 -Wall -c -fmessage-length=0 -v -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


