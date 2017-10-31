################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/util/util.c 

OBJS += \
./code/util/util.o 

C_DEPS += \
./code/util/util.d 


# Each subdirectory must supply rules for building sources it contributes
code/util/%.o: ../code/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DOS_LINUX -I"../code" -I/usr/include -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


