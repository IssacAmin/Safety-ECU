################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/generated/src/subdir.mk
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
SECONDARY_FLASH += \
appA2_Z4_0.bin \

SECONDARY_SIZE += \
appA2_Z4_0.siz \


# All Target
all: appA2_Z4_0.elf secondary-outputs

# Tool invocations
appA2_Z4_0.elf: $(OBJS) D:/eJad_GP/SDV-SOTA/ECU/AUTOSAR_SAFETY_ECU/appA2/appA2_Z4_0/Project_Settings/Linker_Files/57xx_flash.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "appA2_Z4_0.elf" "@appA2_Z4_0.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
	@echo ' '

appA2_Z4_0.bin: appA2_Z4_0.elf
	@echo 'Invoking: Standard S32DS Create Flash Image'
	powerpc-eabivle-objcopy -O binary appA2_Z4_0.elf  "appA2_Z4_0.bin"
	@echo 'Finished building: $@'
	@echo ' '

appA2_Z4_0.siz: appA2_Z4_0.elf
	@echo 'Invoking: Standard S32DS Print Size'
	powerpc-eabivle-size --format=berkeley appA2_Z4_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
