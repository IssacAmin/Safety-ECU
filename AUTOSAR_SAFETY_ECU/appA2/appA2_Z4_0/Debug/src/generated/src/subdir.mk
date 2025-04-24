################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Dio_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Mcu_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Mcu_PBcfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Port_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Port_PBcfg.c 

OBJS += \
./src/generated/src/Dio_Cfg.o \
./src/generated/src/Mcu_Cfg.o \
./src/generated/src/Mcu_PBcfg.o \
./src/generated/src/Port_Cfg.o \
./src/generated/src/Port_PBcfg.o 

C_DEPS += \
./src/generated/src/Dio_Cfg.d \
./src/generated/src/Mcu_Cfg.d \
./src/generated/src/Mcu_PBcfg.d \
./src/generated/src/Port_Cfg.d \
./src/generated/src/Port_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/generated/src/Dio_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Dio_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/generated/src/Dio_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/generated/src/Mcu_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Mcu_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/generated/src/Mcu_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/generated/src/Mcu_PBcfg.o: C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Mcu_PBcfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/generated/src/Mcu_PBcfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/generated/src/Port_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Port_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/generated/src/Port_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/generated/src/Port_PBcfg.o: C:/Users/Fady/Downloads/SafetyECUProject/appAConfig/output/generated/src/Port_PBcfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/generated/src/Port_PBcfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


