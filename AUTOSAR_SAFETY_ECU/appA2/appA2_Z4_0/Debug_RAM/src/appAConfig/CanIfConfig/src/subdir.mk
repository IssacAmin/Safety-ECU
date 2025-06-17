################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/CanIfConfig/src/CanIf_Cfg.c 

OBJS += \
./src/appAConfig/CanIfConfig/src/CanIf_Cfg.o 

C_DEPS += \
./src/appAConfig/CanIfConfig/src/CanIf_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/appAConfig/CanIfConfig/src/CanIf_Cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/CanIfConfig/src/CanIf_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/CanIfConfig/src/CanIf_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


