/*
  senso.h - Main include file for the senso game
  Copyright (c) 2017 Andre´ Rennett
*/

#ifndef senso_h
#define senso_h

#include "pitches.h"

#define IN_Y 2
#define IN_B 3
#define IN_G 4
#define IN_R 5
#define IN_W 6

#define OUT_Y 8
#define OUT_B 9
#define OUT_G 10
#define OUT_R 11
#define OUT_W 12

#define TONE_PIN 7

#define ANZ_COLORS 5

typedef enum {yellow=0,blue,green,red,white} tLedColor;
typedef enum {off,demo,iotest,listening,writing} tSequenceMode;

unsigned char pinButton[]  	=	{IN_Y,IN_B,IN_G,IN_R,IN_W};
unsigned int  tones[] 		=	{NOTE_C4,NOTE_G4,NOTE_A4,NOTE_C3,NOTE_B0};
unsigned char pinLED[]   	=	{OUT_Y,OUT_B,OUT_G,OUT_R,OUT_W};

#endif
