################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cache.cpp \
../src/Tools.cpp \
../src/cacheSimulator.cpp 

OBJS += \
./src/Cache.o \
./src/Tools.o \
./src/cacheSimulator.o 

CPP_DEPS += \
./src/Cache.d \
./src/Tools.d \
./src/cacheSimulator.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


