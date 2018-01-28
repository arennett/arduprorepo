################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\AcbList.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\DummySerialPort.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\LcbList.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\OnMessageHandler.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\OnPreConnectHandler.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialMsg.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialNode.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialNodeNet.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialPort.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialPortRxTxMapper.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialRx.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialTx.cpp \
C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SoftSerialPort.cpp 

LINK_OBJ += \
.\libraries\XSerialMsgLib\src\AcbList.cpp.o \
.\libraries\XSerialMsgLib\src\DummySerialPort.cpp.o \
.\libraries\XSerialMsgLib\src\LcbList.cpp.o \
.\libraries\XSerialMsgLib\src\OnMessageHandler.cpp.o \
.\libraries\XSerialMsgLib\src\OnPreConnectHandler.cpp.o \
.\libraries\XSerialMsgLib\src\SerialMsg.cpp.o \
.\libraries\XSerialMsgLib\src\SerialNode.cpp.o \
.\libraries\XSerialMsgLib\src\SerialNodeNet.cpp.o \
.\libraries\XSerialMsgLib\src\SerialPort.cpp.o \
.\libraries\XSerialMsgLib\src\SerialPortRxTxMapper.cpp.o \
.\libraries\XSerialMsgLib\src\SerialRx.cpp.o \
.\libraries\XSerialMsgLib\src\SerialTx.cpp.o \
.\libraries\XSerialMsgLib\src\SoftSerialPort.cpp.o 

CPP_DEPS += \
.\libraries\XSerialMsgLib\src\AcbList.cpp.d \
.\libraries\XSerialMsgLib\src\DummySerialPort.cpp.d \
.\libraries\XSerialMsgLib\src\LcbList.cpp.d \
.\libraries\XSerialMsgLib\src\OnMessageHandler.cpp.d \
.\libraries\XSerialMsgLib\src\OnPreConnectHandler.cpp.d \
.\libraries\XSerialMsgLib\src\SerialMsg.cpp.d \
.\libraries\XSerialMsgLib\src\SerialNode.cpp.d \
.\libraries\XSerialMsgLib\src\SerialNodeNet.cpp.d \
.\libraries\XSerialMsgLib\src\SerialPort.cpp.d \
.\libraries\XSerialMsgLib\src\SerialPortRxTxMapper.cpp.d \
.\libraries\XSerialMsgLib\src\SerialRx.cpp.d \
.\libraries\XSerialMsgLib\src\SerialTx.cpp.d \
.\libraries\XSerialMsgLib\src\SoftSerialPort.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\XSerialMsgLib\src\AcbList.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\AcbList.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\DummySerialPort.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\DummySerialPort.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\LcbList.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\LcbList.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\OnMessageHandler.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\OnMessageHandler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\OnPreConnectHandler.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\OnPreConnectHandler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialMsg.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialMsg.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialNode.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialNode.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialNodeNet.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialNodeNet.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialPort.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialPort.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialPortRxTxMapper.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialPortRxTxMapper.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialRx.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialRx.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SerialTx.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SerialTx.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XSerialMsgLib\src\SoftSerialPort.cpp.o: C:\Users\User\git\ardulibrepo\XSerialMsgLib\src\SoftSerialPort.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.1\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\eightanaloginputs" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib" -I"C:\Users\User\git\ardulibrepo\XSerialMsgLib\src" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SoftwareSerial\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\SPI\src" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\sloeber4.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


