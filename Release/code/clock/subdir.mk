################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/clock/clock.c 

OBJS += \
./code/clock/clock.o 

C_DEPS += \
./code/clock/clock.d 


# Each subdirectory must supply rules for building sources it contributes
code/clock/%.o: ../code/clock/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


