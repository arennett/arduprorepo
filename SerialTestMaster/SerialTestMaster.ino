#include "Arduino.h"
#include <tools.h>
#include <SerialHeader.h>
#include <SoftSerialPort.h>
#include <SerialNode.h>


SoftSerialPort* pSerialPort;


tSerialHeader sheader;



byte data[] = {55,99,88,44}; // some data
SerialNode* pNode1;

void setup()
{
	 Serial.begin(9600);

	 MPRINTLNS("");
	 MPRINTLNS("setup SerialTestMaster");

	 pSerialPort=new SoftSerialPort(10,11,11);
	 pSerialPort->begin(9600);
	 SerialNode::init(10);
	 pNode1 = SerialNode::createNode(1,true,11,1);
	 pNode1->setReady(true);

	 //pNode1->connect();
	 MPRINTFREE;
}


void loop()
{

	SerialNode::processNodes(true, 2000);


}

void update(const byte* pData, size_t data_size,SerialPort* pPort) {
	MPRINTLNS("message received");
	 // send NAK;
}





