################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.c \
D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.c \
D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.c 

OBJS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.o \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.o \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.o 

C_DEPS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.d \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.d \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.d 


# Each subdirectory must supply rules for building sources it contributes
src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.o: D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.o: D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Ipw.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.o: D:/eJad_GP/SDV-SOTA/ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Port_TS_T2D35M10I1R0/src/Port_Siul2.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


