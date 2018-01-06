/*
 * MyMessageHandler.h
 *
 *  Created on: 05.01.2018
 *      Author: User
 */

#ifndef MYMESSAGEHANDLER_H_
#define MYMESSAGEHANDLER_H_

#include <SerialMsgLib.h>
#include <OnMessageHandler.h>
using namespace SerialMsgLib;

class MyMessageHandler: public SerialMsgLib::OnMessageHandler {
public:
	MyMessageHandler();
	virtual ~MyMessageHandler();
	virtual void onMessage(const tSerialHeader* pHeader, const unsigned char *pData, unsigned int dataSize,  SerialNode *pNode);
};

#endif /* MYMESSAGEHANDLER_H_ */
