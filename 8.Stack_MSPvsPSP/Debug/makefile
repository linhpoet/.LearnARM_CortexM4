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
8.Stack_MSPvsPSP.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
8.Stack_MSPvsPSP.list \

OBJCOPY_BIN += \
8.Stack_MSPvsPSP.bin \


# All Target
all: 8.Stack_MSPvsPSP.elf secondary-outputs

# Tool invocations
8.Stack_MSPvsPSP.elf: $(OBJS) $(USER_OBJS) E:\Desktop\ARM_Cortex\Embedded\ Systems\ Programming\ on\ ARM\ Cortex-M3M4\ Processor\.LearnARM_CortexM4\8.Stack_MSPvsPSP\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "8.Stack_MSPvsPSP.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\Desktop\ARM_Cortex\Embedded Systems Programming on ARM Cortex-M3M4 Processor\.LearnARM_CortexM4\8.Stack_MSPvsPSP\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="8.Stack_MSPvsPSP.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

8.Stack_MSPvsPSP.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "8.Stack_MSPvsPSP.list"
	@echo 'Finished building: $@'
	@echo ' '

8.Stack_MSPvsPSP.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "8.Stack_MSPvsPSP.bin"
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
