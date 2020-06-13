################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include code/util/subdir.mk
-include code/string/subdir.mk
-include code/status/posix/subdir.mk
-include code/status/subdir.mk
-include code/sec/posix/subdir.mk
-include code/sec/subdir.mk
-include code/proc/posix/subdir.mk
-include code/proc/linux/subdir.mk
-include code/proc/subdir.mk
-include code/os/posix/subdir.mk
-include code/os/linux/subdir.mk
-include code/os/subdir.mk
-include code/machine/posix/subdir.mk
-include code/machine/linux/subdir.mk
-include code/machine/cpu/subdir.mk
-include code/machine/subdir.mk
-include code/log/posix/subdir.mk
-include code/io/posix/subdir.mk
-include code/io/subdir.mk
-include code/general/library/subdir.mk
-include code/general/subdir.mk
-include code/fs/posix/subdir.mk
-include code/fs/linux/subdir.mk
-include code/fs/subdir.mk
-include code/error/subdir.mk
-include code/common/posix/subdir.mk
-include code/common/linux/subdir.mk
-include code/common/subdir.mk
-include code/com/posix/subdir.mk
-include code/com/subdir.mk
-include code/clock/posix/subdir.mk
-include code/clock/linux/subdir.mk
-include code/clock/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libosapi.so

# Tool invocations
libosapi.so: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L/usr/lib -shared -pg -o "libosapi.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(LIBRARIES)$(OBJS)$(C_DEPS) libosapi.so
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
