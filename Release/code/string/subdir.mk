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
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O2 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fno-short-enums -fPIC -fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


