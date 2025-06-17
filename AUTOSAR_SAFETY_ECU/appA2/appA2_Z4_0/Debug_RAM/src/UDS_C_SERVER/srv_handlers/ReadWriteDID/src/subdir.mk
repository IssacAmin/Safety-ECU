################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/DID_util.c \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x22_ReadDID.c \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x2E_WriteDID.c 

OBJS += \
./src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/DID_util.o \
./src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x22_ReadDID.o \
./src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x2E_WriteDID.o 

C_DEPS += \
./src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/DID_util.d \
./src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x22_ReadDID.d \
./src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x2E_WriteDID.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/DID_util.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/DID_util.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/DID_util.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x22_ReadDID.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x22_ReadDID.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x22_ReadDID.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x2E_WriteDID.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x2E_WriteDID.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/srv_handlers/ReadWriteDID/src/SID_0x2E_WriteDID.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


