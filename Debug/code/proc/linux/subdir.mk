################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/proc/linux/proc_linux.c \
../code/proc/linux/proc_linux_priv.c \
../code/proc/linux/proc_linux_stat.c 

OBJS += \
./code/proc/linux/proc_linux.o \
./code/proc/linux/proc_linux_priv.o \
./code/proc/linux/proc_linux_stat.o 

C_DEPS += \
./code/proc/linux/proc_linux.d \
./code/proc/linux/proc_linux_priv.d \
./code/proc/linux/proc_linux_stat.d 


# Each subdirectory must supply rules for building sources it contributes
code/proc/linux/%.o: ../code/proc/linux/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -DOSAPI_TRACER -I"/home/joao/workspace/osapi/code" -I/usr/include -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -Wconversion -c -fmessage-length=0 -fstack-protector-all -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


