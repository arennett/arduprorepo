#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>


SoftSerialPort* pSerialPort;

tSerialHeader sheader;

byte data[] = { 55, 99, 88, 44 }; // some data
SerialNode *pNode1, *pNode2,*pNode3;
SerialNodeNet* pNet;


unsigned long millis_start = millis();

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################ setup SerialTestClient (11) ######################################");
	pNet=SerialNodeNet::init(11);
	pSerialPort = new SoftSerialPort(10, 11, 10);
	pSerialPort->createDataBuffer(sizeof(unsigned long));
	pSerialPort->begin(9600);
	pNet->setOnPreConnectCallBack(onPreConnect);
	pNet->setOnMessageCallBack(onMessage);
	pNode1 = pNet->createNode(1, false, 10, 1);
	pNode2 = pNet->createNode(2, false, 10, 2);
	pNode3 = pNet->createNode(3, false, 10, 3);

	XPRINTFREE
	;
}

void loop() {
	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}

}

void onPreConnect(SerialNode* pNode) {
	MPRINTLNSVAL("onPreConnect :", pNode->getId());
	pNode->setReady(true);
}

void onMessage(const tSerialHeader * pHeader, const byte* pData,
		size_t data_size, SerialNode* pNode) {
	XPRINTLNSVAL("user message received :", pNode->getId());
	XPRINTLNSVAL("user message data     :", *(unsigned long* )pData);
	if (pHeader->cmd==CMD_ARQ) {
		pNode->send(CMD_ARP,pHeader->aktid,pNode->getId(),pData,data_size);
	}
	// send NAK;
}

