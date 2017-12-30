#include "Arduino.h"
#include <tools.h>
#include <SerialHeader.h>
#include <SoftSerialPort.h>
#include <SerialNode.h>

SoftSerialPort *pSerialPort1, *pSerialPort2;

tSerialHeader sheader;

byte data[] = { 55, 99, 88, 44 }; // some data
SerialNode *pNode1, *pNode2, *pNode3, *pNode4, *pNode;
bool conditionsOK = false;

unsigned long timeStamp = 0;
unsigned long now = 0;
unsigned long testdata1 = 0;


void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("setup SerialTestMaster");
	SerialNode::init(10);
	pSerialPort1 = new SoftSerialPort(10, 11, 11);
	pSerialPort1->begin(9600);
	pSerialPort2 = new SoftSerialPort(8, 9, 12);
	pSerialPort2->begin(9600);
	SerialNode::setOnMessageCallBack(onMessage);
	SerialNode::setOnPreConnectCallBack(onPreConnect);

	pNode1 = SerialNode::createNode(1, true, 11, 1);
	pNode2 = SerialNode::createNode(2, true, 11, 2);
	pNode3 = SerialNode::createNode(3, true, 12, 1);
	pNode4 = SerialNode::createNode(4, true, 12, 2);

	pNode1->setReady(true);
	pNode2->setReady(true);
	pNode3->setReady(true);
	pNode4->setReady(true);

	pNode = pNode1;
	XPRINTFREE
	;
}

void loop() {
	SerialNode::processNodes();

	if (!SerialNode::areAllNodesConnected()) {
		return;
	}

	now = millis();

	if ((now - timeStamp) > 1000) {
		pNode->send(CMD_ACD, 0, 0, (byte*) ++testdata1, sizeof(unsigned long));
		pNode = (SerialNode*) pNode->getNext();
		if (!pNode) {
			pNode = SerialNode::getRoot();
		}
		timeStamp=now;
	}

}

void onPreConnect(SerialNode* pNode) {
	MPRINTLNSVAL("onPreConnect :", pNode->getId());
	pNode->setReady(true);
}

void onMessage(const tSerialHeader * pHeader, const byte* pData,
		size_t data_size, SerialNode* pNode) {
	MPRINTLNSVAL("user message received :", pNode->getId());
	// send NAK;
}
