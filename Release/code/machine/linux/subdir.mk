################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/machine/linux/machine_linux.c 

OBJS += \
./code/machine/linux/machine_linux.o 

C_DEPS += \
./code/machine/linux/machine_linux.d 


# Each subdirectory must supply rules for building sources it contributes
code/machine/linux/%.o: ../code/machine/linux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I"/home/joao/workspace/osapi/code" -I/usr/include -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


