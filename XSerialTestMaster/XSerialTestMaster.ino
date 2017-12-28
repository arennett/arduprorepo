#include "Arduino.h"
#include <tools.h>
#include <SerialHeader.h>
#include <SoftSerialPort.h>
#include <SerialNode.h>


SoftSerialPort* pSerialPort;


tSerialHeader sheader;

byte data[] = {55,99,88,44}; // some data
SerialNode *pNode1,*pNode2;
bool conditionsOK=false;

unsigned long millis_start = millis();

void setup()
{
	 Serial.begin(9600);

	 MPRINTLNS("");
	 MPRINTLNS("setup SerialTestMaster");
	 SerialNode::init(10);
	 pSerialPort=new SoftSerialPort(11,11,10);
	 pSerialPort->begin(9600);
	 pNode1  = SerialNode::createNode(1,false,11,1);
	 pNode2  = SerialNode::createNode(2,false,11,2);


	XPRINTFREE;
}


void loop()
{
	SerialNode::processNodes();


	if (!SerialNode::areAllNodesConnected()) {
		return;
	}

	MPRINTLNS("system calibrated and all nodes connected with remote");

	Serial.flush();


}



void onPreConnect(SerialNode* pNode) {
	pNode->setReady(true);
}


void onMessage(const tSerialHeader * pHeader,const byte* pData, size_t data_size,SerialNode* pNode) {
	MPRINTLNS("user message received");
	 // send NAK;
}
