################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/common/common.c \
../code/common/common_asm.c \
../code/common/common_buffer.c \
../code/common/common_list.c \
../code/common/common_memory.c \
../code/common/common_number.c \
../code/common/common_time.c 

OBJS += \
./code/common/common.o \
./code/common/common_asm.o \
./code/common/common_buffer.o \
./code/common/common_list.o \
./code/common/common_memory.o \
./code/common/common_number.o \
./code/common/common_time.o 

C_DEPS += \
./code/common/common.d \
./code/common/common_asm.d \
./code/common/common_buffer.d \
./code/common/common_list.d \
./code/common/common_memory.d \
./code/common/common_number.d \
./code/common/common_time.d 


# Each subdirectory must supply rules for building sources it contributes
code/common/%.o: ../code/common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O2 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fno-short-enums -fPIC -fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


