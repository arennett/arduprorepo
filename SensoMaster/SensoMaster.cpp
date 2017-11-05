#include "Arduino.h"
#include <tools.h>
#include <SerialMsg.h>
#include <Senso.h>
#include <SoftwareSerial.h>

SerialTx serialTx(new SoftSerialPort(10,11)); // RX, TX

long connectionSpeed = 9600;
SensoMsg sMessage;

void setup() {
  Serial.begin(CONNECTION_SPPED_MASTER_TO_DISPLAY);
  serialTx.begin(9600);
  MPRINTLNS("setup ok");

}

void loop() {

  sMessage.setCmd(CMD_SET_DSP);
  sMessage.setSubCmd(CMDSUB_SET_DSP_CLEAR);
  serialTx.sendData((byte*) &sMessage, sizeof sMessage);
  MPRINTLNS("message clear sent");
  delay(1000);
  sMessage.setCmd(CMD_SET_DSP);
  sMessage.setSubCmd(CMDSUB_SET_DSP_RECT);
  serialTx.sendData((byte*) &sMessage, sizeof sMessage);
  MPRINTLNS("message rect sent");
}
