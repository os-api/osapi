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
	gcc -std=c11 -DOS_LINUX -DOSAPI_TRACER -I"/home/joao/workspace/osapi/code" -I/usr/include -O0 -g3 -pg -Wall -Wconversion -c -fmessage-length=0 -fstack-protector-all -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


