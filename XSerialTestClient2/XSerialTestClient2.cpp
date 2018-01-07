#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>
#include "MyMessageHandler.h"
#include "MyPreConnectHandler.h"
#include <SoftwareSerial.h>
#include <SerialPort.h>
#include"DummySerialPort.h"


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
	MPRINTLNS("################################ setup SerialTestClient (12) ######################################");
	pNet=SerialNodeNet::init(12);
	pSerialPort = new SoftSerialPort(8, 9, 10);
	pSerialPort->createDataBuffer(sizeof(unsigned long));
	pSerialPort->begin(9600);
	pNet->setOnMessageHandler(&messageHandler);
	pNet->setOnPreConnectHandler(&preConnectHandler);
	//pNet->createNode(1, false, 10, 4);
	//pNet->createNode(2, false, 10, 5);
	pNet->createNode(3, false, 11, 3);

	XPRINTFREE;
    Serial.flush();



}

#define SEND_PERIOD 200
void loop() {

	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}




}

