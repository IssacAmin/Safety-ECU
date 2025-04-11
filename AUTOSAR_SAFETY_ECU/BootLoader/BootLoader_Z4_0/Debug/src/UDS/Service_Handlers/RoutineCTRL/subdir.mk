################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/RoutineCTRL/SID_0x31_RoutineCTRL.c \
../src/UDS/Service_Handlers/RoutineCTRL/uds_routine_cfg.c 

OBJS += \
./src/UDS/Service_Handlers/RoutineCTRL/SID_0x31_RoutineCTRL.o \
./src/UDS/Service_Handlers/RoutineCTRL/uds_routine_cfg.o 

C_DEPS += \
./src/UDS/Service_Handlers/RoutineCTRL/SID_0x31_RoutineCTRL.d \
./src/UDS/Service_Handlers/RoutineCTRL/uds_routine_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/RoutineCTRL/%.o: ../src/UDS/Service_Handlers/RoutineCTRL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/RoutineCTRL/SID_0x31_RoutineCTRL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


