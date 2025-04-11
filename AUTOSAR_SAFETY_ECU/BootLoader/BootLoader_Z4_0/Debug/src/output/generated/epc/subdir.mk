################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/SafetyECUProject/bootloaderOsConfig/output/generated/epc/Os_cfg.c 

OBJS += \
./src/output/generated/epc/Os_cfg.o 

C_DEPS += \
./src/output/generated/epc/Os_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/output/generated/epc/Os_cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/bootloaderOsConfig/output/generated/epc/Os_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/epc/Os_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


