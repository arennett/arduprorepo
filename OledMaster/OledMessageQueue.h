/*
 * OledMessageStack.h
 *
 *  Created on: 26.01.2018
 *      Author: User
 */

#ifndef OLEDMESSAGEQUEUE_H_
#define OLEDMESSAGEQUEUE_H_
#define QUEUE_LENGTH  5
#include "Arduino.h"
#include "OledMessage.h"


class OledMessageQueue {
public:
	OledMessageQueue(byte pin_oled_data);
	virtual ~OledMessageQueue();
	void init();
	void push(OledMessage* pMessage);
	OledMessage* pop();
	OledMessage* getLastEntry();
	bool  isEmpty();
	unsigned long getCount();
private:
	unsigned long count=0;
	OledMessage *pRoot=NULL;
	byte pin_oled_data;
};

#endif /* OLEDMESSAGEQUEUE_H_ */
