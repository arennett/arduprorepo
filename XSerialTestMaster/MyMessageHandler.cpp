/*
 * MyMessageHandler.cpp
 *
 *  Created on: 05.01.2018
 *      Author: User
 */


#include <SerialMsgLib.h>
#include <tools.h>
#include "MyMessageHandler.h"

using namespace SerialMsgLib;

MyMessageHandler::MyMessageHandler() {
	// TODO Auto-generated constructor stub

}

MyMessageHandler::~MyMessageHandler() {
	// TODO Auto-generated destructor stub
}

void MyMessageHandler::onMessage(const tSerialHeader* pHeader, const unsigned char* pData, unsigned int dataSize,  SerialNode* pNode){
	XPRINTLNSVAL("MyMessageHandler(10)::onMessage> for node : ",pNode->getId());
	XPRINTLNHEADER(pHeader);
	if (pHeader->cmd==CMD_ARP) {
		XPRINTSVAL("ARP : ", pNode->getId());
		XPRINTLNSVAL(" data : ", *(unsigned long*)pData);
		XPRINTLNSVAL(" acbs : ", AcbList::getInstance()->count());

	}
}
