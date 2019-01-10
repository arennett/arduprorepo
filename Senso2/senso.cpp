#include "Arduino.h"
#include <tools.h>
#include "senso.h"
#include "SimpleTimer.h"
#include "Bounce2.h"
#include "pitches.h"
#include <Wire.h>



void ledWrite(tLedColor color, unsigned char state);
void registerWrite(int whichPin, int whichState);
void checkButtons();
bool isButtonPressed(tLedColor colorButton);
void setSequenceMode(tSequenceMode mode);
tLedColor getNextColor();
void flashNext();
void speedUp();
void animationLEDS(tLedAnimation ledAnimation, tLedColor ledColor = center);

tLedColor currentColor = yellow;
tSequenceMode currentSeqMode = off;
long speed = -20;
const long MAX_INTERVAL = 1000;
const unsigned char MAX_SEQUENCE_LENGTH = 50;

long seqIntervall = MAX_INTERVAL;
SimpleTimer timer;
int seqFlashIdx = -1;
int seqButtonIdx = -1;
int lastSeqElIdx = -1;

int timerIdflashNext, timerIdSpeedUp;
tLedColor colorSequence[MAX_SEQUENCE_LENGTH];
Bounce bouncer[ANZ_COLORS - 1];
#define MPRINT_ON
void setup() {

	Serial.begin(9600);
	XPRINTLNS("");
	XPRINTLNS("SENSO 2");
	XPRINTFREE;

	pinMode(PIN_LATCH, OUTPUT);
	pinMode(PIN_DATA, OUTPUT);
	pinMode(PIN_CLOCK, OUTPUT);

	for (int i = 0; i < ANZ_COLORS; i++) {
		pinMode(pinButton[i], INPUT_PULLUP);
		pinMode(pinLED[i], OUTPUT);
		bouncer[i].attach(pinButton[i]);
		bouncer[i].interval(30);
	}

	timerIdflashNext = timer.setInterval(10000, flashNext);
	animationLEDS(tLedAnimation::round3);
	animationLEDS(tLedAnimation::flicker6, center);

	//setSequenceMode(tSequenceMode::iotest);

}

void loop() {
	timer.run();
	checkButtons();
}

void startGame() {
	XPRINTLNS("<<<<<<<<<<<<<<<<<<<<<<<<start game>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	memset(colorSequence, 0, MAX_SEQUENCE_LENGTH);

	seqIntervall = MAX_INTERVAL;

	timer.resetDelay(seqIntervall, timerIdflashNext);


	animationLEDS(tLedAnimation::flicker3, center);
	lastSeqElIdx = -1;
	setSequenceMode(tSequenceMode::writing);

}

void checkButtons() {
	tLedColor colorButton;
	for (int i = 0; i < ANZ_COLORS; i++) {
		colorButton = (tLedColor) i;

		if (isButtonPressed(colorButton)) {
			if (currentSeqMode == tSequenceMode::iotest) {
				ledWrite(colorButton, HIGH);
				delay(500);
				ledWrite(colorButton, LOW);
				return;
			}

			if (colorButton == center) {
				// start game
				startGame();

			} else {

				if (currentSeqMode == tSequenceMode::listening) {
					seqButtonIdx++;
					MPRINTLNSVAL("checkButtons:: listening mode / button: ",colorButton);
					MPRINTLNSVAL("checkButtons:: seqButtonIdx :" ,seqButtonIdx);
					MPRINTLNSVAL("checkButtons:: expected color:" ,colorSequence[seqButtonIdx]);



					if (colorButton == colorSequence[seqButtonIdx]) {

						if (seqButtonIdx < lastSeqElIdx) {
							// ok go on keep on
							MPRINTLNS("checkButtons:: waiting for next button");
							break;

						} else {
							// gratulation
							animationLEDS(flicker1, center);
							MPRINTLNS("checkButtons:: yes! start from beginning");
							setSequenceMode(tSequenceMode::writing);
						}

					} else {
						MPRINTLNS("checkButtons:: wrong color, you loose");
						animationLEDS(tLedAnimation::flicker6, center);
						ledWrite(colorSequence[seqButtonIdx], HIGH);
						delay(500);
						ledWrite(colorSequence[seqButtonIdx], LOW);

						setSequenceMode(tSequenceMode::off);
					}

				}

			}
		}

	}
}

bool isButtonPressed(tLedColor color) {

	bouncer[color].update();
	bool isPressed = (bouncer[color].fell());
	bool isReleased = (bouncer[color].rose());

	if (isPressed) {
		ledWrite(color, HIGH);
	}
	if (isReleased) {
		ledWrite(color, LOW);
	}
	if (isReleased) {
		MPRINTLNSVAL("isButtonPressed:: Button pressed: ",color);
	}
	return isReleased;

}

void ledWrite(tLedColor color, unsigned char state) {
	registerWrite((unsigned char) pinLED[color], state);
	if (state == HIGH) {
		MPRINTLNSVAL("ledWrite:: LED on:",color);
		tone(TONE_PIN, tones[color]);
	} else {
		noTone(TONE_PIN);
	}
}

void registerWrite(int whichPin, int whichState) {
// the bits you want to send
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(PIN_LATCH, LOW);

  // turn on the next highest bit in bitsToSend:
  bitWrite(bitsToSend, whichPin, whichState);

  // shift the bits out:
  shiftOut(PIN_DATA, PIN_CLOCK, MSBFIRST, bitsToSend);

    // turn on the output so the LEDs can light up:
  digitalWrite(PIN_LATCH, HIGH);

}

void setSequenceMode(tSequenceMode mode) {

	currentSeqMode = mode;
	if (mode == tSequenceMode::listening) {
		timer.disable(timerIdflashNext);
		seqFlashIdx = -1;
	} else if (mode == tSequenceMode::writing) {
		seqButtonIdx = -1;
		timer.enable(timerIdflashNext);
		timer.restartTimer(timerIdflashNext);
	} else {
		seqFlashIdx = -1;
		seqButtonIdx = -1;
	}

	MPRINTLNSVAL("setSequenceMode:: ",currentSeqMode);
}
void flashNext() {

	bool eos = false;
	ledWrite(currentColor, LOW);
	if (currentSeqMode > 0) {
		MPRINTLNSVAL("flashNext:: currentSeqMode ", currentSeqMode);
	}

	if ((currentSeqMode == tSequenceMode::writing)
			|| (currentSeqMode == tSequenceMode::demo)) {

		seqFlashIdx++;
		MPRINTLNSVAL("flashNext:: seqFlashIdx:",  seqFlashIdx);
		MPRINTLNSVAL("flashNext:: lastSeqElIdx:", lastSeqElIdx);
		speedUp();
		ledWrite(currentColor, LOW);
		delay(100);
		if (lastSeqElIdx == MAX_SEQUENCE_LENGTH) {
			setSequenceMode(tSequenceMode::off);
			// game over
			MPRINTLNS("flashNext:: GAME OVER YOU WIN");
		}

		if (seqFlashIdx > lastSeqElIdx) {
			// end of seq new color will be created
			eos = true;
		}

		currentColor = getNextColor();
		ledWrite(currentColor, HIGH);
		if (eos) {
			delay(500);
			ledWrite(currentColor, LOW);

		}

		// get next color set seq mode to listening if no more flashing needed
		//Serial.write("currentColor:\n");
		//MPRINTLNS(currentColor);

	}
}

void speedUp() {
	MPRINTLNS("speed up");
	if (seqIntervall > 400) {
		seqIntervall = seqIntervall - 20;
		timer.resetDelay(seqIntervall, timerIdflashNext);
	}
	//timer.deleteTimer(timerIdSequenceOut);
	//timerIdflashNext= timer.setInterval(seqIntervall, flashNext);

	//Serial.write("timerIdflashNext 2: \n");
	//MPRINTLNS(timerIdflashNext);

}

tLedColor getNextColor() {
	if ((currentSeqMode == tSequenceMode::demo)) {
		if (currentColor == center) {
			return yellow;
		} else {
			return (tLedColor) (currentColor + 1);
		}
	} else if ((currentSeqMode == tSequenceMode::writing)) {

		if (seqFlashIdx <= lastSeqElIdx) {
			currentColor = colorSequence[seqFlashIdx];
			MPRINT("getNextColor:: seq  color: ");
		} else {
			currentColor = (tLedColor) (random(ANZ_COLORS)+1);
			//if (currentColor == red) {
			//	currentColor = yellow;
			//} else {
			//	currentColor = (tLedColor) (currentColor + 1);
			//}

			colorSequence[++lastSeqElIdx] = currentColor;
			setSequenceMode(tSequenceMode::listening);
			MPRINT("getNextColor:: new  color: ");
		}

	}
	MPRINTLN(currentColor);
	return currentColor;

}

void animationLEDS(tLedAnimation ledAnimation, tLedColor ledColor) {


	switch (ledAnimation) {
	case round3:
				for (int i = 0; i < 3; i++) {
					for (tLedColor col = yellow; col <= white; col= (tLedColor)(col+1)) {
						ledWrite(col, HIGH);
						delay(50);
						ledWrite(col, LOW);
						delay(100);

					}

				}
				break;
		case flicker1:
			for (int i = 0; i < 1; i++) {
					ledWrite(ledColor, HIGH);
					delay(100);
					ledWrite(ledColor, LOW);
					delay(100);

			}
			break;
	case flicker3:
			for (int i = 0; i < 3; i++) {
					ledWrite(ledColor, HIGH);
					delay(100);
					ledWrite(ledColor, LOW);
					delay(100);

			}
			break;
	case flicker6:
			for (int i = 0; i < 6; i++) {
					ledWrite(ledColor, HIGH);
					delay(100);
					ledWrite(ledColor, LOW);
					delay(100);

			}
			break;

	}
}
