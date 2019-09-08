################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/log/posix/log_posix.c 

OBJS += \
./code/log/posix/log_posix.o 

C_DEPS += \
./code/log/posix/log_posix.d 


# Each subdirectory must supply rules for building sources it contributes
code/log/posix/%.o: ../code/log/posix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -DOSAPI_TRACER -I"/home/joao/workspace/osapi/code" -I/usr/include -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -Wconversion -c -fmessage-length=0 -fstack-protector-all -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


