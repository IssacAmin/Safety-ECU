################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_NR_Handler.c \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_helpers.c \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_server.c \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_server_q.c 

OBJS += \
./src/UDS_C_SERVER/server_main/src/uds_NR_Handler.o \
./src/UDS_C_SERVER/server_main/src/uds_helpers.o \
./src/UDS_C_SERVER/server_main/src/uds_server.o \
./src/UDS_C_SERVER/server_main/src/uds_server_q.o 

C_DEPS += \
./src/UDS_C_SERVER/server_main/src/uds_NR_Handler.d \
./src/UDS_C_SERVER/server_main/src/uds_helpers.d \
./src/UDS_C_SERVER/server_main/src/uds_server.d \
./src/UDS_C_SERVER/server_main/src/uds_server_q.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS_C_SERVER/server_main/src/uds_NR_Handler.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_NR_Handler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/server_main/src/uds_NR_Handler.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UDS_C_SERVER/server_main/src/uds_helpers.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_helpers.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/server_main/src/uds_helpers.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UDS_C_SERVER/server_main/src/uds_server.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_server.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/server_main/src/uds_server.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/UDS_C_SERVER/server_main/src/uds_server_q.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/server_main/src/uds_server_q.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/server_main/src/uds_server_q.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


