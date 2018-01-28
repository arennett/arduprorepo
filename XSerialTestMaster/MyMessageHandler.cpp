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
	MPRINTLNSVAL("MyMessageHandler(10)::onMessage> for node : ",pNode->getId());
	MPRINTLNHEADER(pHeader);
	if (pHeader->cmd==CMD_ARP) {
		MPRINTSVAL("ARP : ", pNode->getId());
		MPRINTLNSVAL(" dataSize : ",dataSize);
		MPRINTLNSVAL(" data : ", *(unsigned long*)pData);
		MPRINTLNSVAL(" acbs : ", AcbList::getInstance()->count());

	}
}
