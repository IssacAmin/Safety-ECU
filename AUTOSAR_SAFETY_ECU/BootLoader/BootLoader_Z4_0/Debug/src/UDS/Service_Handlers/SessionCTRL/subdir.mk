################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/SessionCTRL/SID_0x10_SessionCtrl.c \
../src/UDS/Service_Handlers/SessionCTRL/uds_session_cfg.c 

OBJS += \
./src/UDS/Service_Handlers/SessionCTRL/SID_0x10_SessionCtrl.o \
./src/UDS/Service_Handlers/SessionCTRL/uds_session_cfg.o 

C_DEPS += \
./src/UDS/Service_Handlers/SessionCTRL/SID_0x10_SessionCtrl.d \
./src/UDS/Service_Handlers/SessionCTRL/uds_session_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/SessionCTRL/%.o: ../src/UDS/Service_Handlers/SessionCTRL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/SessionCTRL/SID_0x10_SessionCtrl.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


