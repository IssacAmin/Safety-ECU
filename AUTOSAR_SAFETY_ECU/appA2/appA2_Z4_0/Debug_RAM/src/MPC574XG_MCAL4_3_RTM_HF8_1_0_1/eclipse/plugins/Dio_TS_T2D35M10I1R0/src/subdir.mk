################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio.c \
C:/Users/Fady/Downloads/Safety-ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio_Siul2.c 

OBJS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio.o \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio_Siul2.o 

C_DEPS += \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio.d \
./src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio_Siul2.d 


# Each subdirectory must supply rules for building sources it contributes
src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio.o: C:/Users/Fady/Downloads/Safety-ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio_Siul2.o: C:/Users/Fady/Downloads/Safety-ECU/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio_Siul2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Dio_TS_T2D35M10I1R0/src/Dio_Siul2.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


