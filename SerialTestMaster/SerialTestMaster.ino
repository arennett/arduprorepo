#include "Arduino.h"
#include <tools.h>
#include <SerialHeader.h>
#include <SoftSerialPort.h>
#include <SerialNode.h>


SoftSerialPort* pSerialPort1;
SoftSerialPort* pSerialPort2;


//byte data[] = {55,99,88,44}; // some data
SerialNode *pNode1,*pNode2,*pNode3,*pNode4;

void setup()
{
	 Serial.begin(9600);

	 MPRINTLNS("");
	 MPRINTLNS("setup SerialTestMaster");
	 SerialNode::init(10);
	 SerialNode::setOnMessageCallBack(onMessage);
	 SerialNode::setOnPreConnectCallBack(onPreConnect);

	 // pSerialPort1 =new SoftSerialPort(10,11,11);
	  pSerialPort2 =new SoftSerialPort(8,9,12);

	  //pSerialPort1->begin(9600);
	  pSerialPort2->begin(9600);

	 //pNode1  = SerialNode::createNode(1,true,11,1);
	 //pNode2  = SerialNode::createNode(2,true,11,2);
	  pNode3  = SerialNode::createNode(3,true,12,1);
	  pNode4  = SerialNode::createNode(4,true,12,2);





	PRINTFREE;
}


void loop()
{
	SerialNode::processNodes();



	if (!SerialNode::areAllNodesConnected()) {
		return;
	}

	// system calibrated , and all
	//MPRINTLNS("system calibrated and all nodes connected withe remote");

	Serial.flush();



}

// here you can code preconditions to connect
void onPreConnect(SerialNode* pNode) {
	if (pNode==pNode1){
		pNode1->setReady(true);
		XPRINTLNS("node 1 ready");
	}

	if (pNode==pNode2){
		pNode2->setReady(true);
		XPRINTLNS("node 2 ready");

	}

	if (pNode==pNode3){
		pNode3->setReady(true);
		XPRINTLNS("node 3 ready");
	}


	if (pNode==pNode4){
		pNode4->setReady(true);
		MPRINTLNS("node 4 ready");

	}

}

void onMessage(const tSerialHeader * pHeader,const byte* pData, size_t data_size,SerialNode* pNode) {
	MPRINTLNS("user message received");
	 // send NAK;
}





