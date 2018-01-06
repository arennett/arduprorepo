/*
 * MyPreConnectHandler.cpp
 *
 *  Created on: 05.01.2018
 *      Author: User
 */

#include "MyPreConnectHandler.h"
#include <tools.h>
MyPreConnectHandler::MyPreConnectHandler() {
	// TODO Auto-generated constructor stub

}

MyPreConnectHandler::~MyPreConnectHandler() {
	// TODO Auto-generated destructor stub
}

 void MyPreConnectHandler::onPreConnect(SerialNode* pNode){

	 XPRINTLNSVAL("MyPreConnectHandler::onPreConnect> node : ",pNode->getId());
	 pNode->setReady(true);

 }
