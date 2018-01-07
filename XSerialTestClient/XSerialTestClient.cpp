#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>
#include "MyMessageHandler.h"
#include "MyPreConnectHandler.h"
#include <SoftwareSerial.h>
#include <SerialPort.h>
//#include"DummySerialPort.h"

SoftSerialPort* pSerialPort;
tSerialHeader sheader;

//byte data[] = { 55, 99, 88, 44 }; // some data
SerialNodeNet* pNet;
MyMessageHandler messageHandler;
MyPreConnectHandler preConnectHandler;
tStamp timeStamp =0;
unsigned long testdata1 =0;

unsigned long millis_start = millis();

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################ setup SerialTestClient (11) ######################################");
	pNet=SerialNodeNet::init(11);
	AcbList::getInstance()->setAktId(1000);
	pSerialPort = new SoftSerialPort(10, 11, 10);
	pSerialPort->createDataBuffer(sizeof(unsigned long));
	pSerialPort->begin(9600);
	pNet->setOnMessageHandler(&messageHandler);
	pNet->setOnPreConnectHandler(&preConnectHandler);
	//pNode1 = pNet->createNode(1, false, 10, 1);
	//pNode2 = pNet->createNode(2, false, 10, 2);
	pNet->createNode(3, true, 12, 3);
	XPRINTFREE;
    Serial.flush();



}
#define SEND_PERIOD 500
void loop() {

	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}
	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}

	tStamp now = millis();

	tStamp delta =now - timeStamp;

	if ((delta) > SEND_PERIOD) {
		SerialNode* pNode=pNet->getNode(3);
		pNode->send(CMD_ARQ, 0, 0, (byte*) &++testdata1, sizeof(unsigned long));
		timeStamp = now;
	}

}

