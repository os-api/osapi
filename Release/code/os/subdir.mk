################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/os/os.c \
../code/os/os_posix.c 

OBJS += \
./code/os/os.o \
./code/os/os_posix.o 

C_DEPS += \
./code/os/os.d \
./code/os/os_posix.d 


# Each subdirectory must supply rules for building sources it contributes
code/os/%.o: ../code/os/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DOS_LINUX -I"../code" -I/usr/include -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


