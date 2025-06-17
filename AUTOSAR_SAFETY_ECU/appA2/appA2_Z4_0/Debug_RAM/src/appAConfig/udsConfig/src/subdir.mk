################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_DID_cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_ECUReset_cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_routine_cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_securityLvl_cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_session_cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_sid_cfg.c \
C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_supplier_manufacturer_cfg.c 

OBJS += \
./src/appAConfig/udsConfig/src/uds_DID_cfg.o \
./src/appAConfig/udsConfig/src/uds_ECUReset_cfg.o \
./src/appAConfig/udsConfig/src/uds_routine_cfg.o \
./src/appAConfig/udsConfig/src/uds_securityLvl_cfg.o \
./src/appAConfig/udsConfig/src/uds_session_cfg.o \
./src/appAConfig/udsConfig/src/uds_sid_cfg.o \
./src/appAConfig/udsConfig/src/uds_supplier_manufacturer_cfg.o 

C_DEPS += \
./src/appAConfig/udsConfig/src/uds_DID_cfg.d \
./src/appAConfig/udsConfig/src/uds_ECUReset_cfg.d \
./src/appAConfig/udsConfig/src/uds_routine_cfg.d \
./src/appAConfig/udsConfig/src/uds_securityLvl_cfg.d \
./src/appAConfig/udsConfig/src/uds_session_cfg.d \
./src/appAConfig/udsConfig/src/uds_sid_cfg.d \
./src/appAConfig/udsConfig/src/uds_supplier_manufacturer_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/appAConfig/udsConfig/src/uds_DID_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_DID_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_DID_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appAConfig/udsConfig/src/uds_ECUReset_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_ECUReset_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_ECUReset_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appAConfig/udsConfig/src/uds_routine_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_routine_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_routine_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appAConfig/udsConfig/src/uds_securityLvl_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_securityLvl_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_securityLvl_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appAConfig/udsConfig/src/uds_session_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_session_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_session_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appAConfig/udsConfig/src/uds_sid_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_sid_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_sid_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/appAConfig/udsConfig/src/uds_supplier_manufacturer_cfg.o: C:/Users/Fady/Downloads/Safety-ECU/AUTOSAR_SAFETY_ECU/appAConfig/udsConfig/src/uds_supplier_manufacturer_cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/appAConfig/udsConfig/src/uds_supplier_manufacturer_cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


