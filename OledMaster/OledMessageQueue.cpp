/*
 * OledMessageStack.cpp
 *
 *  Created on: 26.01.2018
 *      Author: User
 */

#include "OledMessageQueue.h"

#include "Arduino.h"
#include "OledMessage.h"
#include <tools.h>


OledMessageQueue::OledMessageQueue(byte pin_oled_data) {
	this->pin_oled_data=pin_oled_data;

}

OledMessageQueue::~OledMessageQueue() {
	// TODO Auto-generated destructor stub
}

void OledMessageQueue::push(OledMessage* pMessage) {

	if (count >= QUEUE_LENGTH) {
		XPRINTLN("OledMessageStack::push> queue overflow, delete oldest entry");
	 	delete pop();
	}

	OledMessage* pLast= OledMessageQueue::getLastEntry();
	if (pLast) {
		pLast->pNext=pMessage;
	}else{
		pRoot=pMessage;
	}
	digitalWrite(pin_oled_data,HIGH);

	count++;
	MPRINTLNSVAL("OledMessageStack::push> count: ",count);

}

bool  OledMessageQueue::isEmpty() {
	return pRoot==NULL;
}
unsigned long OledMessageQueue::getCount() {
	return count;
}

OledMessage* OledMessageQueue::pop() {
	MPRINTLNS(" OledMessageStack::pop>");
	OledMessage* pFirst=pRoot;
	pFirst=pRoot;
	if (pRoot) {
		if( pRoot->pNext) {
			pFirst=pRoot;
			pRoot = pRoot->pNext;
		}else{
			pRoot = NULL;
		}
	}



	if (count > 0) {
		--count;
	}
	if (isEmpty()) {
		digitalWrite(pin_oled_data,LOW);
		MPRINTLN(" OledMessageQueue::pop> EMPTY");

	}

return pFirst;
}


OledMessage* OledMessageQueue::getLastEntry() {
	OledMessage* pLast = pRoot;
	while (pLast && pLast->pNext) {
		pLast = (OledMessage*) pLast->pNext;
	}
	return pLast;
}
