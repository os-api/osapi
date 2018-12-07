################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/machine/machine.c \
../code/machine/machine_linux.c \
../code/machine/machine_posix.c 

OBJS += \
./code/machine/machine.o \
./code/machine/machine_linux.o \
./code/machine/machine_posix.o 

C_DEPS += \
./code/machine/machine.d \
./code/machine/machine_linux.d \
./code/machine/machine_posix.d 


# Each subdirectory must supply rules for building sources it contributes
code/machine/%.o: ../code/machine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I"../code" -I/usr/include -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


