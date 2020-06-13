################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/machine/cpu/machine_cpu.c \
../code/machine/cpu/machine_cpu_amd.c \
../code/machine/cpu/machine_cpu_common.c \
../code/machine/cpu/machine_cpu_intel.c 

OBJS += \
./code/machine/cpu/machine_cpu.o \
./code/machine/cpu/machine_cpu_amd.o \
./code/machine/cpu/machine_cpu_common.o \
./code/machine/cpu/machine_cpu_intel.o 

C_DEPS += \
./code/machine/cpu/machine_cpu.d \
./code/machine/cpu/machine_cpu_amd.d \
./code/machine/cpu/machine_cpu_common.d \
./code/machine/cpu/machine_cpu_intel.d 


# Each subdirectory must supply rules for building sources it contributes
code/machine/cpu/%.o: ../code/machine/cpu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O2 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fno-short-enums -fPIC -fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


