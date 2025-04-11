################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/uds_NR_Handler.c \
../src/UDS/uds_helpers.c \
../src/UDS/uds_server.c \
../src/UDS/uds_server_q.c \
../src/UDS/uds_sid_cfg.c \
../src/UDS/uds_supplier_manufacturer_cfg.c 

OBJS += \
./src/UDS/uds_NR_Handler.o \
./src/UDS/uds_helpers.o \
./src/UDS/uds_server.o \
./src/UDS/uds_server_q.o \
./src/UDS/uds_sid_cfg.o \
./src/UDS/uds_supplier_manufacturer_cfg.o 

C_DEPS += \
./src/UDS/uds_NR_Handler.d \
./src/UDS/uds_helpers.d \
./src/UDS/uds_server.d \
./src/UDS/uds_server_q.d \
./src/UDS/uds_sid_cfg.d \
./src/UDS/uds_supplier_manufacturer_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/%.o: ../src/UDS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/uds_NR_Handler.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


