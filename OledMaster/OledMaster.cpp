#include "Arduino.h"
#include <Wire.h>
#include <tools.h>
#include "OledMessage.h"
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
	XPRINTLN("");
	XPRINTLN("OLED MASTER");
	pinMode(PIN_OLED_DATA,OUTPUT);
	Wire.begin(I2C_ADDRESS);                // join i2c bus with address #8
	Wire.onRequest(onRequestEvent);
	XPRINTFREE;
// Add your initialization code here
}

// The loop function is called in an endless loop
int i =0;
void loop()
{

	pMessage = new OledMessage(tOledCmd::CMD_CLEAR);
	messageQueue.push(pMessage);

	byte params[]= {4+i,6+i,20+i,40+i,WHITE};

	pMessage = new OledMessage(tOledCmd::CMD_RECTANGL,params,5);
	messageQueue.push(pMessage);

	byte params2[] = {60+i,30+i,20+i,WHITE};

	pMessage = new OledMessage(tOledCmd::CMD_CIRCLE,params2,4);
	messageQueue.push(pMessage);

	pMessage = new OledMessage(tOledCmd::CMD_UPDATE);
	messageQueue.push(pMessage);

	i++;

	if (i > 40) {
		i=0;
	}
	delay(200);


//Add your repeated code here
}

void onRequestEvent() {
	MPRINTLN("onRequestEvent()");
	if (!messageQueue.isEmpty()){
		OledMessage* pMessage = messageQueue.pop();
		for (int i= 0; i < pMessage->getParamsSize()+2 ;i++) {
			MPRINTLNSVAL("WRITE :" , pMessage->buffer[i]);
		}
		Wire.write(pMessage->buffer, OLEDMESSAGE_SIZE); // respond with message of 6 bytes

		delete pMessage;
	}
}

