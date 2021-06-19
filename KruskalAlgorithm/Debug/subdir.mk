################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Disjoint.cpp \
../Edge.cpp \
../Graph.cpp \
../InvalidArgument.cpp \
../LinkedList.cpp \
../Node.cpp \
../kruskaltest.cpp 

OBJS += \
./Disjoint.o \
./Edge.o \
./Graph.o \
./InvalidArgument.o \
./LinkedList.o \
./Node.o \
./kruskaltest.o 

CPP_DEPS += \
./Disjoint.d \
./Edge.d \
./Graph.d \
./InvalidArgument.d \
./LinkedList.d \
./Node.d \
./kruskaltest.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


