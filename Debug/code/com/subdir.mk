################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/com/com.c \
../code/com/com_ip.c \
../code/com/com_private.c 

OBJS += \
./code/com/com.o \
./code/com/com_ip.o \
./code/com/com_private.o 

C_DEPS += \
./code/com/com.d \
./code/com/com_ip.d \
./code/com/com_private.d 


# Each subdirectory must supply rules for building sources it contributes
code/com/%.o: ../code/com/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -DOSAPI_TRACER -I"/home/joao/workspace/osapi/code" -I/usr/include -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -Wconversion -c -fmessage-length=0 -fstack-protector-all -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


