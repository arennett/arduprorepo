//#define DPRINT_ON     //...debugging level
#define MPRINT_ON     //...monitoring level

#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>
#include "MyMessageHandler.h"
#include "MyPreConnectHandler.h"


using namespace SerialMsgLib;

SoftSerialPort *pSerialPort1, *pSerialPort2;
tSerialHeader sheader;

byte data[] = { 55, 99, 88, 44 }; // some data
SerialNodeNet* pNet;
bool conditionsOK = false;
MyMessageHandler messageHandler;
MyPreConnectHandler preConnectHandler;

unsigned long timeStamp = 0;
unsigned long now = 0;
unsigned long testdata1 = 0;

tStamp delta;

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################setup SerialTestMaster (4)######################################");

	pNet=SerialNodeNet::init(4);

	pSerialPort1 = new SoftSerialPort(8, 9, 5);
	pSerialPort1->createDataBuffer(sizeof(unsigned long));
	pSerialPort1->begin(9600);


	pNet->setOnMessageHandler(&messageHandler);
	pNet->setOnPreConnectHandler(&preConnectHandler);

	pNet->createNode(1, true, 7, 1);

	XPRINTFREE;
}

#define SEND_PERIOD 500
void loop() {

	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}

	delta = millis()-timeStamp;

	if ((delta) > SEND_PERIOD) {
		    SerialNode* pNode = pNet->getNode(1);
			for (int i=0; i < 1; i++) {
				pNode->send(CMD_ARQ, 0, 0, (byte*) &++testdata1, sizeof(unsigned long));
				XPRINTSVAL("send: ",pNode->getId());XPRINTSVAL(" data : ", testdata1);XPRINTLNSVAL(" delay ",delta-SEND_PERIOD);

			}
			timeStamp=now;
	}
}
