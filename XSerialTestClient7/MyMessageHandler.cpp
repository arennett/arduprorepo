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
	MPRINTLNSVAL("MyMessageHandler(12)::onMessage> for node : ",pNode->getId());
	//MPRINT(pHeader);
	if (pHeader->cmd==CMD_ARQ) {
		pNode->send(CMD_ARP, pHeader->aktid, 0, pData, dataSize);
	}

}
