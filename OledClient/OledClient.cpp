#include "Arduino.h"
#include <Wire.h>
#include "OledDisplay.h"
#include <OledMessage.h>
#include <tools.h>
#include "bitmaps.h"

#define PIN_OLED_DATA 2  // HIGH  ...data available
OledDisplay oledDisplay;
#define I2C_ADDRESS_OLED_MASTER  0x08
int freeRam2();

OledMessage oledMessage;
void setup() {
	Serial.begin(9600);

	XPRINTLNS("");
	XPRINTLNS("OLED CLIENT");

	pinMode(PIN_OLED_DATA, INPUT);

	oledDisplay.init();

	XPRINTFREE;
	Serial.flush();
}

// The loop function is called in an endless loop
void loop() {

	if (digitalRead(PIN_OLED_DATA) == HIGH) {
		MPRINTLN("OLED CLient : DATA Available PIN2 ");

		Wire.requestFrom(I2C_ADDRESS_OLED_MASTER, OLEDMESSAGE_SIZE); // request 6 bytes from slave device #8
		byte idx = 0;
		MPRINTLNSVAL("OLED CLient : BYTES Available WIRE : ",Wire.available());


		while (Wire.available() && idx < OLEDMESSAGE_SIZE) { // slave may send less than requested
			oledMessage.buffer[idx] = Wire.read(); // receive a byte as character
			MPRINTLNSVAL("OLED CLient : READ idx: ", oledMessage.buffer[idx]);
			++idx;
		}

		if (idx > 0) {
			MPRINTLNSVAL("OLED CLient : cmd: ",oledMessage.getCmd());
			tParams* pPar=oledMessage.getTParams();
			switch  (oledMessage.getCmd()) {
			case tOledCmd::CMD_UPDATE:
				MPRINTLNS("OLED CLient : CMD_UPDATE");
				oledDisplay.update();
				break;

			case tOledCmd::CMD_CLEAR:
				MPRINTLNS("OLED CLient : CMD_CLEAR");
				oledDisplay.clear();
				break;
			case tOledCmd::CMD_LINE:
				MPRINTLNS("OLED CLient : CMD_LINE");
				oledDisplay.drawLine(pPar->a.p0.x1,pPar->a.p1.y1, pPar->a.p2.x2, pPar->a.p3.y2, pPar->a.color);
				break;
			case tOledCmd::CMD_RECTANGL:
				MPRINTLNS("OLED CLient : CMD_RECTANG");
				oledDisplay.drawRectangle(pPar->a.p0.x1,pPar->a.p1.y1, pPar->a.p2.x2, pPar->a.p3.y2, pPar->a.color);
				break;

			case tOledCmd::CMD_CIRCLE:
				MPRINTLNS("OLED CLient : CMD_CIRCLE");
				oledDisplay.drawCircle(pPar->a.p0.x1,pPar->a.p1.y1, pPar->a.p2.r, pPar->a.color);
				break;

			case tOledCmd::CMD_BMP_START: // main Scree
				MPRINTLNS("OLED CLient : CMD_BMP_START");
				oledDisplay.drawBitMap(0, 0, bmp_startscreen, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, BLACK,WHITE);
				break;
			case tOledCmd::CMD_BMP_GAME_SELECT: // main Scree
				MPRINTLNS("OLED CLient : CMD_BMP_GAME_SELECT");
				oledDisplay.drawBitMap(0, 0, bmp_screen_gameselect, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, BLACK,WHITE);
				break;
			}
		}

	}else {
		MPRINTLN("OLED CLient : NO DATA");
	}

}

int freeRam2() {
	extern int __heap_start, *__brkval;
	int v;
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
