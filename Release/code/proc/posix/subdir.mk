################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/proc/posix/proc_posix.c \
../code/proc/posix/proc_posix_identity.c \
../code/proc/posix/proc_posix_instance.c \
../code/proc/posix/proc_posix_library.c \
../code/proc/posix/proc_posix_priv.c \
../code/proc/posix/proc_posix_signal.c 

OBJS += \
./code/proc/posix/proc_posix.o \
./code/proc/posix/proc_posix_identity.o \
./code/proc/posix/proc_posix_instance.o \
./code/proc/posix/proc_posix_library.o \
./code/proc/posix/proc_posix_priv.o \
./code/proc/posix/proc_posix_signal.o 

C_DEPS += \
./code/proc/posix/proc_posix.d \
./code/proc/posix/proc_posix_identity.d \
./code/proc/posix/proc_posix_instance.d \
./code/proc/posix/proc_posix_library.d \
./code/proc/posix/proc_posix_priv.d \
./code/proc/posix/proc_posix_signal.d 


# Each subdirectory must supply rules for building sources it contributes
code/proc/posix/%.o: ../code/proc/posix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


