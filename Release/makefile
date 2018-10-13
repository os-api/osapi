################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include code/util/subdir.mk
-include code/string/subdir.mk
-include code/status/subdir.mk
-include code/sec/subdir.mk
-include code/proc/subdir.mk
-include code/os/subdir.mk
-include code/net/subdir.mk
-include code/machine/subdir.mk
-include code/log/subdir.mk
-include code/ipc/subdir.mk
-include code/general/subdir.mk
-include code/error/subdir.mk
-include code/common/subdir.mk
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
	gcc -shared -o "libosapi.so" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(LIBRARIES)$(OBJS)$(C_DEPS) libosapi.so
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
