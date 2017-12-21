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


	PRINTFREE;
}


void loop()
{
	SerialNode::processNodes();


	if (!SerialNode::areAllNodesConnected()) {
		return;
	}

	// system calibrated , and all
	//MPRINTLNS("system calibrated and all nodes connected with remote");

	Serial.flush();


}



void onPreConnect(SerialNode* pNode) {
	if (pNode==pNode1){
			if ((millis()-millis_start) > 2000){ //only example , check inputs, calibrate
				pNode1->setReady(true);
				MPRINTLNS("node 1 ready");
			}
	    }

		 // preCondition for node2  to connect
	if (pNode==pNode2){
		if ((millis()-millis_start) > 4000){ //only example , check inputs, calibrate
			pNode2->setReady(true);
			MPRINTLNS("node 2 ready");
		}
	}
}


void onMessage(const tSerialHeader * pHeader,const byte* pData, size_t data_size,SerialNode* pNode) {
	MPRINTLNS("user message received");
	 // send NAK;
}





