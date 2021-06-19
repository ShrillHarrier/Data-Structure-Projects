################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DoubleHash.cpp \
../Person.cpp \
../openhttest.cpp \
../orderedhttest.cpp 

OBJS += \
./DoubleHash.o \
./Person.o \
./openhttest.o \
./orderedhttest.o 

CPP_DEPS += \
./DoubleHash.d \
./Person.d \
./openhttest.d \
./orderedhttest.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


