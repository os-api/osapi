################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/fs/posix/fs_posix.c \
../code/fs/posix/fs_posix_dir.c \
../code/fs/posix/fs_posix_element.c \
../code/fs/posix/fs_posix_elementInfo.c \
../code/fs/posix/fs_posix_element_id.c \
../code/fs/posix/fs_posix_file.c \
../code/fs/posix/fs_posix_id.c \
../code/fs/posix/fs_posix_link.c \
../code/fs/posix/fs_posix_priv.c 

OBJS += \
./code/fs/posix/fs_posix.o \
./code/fs/posix/fs_posix_dir.o \
./code/fs/posix/fs_posix_element.o \
./code/fs/posix/fs_posix_elementInfo.o \
./code/fs/posix/fs_posix_element_id.o \
./code/fs/posix/fs_posix_file.o \
./code/fs/posix/fs_posix_id.o \
./code/fs/posix/fs_posix_link.o \
./code/fs/posix/fs_posix_priv.o 

C_DEPS += \
./code/fs/posix/fs_posix.d \
./code/fs/posix/fs_posix_dir.d \
./code/fs/posix/fs_posix_element.d \
./code/fs/posix/fs_posix_elementInfo.d \
./code/fs/posix/fs_posix_element_id.d \
./code/fs/posix/fs_posix_file.d \
./code/fs/posix/fs_posix_id.d \
./code/fs/posix/fs_posix_link.d \
./code/fs/posix/fs_posix_priv.d 


# Each subdirectory must supply rules for building sources it contributes
code/fs/posix/%.o: ../code/fs/posix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -std=c11 -DOS_LINUX -I/usr/include -I"${OSAPI_DIR}/code" -O3 -Wall -Wconversion -c -fmessage-length=0 -fvisibility=hidden -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


