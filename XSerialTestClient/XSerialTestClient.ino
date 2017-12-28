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
	 SerialNode::init(11);
	 pSerialPort=new SoftSerialPort(10,11,10);
	 pSerialPort->begin(9600);
	 pNode1  = SerialNode::createNode(1,false,10,1);
	 pNode2  = SerialNode::createNode(2,false,10,2);

	 XPRINTFREE;
}


void loop()
{
	SerialNode::processNodes();


	if (!SerialNode::areAllNodesConnected()) {
		return;
	}

	// system calibrated , and al l
	MPRINTLNS("system calibrated and all nodes connected with remote");




}




void onPreConnect(SerialNode* pNode) {
	MPRINTLNSVAL("onPreConnect :" ,pNode->getId());
	pNode->setReady(true);
}


void onMessage(const tSerialHeader * pHeader,const byte* pData, size_t data_size,SerialNode* pNode) {
	MPRINTLNSVAL("user message received :" ,pNode->getId() );
	 // send NAK;
}

