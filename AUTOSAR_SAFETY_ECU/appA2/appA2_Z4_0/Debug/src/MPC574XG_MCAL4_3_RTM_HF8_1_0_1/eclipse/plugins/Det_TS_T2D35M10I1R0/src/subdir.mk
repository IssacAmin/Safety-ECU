################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/Det.c 

OBJS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/Det.o 

C_DEPS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/Det.d 


# Each subdirectory must supply rules for building sources it contributes
src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/Det.o: D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/Det.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Det_TS_T2D35M10I1R0/src/Det.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


