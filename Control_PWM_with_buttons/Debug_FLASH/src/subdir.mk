################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FTM.c \
../src/FlexCAN.c \
../src/LPIT.c \
../src/LPSPI.c \
../src/LPUART.c \
../src/NVIC.c \
../src/PCC.c \
../src/PORT_GPIO.c \
../src/SCG.c \
../src/SIM.c \
../src/funtion.c \
../src/ledMax7219.c \
../src/main.c 

OBJS += \
./src/FTM.o \
./src/FlexCAN.o \
./src/LPIT.o \
./src/LPSPI.o \
./src/LPUART.o \
./src/NVIC.o \
./src/PCC.o \
./src/PORT_GPIO.o \
./src/SCG.o \
./src/SIM.o \
./src/funtion.o \
./src/ledMax7219.o \
./src/main.o 

C_DEPS += \
./src/FTM.d \
./src/FlexCAN.d \
./src/LPIT.d \
./src/LPSPI.d \
./src/LPUART.d \
./src/NVIC.d \
./src/PCC.d \
./src/PORT_GPIO.d \
./src/SCG.d \
./src/SIM.d \
./src/funtion.d \
./src/ledMax7219.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/FTM.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


