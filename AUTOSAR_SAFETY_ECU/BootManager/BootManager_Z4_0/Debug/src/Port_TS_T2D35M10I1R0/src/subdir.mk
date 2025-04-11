################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.c 

OBJS += \
./src/Port_TS_T2D35M10I1R0/src/Port.o \
./src/Port_TS_T2D35M10I1R0/src/Port_Ipw.o \
./src/Port_TS_T2D35M10I1R0/src/Port_Siul2.o 

C_DEPS += \
./src/Port_TS_T2D35M10I1R0/src/Port.d \
./src/Port_TS_T2D35M10I1R0/src/Port_Ipw.d \
./src/Port_TS_T2D35M10I1R0/src/Port_Siul2.d 


# Each subdirectory must supply rules for building sources it contributes
src/Port_TS_T2D35M10I1R0/src/Port.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Port_TS_T2D35M10I1R0/src/Port.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Port_TS_T2D35M10I1R0/src/Port_Ipw.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Port_TS_T2D35M10I1R0/src/Port_Ipw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Port_TS_T2D35M10I1R0/src/Port_Siul2.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Port_TS_T2D35M10I1R0/src/Port_Siul2.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


