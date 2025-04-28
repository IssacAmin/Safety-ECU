################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/output/generated/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Rte_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Mcu_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
BootManager_Z4_0.siz \


# All Target
all: BootManager_Z4_0.elf secondary-outputs

# Tool invocations
BootManager_Z4_0.elf: $(OBJS) C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/BootManager/BootManager_Z4_0/Project_Settings/Linker_Files/57xx_flash.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "BootManager_Z4_0.elf" "@BootManager_Z4_0.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

BootManager_Z4_0.siz: BootManager_Z4_0.elf
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley BootManager_Z4_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
