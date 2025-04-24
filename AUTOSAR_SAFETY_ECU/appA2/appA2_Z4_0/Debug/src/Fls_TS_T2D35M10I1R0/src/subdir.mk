################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_Ac.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_Flash.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_Flash_Const.c \
C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_IPW.c 

OBJS += \
./src/Fls_TS_T2D35M10I1R0/src/Fls.o \
./src/Fls_TS_T2D35M10I1R0/src/Fls_Ac.o \
./src/Fls_TS_T2D35M10I1R0/src/Fls_Flash.o \
./src/Fls_TS_T2D35M10I1R0/src/Fls_Flash_Const.o \
./src/Fls_TS_T2D35M10I1R0/src/Fls_IPW.o 

C_DEPS += \
./src/Fls_TS_T2D35M10I1R0/src/Fls.d \
./src/Fls_TS_T2D35M10I1R0/src/Fls_Ac.d \
./src/Fls_TS_T2D35M10I1R0/src/Fls_Flash.d \
./src/Fls_TS_T2D35M10I1R0/src/Fls_Flash_Const.d \
./src/Fls_TS_T2D35M10I1R0/src/Fls_IPW.d 


# Each subdirectory must supply rules for building sources it contributes
src/Fls_TS_T2D35M10I1R0/src/Fls.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Fls_TS_T2D35M10I1R0/src/Fls.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Fls_TS_T2D35M10I1R0/src/Fls_Ac.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_Ac.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Fls_TS_T2D35M10I1R0/src/Fls_Ac.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Fls_TS_T2D35M10I1R0/src/Fls_Flash.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_Flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Fls_TS_T2D35M10I1R0/src/Fls_Flash.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Fls_TS_T2D35M10I1R0/src/Fls_Flash_Const.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_Flash_Const.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Fls_TS_T2D35M10I1R0/src/Fls_Flash_Const.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Fls_TS_T2D35M10I1R0/src/Fls_IPW.o: C:/Users/Fady/Downloads/SafetyECUProject/MPC574XG_MCAL4_3_RTM_HF8_1_0_1/eclipse/plugins/Fls_TS_T2D35M10I1R0/src/Fls_IPW.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/Fls_TS_T2D35M10I1R0/src/Fls_IPW.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


