#include "Arduino.h"
#include <tools.h>
#include <SerialMsgLib.h>
#include "MyMessageHandler.h"
#include "MyPreConnectHandler.h"
#include <SoftwareSerial.h>
#include <SerialPort.h>
//#include"DummySerialPort.h"
#define PIN_LED_CONNECTED 2

SoftSerialPort* pSerialPort5;
SoftSerialPort* pSerialPort7;

tSerialHeader sheader;

//byte data[] = { 55, 99, 88, 44 }; // some data
SerialNodeNet* pNet;
MyMessageHandler messageHandler;
MyPreConnectHandler preConnectHandler;
tStamp timeStamp =0;
unsigned long testdata1 =0;

unsigned long millis_start = millis();
bool isLinked =false;

void setup() {
	Serial.begin(9600);

	MPRINTLNS("");
	MPRINTLNS("################################ setup SerialTestClient (6) ######################################");

	pinMode(PIN_LED_CONNECTED,OUTPUT);
	digitalWrite(PIN_LED_CONNECTED,LOW);

	pNet=SerialNodeNet::init(6);
	AcbList::getInstance()->setAktId(1000);
	pSerialPort5 = new SoftSerialPort(6, 7, 5);
	pSerialPort5->createDataBuffer(sizeof(unsigned long));
	pSerialPort5->begin(9600);
	pSerialPort7 = new SoftSerialPort(8, 9, 7);
	pSerialPort7->createDataBuffer(sizeof(unsigned long));
	pSerialPort7->begin(9600);
	pNet->setOnMessageHandler(&messageHandler);
	pNet->setOnPreConnectHandler(&preConnectHandler);

	XPRINTFREE;
    Serial.flush();



}
#define SEND_PERIOD 500
void loop() {

	pNet->processNodes();

	if (!pNet->areAllNodesConnected()) {
		digitalWrite(PIN_LED_CONNECTED,LOW);
		return;
	}
	if(!isLinked && SerialNodeNet::getInstance()->getLcbList()->countCompleted() > 0) {
		digitalWrite(PIN_LED_CONNECTED,HIGH);
		isLinked=true;
	}

}

