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
Az15.change_sp_to_psp.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Az15.change_sp_to_psp.list \

OBJCOPY_BIN += \
Az15.change_sp_to_psp.bin \


# All Target
all: Az15.change_sp_to_psp.elf secondary-outputs

# Tool invocations
Az15.change_sp_to_psp.elf: $(OBJS) $(USER_OBJS) E:\Desktop\ARM_Cortex\Embedded\ Systems\ Programming\ on\ ARM\ Cortex-M3M4\ Processor\.LearnARM_CortexM4\Az15.change_sp_to_psp\STM32F407VGTX_FLASH.ld
	arm-none-eabi-gcc -o "Az15.change_sp_to_psp.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"E:\Desktop\ARM_Cortex\Embedded Systems Programming on ARM Cortex-M3M4 Processor\.LearnARM_CortexM4\Az15.change_sp_to_psp\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Az15.change_sp_to_psp.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Az15.change_sp_to_psp.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Az15.change_sp_to_psp.list"
	@echo 'Finished building: $@'
	@echo ' '

Az15.change_sp_to_psp.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Az15.change_sp_to_psp.bin"
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
