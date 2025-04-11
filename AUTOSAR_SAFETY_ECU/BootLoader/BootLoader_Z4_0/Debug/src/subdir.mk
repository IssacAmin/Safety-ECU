################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/OsVector.c \
../src/UDS_utils.c \
../src/flags.c \
../src/main.c 

S_UPPER_SRCS += \
../src/intc_sw_handlers.S 

OBJS += \
./src/OsVector.o \
./src/UDS_utils.o \
./src/flags.o \
./src/intc_sw_handlers.o \
./src/main.o 

C_DEPS += \
./src/OsVector.d \
./src/UDS_utils.d \
./src/flags.d \
./src/main.d 


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


