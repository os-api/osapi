################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/status/status.c 

OBJS += \
./code/status/status.o 

C_DEPS += \
./code/status/status.d 


# Each subdirectory must supply rules for building sources it contributes
code/status/%.o: ../code/status/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DOS_LINUX -I"../code" -I/usr/include -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

