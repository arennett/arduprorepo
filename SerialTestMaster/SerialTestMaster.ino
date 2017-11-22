#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>

SoftSerialPort* pPort =new SoftSerialPort(10,11);
SerialHeaderTx* pTx = new SerialHeaderTx(new SerialHeaderRx(pPort,30));

byte data[] = {55,99,88,44}; // some data

byte masterAddr = 0x01;
byte clientAddr = 0x02;


void setup()
{
	 Serial.begin(9600);
	 MPRINTLN("setup SerialTestMaster");
	 pPort->begin(9600);
	 MPRINTFREE;


	 SerialHeaderRx* pRx= pTx->getRx();

	 pRx->mprintCcbList();
	 pRx->addConnection(masterAddr, clientAddr,true);
	 pRx->mprintCcbList();

	 if(pRx->connect(20000,1000)) {
		 MPRINTLN("WE HAVE CONNECTED");
	 }

	 MPRINTFREE;

}


void loop()
{
	delay(1000);
	MPRINTLN("LOOP");
}





