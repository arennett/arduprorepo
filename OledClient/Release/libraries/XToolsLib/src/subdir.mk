################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\User\git\ardulibrepo\XToolsLib\src\OledMessage.cpp \
C:\Users\User\git\ardulibrepo\XToolsLib\src\tools.cpp 

LINK_OBJ += \
.\libraries\XToolsLib\src\OledMessage.cpp.o \
.\libraries\XToolsLib\src\tools.cpp.o 

CPP_DEPS += \
.\libraries\XToolsLib\src\OledMessage.cpp.d \
.\libraries\XToolsLib\src\tools.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\XToolsLib\src\OledMessage.cpp.o: C:\Users\User\git\ardulibrepo\XToolsLib\src\OledMessage.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\eightanaloginputs" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\Wire" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\Wire\src" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\SPI" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\SPI\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

libraries\XToolsLib\src\tools.cpp.o: C:\Users\User\git\ardulibrepo\XToolsLib\src\tools.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\tools\avr-gcc\5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR     -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\cores\arduino" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\variants\eightanaloginputs" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\Wire" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\Wire\src" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\SPI" -I"C:\sloeber\sloeber4.3.1\arduinoPlugin\packages\arduino\hardware\avr\1.6.23\libraries\SPI\src" -I"C:\Users\User\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\User\git\ardulibrepo\XToolsLib" -I"C:\Users\User\git\ardulibrepo\XToolsLib\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


