################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/string/string.c \
../code/string/string_basic.c \
../code/string/string_wide.c 

OBJS += \
./code/string/string.o \
./code/string/string_basic.o \
./code/string/string_wide.o 

C_DEPS += \
./code/string/string.d \
./code/string/string_basic.d \
./code/string/string_wide.d 


# Each subdirectory must supply rules for building sources it contributes
code/string/%.o: ../code/string/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -DOSAPI_TRACER -I"/home/joao/workspace/osapi/code" -I/usr/include -O0 -g3 -pg -Wall -Wconversion -c -fmessage-length=0 -fstack-protector-all -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


