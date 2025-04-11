################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/ECUReset/SID_0x11_ECUReset.c \
../src/UDS/Service_Handlers/ECUReset/uds_ECUReset_cfg.c 

OBJS += \
./src/UDS/Service_Handlers/ECUReset/SID_0x11_ECUReset.o \
./src/UDS/Service_Handlers/ECUReset/uds_ECUReset_cfg.o 

C_DEPS += \
./src/UDS/Service_Handlers/ECUReset/SID_0x11_ECUReset.d \
./src/UDS/Service_Handlers/ECUReset/uds_ECUReset_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/ECUReset/%.o: ../src/UDS/Service_Handlers/ECUReset/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/ECUReset/SID_0x11_ECUReset.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


