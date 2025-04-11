################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/ReadWriteDID/DID_util.c \
../src/UDS/Service_Handlers/ReadWriteDID/SID_0x22_ReadDID.c \
../src/UDS/Service_Handlers/ReadWriteDID/SID_0x2E_WriteDID.c \
../src/UDS/Service_Handlers/ReadWriteDID/uds_DID_cfg.c 

OBJS += \
./src/UDS/Service_Handlers/ReadWriteDID/DID_util.o \
./src/UDS/Service_Handlers/ReadWriteDID/SID_0x22_ReadDID.o \
./src/UDS/Service_Handlers/ReadWriteDID/SID_0x2E_WriteDID.o \
./src/UDS/Service_Handlers/ReadWriteDID/uds_DID_cfg.o 

C_DEPS += \
./src/UDS/Service_Handlers/ReadWriteDID/DID_util.d \
./src/UDS/Service_Handlers/ReadWriteDID/SID_0x22_ReadDID.d \
./src/UDS/Service_Handlers/ReadWriteDID/SID_0x2E_WriteDID.d \
./src/UDS/Service_Handlers/ReadWriteDID/uds_DID_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/ReadWriteDID/%.o: ../src/UDS/Service_Handlers/ReadWriteDID/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/ReadWriteDID/DID_util.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


