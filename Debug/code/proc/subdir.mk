################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/proc/proc.c \
../code/proc/proc_buffer.c \
../code/proc/proc_info.c \
../code/proc/proc_list.c \
../code/proc/proc_memory.c \
../code/proc/proc_plan.c \
../code/proc/proc_resource.c \
../code/proc/proc_time.c 

OBJS += \
./code/proc/proc.o \
./code/proc/proc_buffer.o \
./code/proc/proc_info.o \
./code/proc/proc_list.o \
./code/proc/proc_memory.o \
./code/proc/proc_plan.o \
./code/proc/proc_resource.o \
./code/proc/proc_time.o 

C_DEPS += \
./code/proc/proc.d \
./code/proc/proc_buffer.d \
./code/proc/proc_info.d \
./code/proc/proc_list.d \
./code/proc/proc_memory.d \
./code/proc/proc_plan.d \
./code/proc/proc_resource.d \
./code/proc/proc_time.d 


# Each subdirectory must supply rules for building sources it contributes
code/proc/%.o: ../code/proc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -DOSAPI_TRACER -I"/home/joao/workspace/osapi/code" -I/usr/include -O0 -g3 -pg -Wall -Wconversion -c -fmessage-length=0 -fstack-protector-all -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


