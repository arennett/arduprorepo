#include "Arduino.h"
#include <Senso.h>
#include <tools.h>
#include <SerialMsgLib.h>
#include"OledDisplay.h"
//The setup function is called once at startup of the sketch
void  dataUpdate(byte *data , size_t len);
OledDisplay oledDisplay;
SensoMsg sMessage;
long connectionSpeed = 9600;
SerialRx serialRx(new SoftSerialPort(10, 11),30);

void setup() {
	Serial.begin(9600);
	MPRINTLNS("");
	MPRINTLNS("Setup Senso Display Client");
	oledDisplay.init();

	serialRx.begin(CONNECTION_SPPED_MASTER_TO_DISPLAY);

	serialRx.setUpdateCallback(dataUpdate);
	MPRINTFREE;

}

void dataUpdate(byte *data , size_t len) {

	SensoMsgHdr* pHdr = (SensoMsgHdr*)data;

	SensoMsg smsg* (*data);

	MPRINTSVAL("message received ,len: " ,len);
	MPRINTSVAL("cmd: ",pHdr->cmd);
	MPRINTSVAL("subcmd: ",pHdr->subcmd);

	if (pHdr->cmd==CMD_SET_DSP) {
		if(pHdr->subcmd==CMDSUB_SET_DSP_CLEAR) {
			oledDisplay.clear();
		}
		if(pHdr->subcmd==CMDSUB_SET_DSP_RECT) {
			oledDisplay.testdrawrect();
		}
	}
	MPRINTFREE;

}

// The loop function is called in an endless loop
void loop() {

	serialRx.readNext();

}
