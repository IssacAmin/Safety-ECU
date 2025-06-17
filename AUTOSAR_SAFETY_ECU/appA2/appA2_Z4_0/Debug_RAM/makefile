################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/bootloaderOsConfig/output/generated/epc/subdir.mk
-include src/appAConfig/udsConfig/src/subdir.mk
-include src/appAConfig/output/generated/src/subdir.mk
-include src/appAConfig/CanIfConfig/src/subdir.mk
-include src/UDS_C_SERVER/srv_handlers/TesterPresent/src/subdir.mk
-include src/UDS_C_SERVER/srv_handlers/SessionCTRL/src/subdir.mk
-include src/UDS_C_SERVER/srv_handlers/SecurityAccess/src/subdir.mk
-include src/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/subdir.mk
-include src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/subdir.mk
-include src/UDS_C_SERVER/srv_handlers/ECUReset/src/subdir.mk
-include src/UDS_C_SERVER/server_main/src/subdir.mk
-include src/MPC574xG_AUTOSAR_OS_4_0_92_RTM_1_0_3/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Rte_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Mcu_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/subdir.mk
-include src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/subdir.mk
-include src/CanTp/src/subdir.mk
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
appA2_Z4_0.siz \


# All Target
all: appA2_Z4_0.elf secondary-outputs

# Tool invocations
appA2_Z4_0.elf: $(OBJS) C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appA2/appA2_Z4_0/Project_Settings/Linker_Files/57xx_ram.ld $(OSPT) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	powerpc-eabivle-gcc -o "appA2_Z4_0.elf" "@appA2_Z4_0.args"  $(USER_OBJS) $(LIBS) $(OSPT)
	@echo 'Finished building target: $@'
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

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
