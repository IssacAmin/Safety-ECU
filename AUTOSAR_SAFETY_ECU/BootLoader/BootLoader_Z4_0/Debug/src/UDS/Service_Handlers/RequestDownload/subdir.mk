################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/RequestDownload/SID_0x34_RequestDownload.c \
../src/UDS/Service_Handlers/RequestDownload/SID_0x36_TransferData.c \
../src/UDS/Service_Handlers/RequestDownload/SID_0x37_RequestTransferExit.c 

OBJS += \
./src/UDS/Service_Handlers/RequestDownload/SID_0x34_RequestDownload.o \
./src/UDS/Service_Handlers/RequestDownload/SID_0x36_TransferData.o \
./src/UDS/Service_Handlers/RequestDownload/SID_0x37_RequestTransferExit.o 

C_DEPS += \
./src/UDS/Service_Handlers/RequestDownload/SID_0x34_RequestDownload.d \
./src/UDS/Service_Handlers/RequestDownload/SID_0x36_TransferData.d \
./src/UDS/Service_Handlers/RequestDownload/SID_0x37_RequestTransferExit.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/RequestDownload/%.o: ../src/UDS/Service_Handlers/RequestDownload/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/RequestDownload/SID_0x34_RequestDownload.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


