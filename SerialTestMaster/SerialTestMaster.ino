#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>
#include <SensoMsg.h>

SoftSerialPort sensoClientPort = new SoftSerialPort(10,11);
SerialTx stxClient (sensoClientPort);

SensoMsg sensoMsg(true);

void setup()
{
	 Serial.begin(9600);
	 MPRINTLN("setup SerialTestMaster");
	 stxClient.begin(9600);
}


void loop()
{
	sensoMsg.setCmd(CMD_SET_DSP_CLEAR);
	delay(300);
	sensoMsg.send(&stxClient);
	sensoMsg.setCmd(CMD_SET_DSP_RECT);
	delay(300);
	sensoMsg.setCmd(CMD_SET_DSP_CLEAR);
	delay(300);
	sensoMsg.setCmd(CMD_SET_DSP_CIRCLE);
	delay(300);


}





