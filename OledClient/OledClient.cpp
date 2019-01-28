#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
//#define MPRINT_ON
#include <tools.h>
#include <WQDefines.h>
#include <WQReader.h>
#include "OledDisplay.h"
#include "bitmaps.h"


#define PIN_MQ_NEWDATA 2  // HIGH  ...data available
typedef enum {game_init=0,game_start,key_yellow,key_blue,key_green,key_red,key_white} tMqCmd;

OledDisplay oledDisplay;
#define I2C_ADDRESS_OLED_MASTER  0x08
int freeRam2();
bool receivedData =false;

WQReader wqReader(PIN_MQ_NEWDATA, I2C_ADDRESS_OLED_MASTER);
tWQMessage wqMessage;

void setup() {
	Serial.begin(9600);

	XPRINTLNS("");
	XPRINTLNS("OLED CLIENT V1");
	MPRINTLN("MPRINT IS ON");
	wqReader.init();
	oledDisplay.init();
	oledDisplay.drawBitMap(0, 0, bmp_startscreen, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, BLACK,WHITE);

	XPRINTFREE;
	Serial.flush();
}

// The loop function is called in an endless loop
void loop(){
	receivedData=false;
	if (wqReader.process(wqMessage)) {
		MPRINTLN("OLED CLient : DATA Available PIN2 ");
		MPRINTLNSVAL("OLED CLient : CMD: ", wqMessage.cmd);
		switch  (wqMessage.cmd) {
		/*	case tMqCmd::CMD_UPDATE:
				MPRINTLNS("OLED CLient : CMD_UPDATE");
				oledDisplay.update();
				break;

			case tMqCmd::CMD_CLEAR:
				MPRINTLNS("OLED CLient : CMD_CLEAR");
				oledDisplay.clear();
				break;
			case tMqCmd::CMD_LINE:
				MPRINTLNS("OLED CLient : CMD_LINE");
				oledDisplay.drawLine(pPar->a.p0.x1,pPar->a.p1.y1, pPar->a.p2.x2, pPar->a.p3.y2, pPar->a.color);
				break;
			case tMqCmd::CMD_RECTANGL:
				MPRINTLNS("OLED CLient : CMD_RECTANG");
				oledDisplay.drawRectangle(pPar->a.p0.x1,pPar->a.p1.y1, pPar->a.p2.x2, pPar->a.p3.y2, pPar->a.color);
				break;

			case tMqCmd::CMD_CIRCLE:
				MPRINTLNS("OLED CLient : CMD_CIRCLE");
				oledDisplay.drawCircle(pPar->a.p0.x1,pPar->a.p1.y1, pPar->a.p2.r, pPar->a.color);
				break;
*/
			case tMqCmd::game_init: // main Scree
				MPRINTLNS("OLED CLient:  tMqCmd::game_init");
				oledDisplay.drawBitMap(0, 0, bmp_startscreen, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, BLACK,WHITE);
				break;
			case tMqCmd::game_start: // main Scree
				MPRINTLNS("OLED CLient : tMqCmd::game_start");
				oledDisplay.drawBitMap(0, 0, bmp_screen_gameselect, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT, BLACK,WHITE);
				break;
			}

	}else {
		//MPRINTLN("OLED CLient : NO DATA");
	}

}

int freeRam2() {
	extern int __heap_start, *__brkval;
	int v;
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
