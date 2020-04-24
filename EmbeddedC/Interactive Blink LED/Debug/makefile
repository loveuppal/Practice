################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include freertos/src/subdir.mk
-include example/src/subdir.mk
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
all: Final.axf

# Tool invocations
Final.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/sriq/Documents/MCUXpresso_11.0.1_2563/workspace/lpc_chip_175x_6x/Debug" -L"/home/sriq/Documents/MCUXpresso_11.0.1_2563/workspace/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="Final.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "VTU_SING_BUTT_Debug.ld" -o "Final.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Final.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Final.axf"; # arm-none-eabi-objcopy -v -O binary "Final.axf" "Final.bin" ; # checksum -p LPC1769 -d "Final.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
