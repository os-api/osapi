################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/ipc/semaphore_posix.c 

OBJS += \
./code/ipc/semaphore_posix.o 

C_DEPS += \
./code/ipc/semaphore_posix.d 


# Each subdirectory must supply rules for building sources it contributes
code/ipc/%.o: ../code/ipc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I"../code" -I/usr/include -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


