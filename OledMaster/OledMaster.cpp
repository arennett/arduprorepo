#include "Arduino.h"
#include <Wire.h>
#include <tools.h>
#include "OledMessageQueue.h"

#define PIN_OLED_DATA 2  // HIGH  ...data available
#define I2C_ADDRESS  0x08
OledMessageQueue messageQueue(PIN_OLED_DATA);
void onRequestEvent();
OledMessage* pMessage=NULL;
//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	XPRINTLNS("");
	XPRINTLNS("OLED MASTER");
	pinMode(PIN_OLED_DATA,OUTPUT);
	Wire.begin(I2C_ADDRESS);                // join i2c bus with address #8
	Wire.onRequest(onRequestEvent);
	XPRINTFREE;
	pMessage = new OledMessage(tOledCmd::CMD_CLEAR);
	messageQueue.push(pMessage);
	pMessage = new OledMessage(tOledCmd::CMD_BMP_START);
	messageQueue.push(pMessage);
	pMessage = new OledMessage(tOledCmd::CMD_UPDATE);
	messageQueue.push(pMessage);
	delay(3000);
	pMessage = new OledMessage(tOledCmd::CMD_BMP_GAME_SELECT);
	messageQueue.push(pMessage);
	pMessage = new OledMessage(tOledCmd::CMD_UPDATE);
	messageQueue.push(pMessage);
	delay(3000);



// Add your initialization code here
}

// The loop function is called in an endless loop
int i =0;
void loop()
{

	pMessage = new OledMessage(tOledCmd::CMD_CLEAR);
	messageQueue.push(pMessage);

	byte params[]= {WHITE,4+i,6+i,20+i,40+i};

	pMessage = new OledMessage(tOledCmd::CMD_RECTANGL,params,5);
	messageQueue.push(pMessage);

	byte params2[] = {WHITE,60+i,30+i,20+i};

	pMessage = new OledMessage(tOledCmd::CMD_CIRCLE,params2,4);
	messageQueue.push(pMessage);

	byte params3[] = {WHITE,i,30+i,127,31};

		pMessage = new OledMessage(tOledCmd::CMD_LINE,params3,5);
		messageQueue.push(pMessage);

	pMessage = new OledMessage(tOledCmd::CMD_UPDATE);
	messageQueue.push(pMessage);

	i++;

	if (i > 40) {
		i=0;
	}
	delay(100);


//Add your repeated code here
}

void onRequestEvent() {
	MPRINTLNS("onRequestEvent()");
	if (!messageQueue.isEmpty()){
		OledMessage* pMessage = messageQueue.pop();
		for (int i= 0; i < pMessage->getParamsSize()+2 ;i++) {
			MPRINTLNSVAL("WRITE :" , pMessage->buffer[i]);
		}
		Wire.write(pMessage->buffer, OLEDMESSAGE_SIZE); // respond with message of 6 bytes

		delete pMessage;
	}
}

