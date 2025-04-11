################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/UDS/Service_Handlers/TesterPresent/SID_0x3E_TesterPresent.c 

OBJS += \
./src/UDS/Service_Handlers/TesterPresent/SID_0x3E_TesterPresent.o 

C_DEPS += \
./src/UDS/Service_Handlers/TesterPresent/SID_0x3E_TesterPresent.d 


# Each subdirectory must supply rules for building sources it contributes
src/UDS/Service_Handlers/TesterPresent/%.o: ../src/UDS/Service_Handlers/TesterPresent/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/UDS/Service_Handlers/TesterPresent/SID_0x3E_TesterPresent.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


