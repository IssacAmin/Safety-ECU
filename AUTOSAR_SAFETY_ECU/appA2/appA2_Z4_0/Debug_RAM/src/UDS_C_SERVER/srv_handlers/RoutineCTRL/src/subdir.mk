################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/SID_0x31_RoutineCTRL.c 

OBJS += \
./src/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/SID_0x31_RoutineCTRL.o 

C_DEPS += \
./src/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/SID_0x31_RoutineCTRL.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/SID_0x31_RoutineCTRL.o: C:/Users/Fady/Downloads/Safety-ECU/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/SID_0x31_RoutineCTRL.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS_C_SERVER/srv_handlers/RoutineCTRL/src/SID_0x31_RoutineCTRL.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


