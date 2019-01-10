/*
  senso.h - Main include file for the senso game
  Copyright (c) 2017 Andre´ Rennett
*/

#ifndef senso_h
#define senso_h

#include "pitches.h"



#define IN_CENTER 3
#define IN_W 4
#define IN_Y 5
#define IN_B 6
#define IN_G 7
#define IN_R 8


//Pin connected to latch pin (ST_CP) of 74HC595
#define PIN_LATCH 9
//Pin connected to clock pin (SH_CP) of 74HC595
#define PIN_CLOCK 12
////Pin connected to Data in (DS) of 74HC595
#define PIN_DATA  11

#define OUT_CENTER 0

#define OUT_Y 1
#define OUT_B 2
#define OUT_G 3
#define OUT_R 4
#define OUT_W 5

#define TONE_PIN 13




typedef enum {center=0,yellow,blue,green,red,white,ANZ_COLORS=white+1} tLedColor;
typedef enum {round3,flicker1,flicker3,flicker6} tLedAnimation;
typedef enum {off,demo,iotest,listening,writing} tSequenceMode;

unsigned char pinButton[]  	=	{IN_CENTER,IN_Y,IN_B,IN_G,IN_R,IN_W};
unsigned int  tones[] 		=	{NOTE_C4,NOTE_G4,NOTE_A4,NOTE_C3,NOTE_B0};
unsigned char pinLED[]   	=	{OUT_CENTER,OUT_Y,OUT_B,OUT_G,OUT_R,OUT_W};

#endif
