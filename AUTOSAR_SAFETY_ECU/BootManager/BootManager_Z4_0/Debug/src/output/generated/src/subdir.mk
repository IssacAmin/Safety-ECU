################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Dio_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Fls_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Fls_PBcfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Mcu_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Mcu_PBcfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Port_Cfg.c \
C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Port_PBcfg.c 

OBJS += \
./src/output/generated/src/Dio_Cfg.o \
./src/output/generated/src/Fls_Cfg.o \
./src/output/generated/src/Fls_PBcfg.o \
./src/output/generated/src/Mcu_Cfg.o \
./src/output/generated/src/Mcu_PBcfg.o \
./src/output/generated/src/Port_Cfg.o \
./src/output/generated/src/Port_PBcfg.o 

C_DEPS += \
./src/output/generated/src/Dio_Cfg.d \
./src/output/generated/src/Fls_Cfg.d \
./src/output/generated/src/Fls_PBcfg.d \
./src/output/generated/src/Mcu_Cfg.d \
./src/output/generated/src/Mcu_PBcfg.d \
./src/output/generated/src/Port_Cfg.d \
./src/output/generated/src/Port_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/output/generated/src/Dio_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Dio_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Dio_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/output/generated/src/Fls_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Fls_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Fls_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/output/generated/src/Fls_PBcfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Fls_PBcfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Fls_PBcfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/output/generated/src/Mcu_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Mcu_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Mcu_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/output/generated/src/Mcu_PBcfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Mcu_PBcfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Mcu_PBcfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/output/generated/src/Port_Cfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Port_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Port_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/output/generated/src/Port_PBcfg.o: C:/Users/Fady/Downloads/SafetyECUProject/BootmanagerConfig/output/generated/src/Port_PBcfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/output/generated/src/Port_PBcfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


