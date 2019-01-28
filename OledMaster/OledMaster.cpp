#include "Arduino.h"
#include <Wire.h>
#include <tools.h>
#include <WQDefines.h>
#include <WQWriter.h>

#define PIN_MQ_NEWDATA 2  // HIGH  ...data available
#define I2C_ADDRESS  0x08

typedef enum {game_init=0,game_start,key_yellow,key_blue,key_green,key_red,key_white} tMqCmd;

WQWriter wqWriter;

void onRequestHandler();


//The setup function is called once at startup of the sketch
void setup()
{
	Serial.begin(9600);
	XPRINTLNS("");
	XPRINTLNS("OledMaster::setup");
	MPRINTLN("OledMaster:MPRINT IS ON");
	wqWriter.init(PIN_MQ_NEWDATA, I2C_ADDRESS, onRequestHandler);



	tWQMessage wqMess;
	memset(&wqMess,0,sizeof(tWQMessage));
	MPRINTLN("OledMaster::setup: enqueue some messages now");
	XFLUSH;
	wqMess.cmd = tMqCmd::game_init;
	wqWriter.write(wqMess);
	wqMess.cmd = tMqCmd::game_start;
	wqWriter.write(wqMess);
	wqMess.cmd = tMqCmd::key_yellow;
	wqWriter.write(wqMess);
	wqMess.cmd = tMqCmd::key_blue;
	wqWriter.write(wqMess);
	wqMess.cmd = tMqCmd::key_green;
	wqWriter.write(wqMess);
	wqMess.cmd = tMqCmd::key_red;
	wqWriter.write(wqMess);
	wqMess.cmd = tMqCmd::key_white;
	wqWriter.write(wqMess);
	MPRINTLN("OledMaster::setup: messages queued");

	XFLUSH;

	// Add your initialization code here
}

// The loop function is called in an endless loop
int i =0;
void loop()
{

	/*pMessage = new OledMessage(tOledCmd::CMD_CLEAR);
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
	}*/
	//delay(30);


//Add your repeated code here
}

void onRequestHandler() {

	wqWriter.onRequestEvent();
	XPRINTFREE;
}

