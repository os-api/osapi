################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/general/general.c 

OBJS += \
./code/general/general.o 

C_DEPS += \
./code/general/general.d 


# Each subdirectory must supply rules for building sources it contributes
code/general/%.o: ../code/general/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O2 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fno-short-enums -fPIC -fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


