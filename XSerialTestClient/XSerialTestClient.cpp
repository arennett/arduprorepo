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
SerialNode *pNode1;//, *pNode2,*pNode3;
SerialNodeNet* pNet;
MyMessageHandler messageHandler;
MyPreConnectHandler preConnectHandler;


unsigned long millis_start = millis();

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################ setup SerialTestClient (11) ######################################");
	pNet=SerialNodeNet::init(11);
	pSerialPort = new SoftSerialPort(10, 11, 10);
	pSerialPort->createDataBuffer(sizeof(unsigned long));
	pSerialPort->begin(9600);
	pNet->setOnMessageHandler(&messageHandler);
	pNet->setOnPreConnectHandler(&preConnectHandler);
	pNode1 = pNet->createNode(1, false, 10, 1);
	//pNode2 = pNet->createNode(2, false, 10, 2);
	//pNode3 = pNet->createNode(3, false, 10, 3);

	XPRINTFREE;
    Serial.flush();



}

void loop() {

	/*pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}*/

}

