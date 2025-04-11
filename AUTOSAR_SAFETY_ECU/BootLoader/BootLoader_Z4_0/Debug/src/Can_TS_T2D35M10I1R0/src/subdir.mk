################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/Can.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/Can_Flexcan.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/Can_Irq.c 

OBJS += \
./src/Can_TS_T2D35M10I1R0/src/Can.o \
./src/Can_TS_T2D35M10I1R0/src/Can_Flexcan.o \
./src/Can_TS_T2D35M10I1R0/src/Can_Irq.o 

C_DEPS += \
./src/Can_TS_T2D35M10I1R0/src/Can.d \
./src/Can_TS_T2D35M10I1R0/src/Can_Flexcan.d \
./src/Can_TS_T2D35M10I1R0/src/Can_Irq.d 


# Each subdirectory must supply rules for building sources it contributes
src/Can_TS_T2D35M10I1R0/src/Can.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/Can.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Can_TS_T2D35M10I1R0/src/Can.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Can_TS_T2D35M10I1R0/src/Can_Flexcan.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/Can_Flexcan.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Can_TS_T2D35M10I1R0/src/Can_Flexcan.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Can_TS_T2D35M10I1R0/src/Can_Irq.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Can_TS_T2D35M10I1R0/src/Can_Irq.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Can_TS_T2D35M10I1R0/src/Can_Irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


