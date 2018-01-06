################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\MyMessageHandler.cpp \
..\MyPreConnectHandler.cpp \
..\XSerialTestMaster.cpp 

LINK_OBJ += \
.\MyMessageHandler.cpp.o \
.\MyPreConnectHandler.cpp.o \
.\XSerialTestMaster.cpp.o 

CPP_DEPS += \
.\MyMessageHandler.cpp.d \
.\MyPreConnectHandler.cpp.d \
.\XSerialTestMaster.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
MyMessageHandler.cpp.o: ..\MyMessageHandler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

MyPreConnectHandler.cpp.o: ..\MyPreConnectHandler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

XSerialTestMaster.cpp.o: ..\XSerialTestMaster.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


