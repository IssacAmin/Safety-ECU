################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/CanTp/src/CanTp_Cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/CanTp/src/CanTp_RX.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/CanTp/src/CanTp_TX.c 

OBJS += \
./src/src/CanTp_Cfg.o \
./src/src/CanTp_RX.o \
./src/src/CanTp_TX.o 

C_DEPS += \
./src/src/CanTp_Cfg.d \
./src/src/CanTp_RX.d \
./src/src/CanTp_TX.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/CanTp_Cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/CanTp/src/CanTp_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/src/CanTp_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/src/CanTp_RX.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/CanTp/src/CanTp_RX.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/src/CanTp_RX.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/src/CanTp_TX.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/CanTp/src/CanTp_TX.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/src/CanTp_TX.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


