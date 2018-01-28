#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>
#include "MyMessageHandler.h"
#include "MyPreConnectHandler.h"
#include <SoftwareSerial.h>
#include <SerialPort.h>
#include"DummySerialPort.h"

#define PIN_LED_CONNECTED 2

SoftSerialPort* pSerialPort6;

tSerialHeader sheader;

//byte data[] = { 55, 99, 88, 44 }; // some data

SerialNodeNet* pNet;
MyMessageHandler messageHandler;
MyPreConnectHandler preConnectHandler;
tStamp timeStamp =0;
unsigned long testdata1 =0;

unsigned long millis_start = millis();

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################ setup SerialTestClient (7) ######################################");

	pinMode(PIN_LED_CONNECTED,OUTPUT);
	digitalWrite(PIN_LED_CONNECTED,LOW);

	pNet=SerialNodeNet::init(7);
	pSerialPort6 = new SoftSerialPort(8, 9, 6);
	pSerialPort6->createDataBuffer(sizeof(unsigned long));
	pSerialPort6->begin(9600);
	pNet->setOnMessageHandler(&messageHandler);
	pNet->setOnPreConnectHandler(&preConnectHandler);
	pNet->createNode(1, false, 4, 1);
	pNet->createNode(2, false, 4, 2);

	XPRINTFREE;
    Serial.flush();



}

#define SEND_PERIOD 200
void loop() {

	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		digitalWrite(PIN_LED_CONNECTED,LOW);
		return;
	}
	digitalWrite(PIN_LED_CONNECTED,HIGH);




}

