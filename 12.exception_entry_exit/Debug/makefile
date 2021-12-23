################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
12.exception_entry_exit.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
12.exception_entry_exit.list \

OBJCOPY_BIN += \
12.exception_entry_exit.bin \


# All Target
all: 12.exception_entry_exit.elf secondary-outputs

# Tool invocations
12.exception_entry_exit.elf: $(OBJS) $(USER_OBJS) E:\Desktop\ARM_Cortex\Embedded\ Systems\ Programming\ on\ ARM\ Cortex-M3M4\ Processor\.LearnARM_CortexM4\12.exception_entry_exit\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "12.exception_entry_exit.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\Desktop\ARM_Cortex\Embedded Systems Programming on ARM Cortex-M3M4 Processor\.LearnARM_CortexM4\12.exception_entry_exit\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="12.exception_entry_exit.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

12.exception_entry_exit.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "12.exception_entry_exit.list"
	@echo 'Finished building: $@'
	@echo ' '

12.exception_entry_exit.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "12.exception_entry_exit.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
