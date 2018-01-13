/*
 * MyPreConnectHandler.h
 *
 *  Created on: 05.01.2018
 *      Author: User
 */

#ifndef MYPRECONNECTHANDLER_H_
#define MYPRECONNECTHANDLER_H_
#include <SerialMsgLib.h>
#include <OnPreConnectHandler.h>
using namespace SerialMsgLib;

class MyPreConnectHandler: public SerialMsgLib::OnPreConnectHandler {
public:
	MyPreConnectHandler();
	virtual ~MyPreConnectHandler();
	virtual void onPreConnect(SerialNode* pNode);
};

#endif /* MYPRECONNECTHANDLER_H_ */
