#include "Arduino.h"
#include <tools.h>
#include <SerialHeader.h>
#include <SoftSerialPort.h>
#include <SerialTx.h>
#include <SerialRx.h>


void update(const byte* pData, size_t data_size,SerialPort* pPort);
SoftSerialPort* pPort =new SoftSerialPort(10,11,11);
SerialTx serialTx;
SerialRx serialRx;
tSerialHeader sheader;

byte data[] = {55,99,88,44}; // some data



void setup()
{
	 Serial.begin(9600);
	 MPRINTLN("setup SerialTestClient");
	 pPort->begin(9600);
	 serialRx.setPort(pPort);
	 serialRx.createBuffer(20);
	 serialRx.setUpdateCallback(update);
	 serialTx.setPort(pPort);
	 sheader.aktid = 4711;
	 sheader.cmd= CMD_CR;
	 sheader.fromAddr= tAddr(11,1);
	 sheader.toAddr = tAddr(10,1);

	 MPRINTFREE;
}


void loop()
{
	serialTx.sendData((byte*)&sheader, sizeof(tSerialHeader));
	delay(1000);
}

void update(const byte* pData, size_t data_size,SerialPort* pPort) {
	 MPRINTLN("update> message received");
	 tSerialHeader* pHeader = (tSerialHeader*) pData;
	 PRINTLNHEADER(pHeader);
	 MPRINTFREE;
}
