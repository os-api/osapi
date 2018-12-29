################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/net/net_ip.c \
../code/net/net_private.c 

OBJS += \
./code/net/net_ip.o \
./code/net/net_private.o 

C_DEPS += \
./code/net/net_ip.d \
./code/net/net_private.d 


# Each subdirectory must supply rules for building sources it contributes
code/net/%.o: ../code/net/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I"/home/joao/workspace/osapi/code" -I/usr/include -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


