#include "Arduino.h"
#include <tools.h>
#include <SerialHeader.h>
#include <SoftSerialPort.h>
#include <SerialNode.h>

SoftSerialPort* pSerialPort;

tSerialHeader sheader;

byte data[] = { 55, 99, 88, 44 }; // some data
SerialNode *pNode1, *pNode2;
bool bStart = false;

unsigned long millis_start = millis();

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("setup SerialTestClient 2");
	SerialNode::init(12);
	pSerialPort = new SoftSerialPort(8, 9, 10);
	pSerialPort->createDataBuffer(sizeof(unsigned long));
	pSerialPort->begin(9600);
	SerialNode::setOnMessageCallBack(onMessage);
	SerialNode::setOnPreConnectCallBack(onPreConnect);
	pNode1 = SerialNode::createNode(1, false, 10, 3);
	pNode2 = SerialNode::createNode(2, false, 10, 4);

	XPRINTFREE
	;
}

void loop() {
	SerialNode::processNodes();

	if (!SerialNode::areAllNodesConnected()) {
		return;
	}
}

void onPreConnect(SerialNode* pNode) {
	MPRINTLNSVAL("onPreConnect :", pNode->getId());
	pNode->setReady(true);
}

void onMessage(const tSerialHeader * pHeader, const byte* pData,
		size_t data_size, SerialNode* pNode) {
	MPRINTLNSVAL("user message received :", pNode->getId());
	MPRINTLNSVAL("user message data     :", *(unsigned long* )pData);
}

