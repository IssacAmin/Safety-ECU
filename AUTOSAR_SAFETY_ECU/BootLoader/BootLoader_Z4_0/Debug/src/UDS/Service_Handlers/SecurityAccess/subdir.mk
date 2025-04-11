################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/SecurityAccess/SID_0x27_SecurityAccess.c \
../src/UDS/Service_Handlers/SecurityAccess/uds_securityLvl_cfg.c 

OBJS += \
./src/UDS/Service_Handlers/SecurityAccess/SID_0x27_SecurityAccess.o \
./src/UDS/Service_Handlers/SecurityAccess/uds_securityLvl_cfg.o 

C_DEPS += \
./src/UDS/Service_Handlers/SecurityAccess/SID_0x27_SecurityAccess.d \
./src/UDS/Service_Handlers/SecurityAccess/uds_securityLvl_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/SecurityAccess/%.o: ../src/UDS/Service_Handlers/SecurityAccess/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/SecurityAccess/SID_0x27_SecurityAccess.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


