################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\User\Documents\Arduino\libraries\Bounce2-master\Bounce2.cpp 

LINK_OBJ += \
.\libraries\Bounce2-master\Bounce2.cpp.o 

CPP_DEPS += \
.\libraries\Bounce2-master\Bounce2.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Bounce2-master\Bounce2.cpp.o: C:\Users\User\Documents\Arduino\libraries\Bounce2-master\Bounce2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Users\User\Documents\Arduino\libraries\Bounce2-master" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


