################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/proc/proc.c \
../code/proc/proc_resource_usage.c 

OBJS += \
./code/proc/proc.o \
./code/proc/proc_resource_usage.o 

C_DEPS += \
./code/proc/proc.d \
./code/proc/proc_resource_usage.d 


# Each subdirectory must supply rules for building sources it contributes
code/proc/%.o: ../code/proc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


