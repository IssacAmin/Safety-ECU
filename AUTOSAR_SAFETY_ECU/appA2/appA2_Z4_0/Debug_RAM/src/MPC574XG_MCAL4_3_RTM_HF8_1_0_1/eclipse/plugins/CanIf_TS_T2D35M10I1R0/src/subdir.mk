################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/CanIf.c 

OBJS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/CanIf.o 

C_DEPS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/CanIf.d 


# Each subdirectory must supply rules for building sources it contributes
src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/CanIf.o: C:/Users/Fady/Downloads/Safety-ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/CanIf.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/CanIf_TS_T2D35M10I1R0/src/CanIf.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


