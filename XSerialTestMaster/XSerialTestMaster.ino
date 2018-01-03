#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>

SoftSerialPort *pSerialPort1, *pSerialPort2;
tSerialHeader sheader;

byte data[] = { 55, 99, 88, 44 }; // some data
SerialNode *pNode1, *pNode2, *pNode3, *pNode4,*pNode5, *pNode6, *pNode;
SerialNodeNet* pNet;
bool conditionsOK = false;

unsigned long timeStamp = 0;
unsigned long now = 0;
unsigned long testdata1 = 0;


void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################setup SerialTestMaster######################################");

	pNet=SerialNodeNet::init(10);

	pSerialPort1 = new SoftSerialPort(10, 11, 11);
	pSerialPort1->createDataBuffer(sizeof(unsigned long));
	pSerialPort1->begin(9600);
	pSerialPort2 = new SoftSerialPort(8, 9, 12);
	pSerialPort2->createDataBuffer(sizeof(unsigned long));
	pSerialPort2->begin(9600);

	pNet->setOnMessageCallBack(onMessage);
	pNet->setOnPreConnectCallBack(onPreConnect);

	pNode1 = pNet->createNode(1, true, 11, 1);
	pNode2 = pNet->createNode(2, true, 11, 2);
	pNode3 = SerialNodeNet::getInstance()->createNode(3, true, 11, 3);

	pNode4 = pNet->createNode(4, true, 12, 1);
	pNode5 = pNet->createNode(5, true, 12, 2);
	pNode6 = pNet->createNode(6, true, 12, 3);
	pNode = pNet->getRootNode();
	XPRINTFREE
	;
}

#define SEND_PERIOD 500
void loop() {
	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		return;
	}

	now = millis();

	unsigned long delta =now - timeStamp;



	if ((delta) > SEND_PERIOD) {
			for (int i=0; i < 2; i++) {
				pNode->send(CMD_ARQ, 0, 0, (byte*) &++testdata1, sizeof(unsigned long));
				XPRINTSVAL("send: ",pNode->getId());XPRINTSVAL(" data : ", testdata1);XPRINTLNSVAL(" delay ",delta-SEND_PERIOD);

			}

		 	pNode = (SerialNode*) pNode->getNext();
			if (!pNode) {
				pNode = pNet->getRootNode();
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

	if (pHeader->cmd==CMD_ARP) {
		XPRINTSVAL("ARP : ", pNode->getId());
		XPRINTLNSVAL(" data : ", *(unsigned long*)pData);
		XPRINTLNSVAL(" acbs : ", AcbList::instance.count());

	}
}
