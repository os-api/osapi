################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/fs/fs_dir.c \
../code/fs/fs_element.c \
../code/fs/fs_elementInfo.c \
../code/fs/fs_file.c \
../code/fs/fs_link.c 

OBJS += \
./code/fs/fs_dir.o \
./code/fs/fs_element.o \
./code/fs/fs_elementInfo.o \
./code/fs/fs_file.o \
./code/fs/fs_link.o 

C_DEPS += \
./code/fs/fs_dir.d \
./code/fs/fs_element.d \
./code/fs/fs_elementInfo.d \
./code/fs/fs_file.d \
./code/fs/fs_link.d 


# Each subdirectory must supply rules for building sources it contributes
code/fs/%.o: ../code/fs/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O2 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fno-short-enums -fPIC -fstack-protector-all -Wformat=2 -Wformat-security -Wstrict-overflow -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


