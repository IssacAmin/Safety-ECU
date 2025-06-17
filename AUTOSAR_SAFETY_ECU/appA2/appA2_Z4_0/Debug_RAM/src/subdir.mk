################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/OsVector.c \
../src/UDS_utils.c \
../src/eraseMemoryRoutine.c \
../src/main.c \
../src/securityLevelsFunctions.c \
../src/udsIf.c 

S_UPPER_SRCS += \
../src/intc_sw_handlers.S 

OBJS += \
./src/OsVector.o \
./src/UDS_utils.o \
./src/eraseMemoryRoutine.o \
./src/intc_sw_handlers.o \
./src/main.o \
./src/securityLevelsFunctions.o \
./src/udsIf.o 

C_DEPS += \
./src/OsVector.d \
./src/UDS_utils.d \
./src/eraseMemoryRoutine.d \
./src/main.d \
./src/securityLevelsFunctions.d \
./src/udsIf.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	powerpc-eabivle-gcc "@src/OsVector.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	powerpc-eabivle-gcc "@src/intc_sw_handlers.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


