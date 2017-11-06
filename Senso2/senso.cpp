#include "Arduino.h"
#include "senso.h"
#include "SimpleTimer.h"
#include "Bounce2.h"
#include "pitches.h"


void ledWrite(tLedColor color, unsigned char state);
void checkButtons();
bool isButtonPressed(tLedColor colorButton);
void setSequenceMode(tSequenceMode mode);
tLedColor getNextColor();
void flashNext();
void speedUp();

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

void setup() {

	Serial.begin(9600);

	for (int i = 0; i < ANZ_COLORS; i++) {
		pinMode(pinButton[i], INPUT_PULLUP);
		pinMode(pinLED[i], OUTPUT);
		bouncer[i].attach(pinButton[i]);
		bouncer[i].interval(30);
	}

	timerIdflashNext = timer.setInterval(10000, flashNext);
	//setSequenceMode(tSequenceMode::iotest);

}

void loop() {
	timer.run();
	checkButtons();
}

void startGame() {
	Serial.write(
			"<<<<<<<<<<<<<<<<<<<<<<<<start game>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	memset(colorSequence, 0, MAX_SEQUENCE_LENGTH);

	seqIntervall = MAX_INTERVAL;

	timer.resetDelay(seqIntervall, timerIdflashNext);

	for (int i = 0; i < 3; i++) {
		ledWrite(white, HIGH);
		delay(100);
		ledWrite(white, LOW);
		delay(100);
	}
	lastSeqElIdx = -1;
	setSequenceMode(tSequenceMode::writing);

}

void checkButtons() {
	tLedColor colorButton;
	Serial.println("check Buttoons");
	Serial.write("setSequenceMode: ");
	Serial.println(currentSeqMode);
	for (int i = 0; i < ANZ_COLORS; i++) {
		colorButton = (tLedColor) i;

		if (isButtonPressed(colorButton)) {
			if (currentSeqMode == tSequenceMode::iotest) {
				ledWrite(colorButton, HIGH);
				delay(500);
				ledWrite(colorButton, LOW);
				return;
			}

			if (colorButton == white) {
				// start game
				startGame();

			} else {

				if (currentSeqMode == tSequenceMode::listening) {
					seqButtonIdx++;
					Serial.write("listening mode / button: ");
					Serial.println(colorButton);
					Serial.print("seqButtonIdx :");
					Serial.println(seqButtonIdx);
					Serial.print("expected color: ");
					Serial.println(colorSequence[seqButtonIdx]);

					if (colorButton == colorSequence[seqButtonIdx]) {

						if (seqButtonIdx < lastSeqElIdx) {
							// ok go on keep on
							Serial.println("waiting for next button");
							break;

						} else {
							// gratulation
							ledWrite(white, HIGH);
							delay(100);
							ledWrite(white, LOW);
							delay(100);
							Serial.println("yes! start from beginning");
							setSequenceMode(tSequenceMode::writing);
						}

					} else {
						Serial.println("wrong color, you loose");
						ledWrite(white, HIGH);
						delay(1000);
						ledWrite(white, LOW);
						delay(1000);
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
		Serial.print("Button pressed: ");
		Serial.println(color);
	}
	return isReleased;

}

void ledWrite(tLedColor color, unsigned char state) {
	digitalWrite((unsigned char) pinLED[color], state);
	if (state == HIGH) {
		Serial.println("tone");
		tone(TONE_PIN, tones[color]);
		Serial.print("LED:");
		Serial.println(color);
	} else {
		noTone(TONE_PIN);
	}
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

	Serial.write("setSequenceMode: ");
	Serial.println(currentSeqMode);
}
void flashNext() {

	bool eos = false;
	ledWrite(currentColor, LOW);
	if (currentSeqMode > 0) {
		Serial.print("fn currenseq mode ");
		Serial.println(currentSeqMode);
	}

	if ((currentSeqMode == tSequenceMode::writing)
			|| (currentSeqMode == tSequenceMode::demo)) {

		seqFlashIdx++;
		Serial.print("flashNext flash idx :");
		Serial.println(seqFlashIdx);
		Serial.print("flashNext last seq idx :");
		Serial.println(lastSeqElIdx);
		speedUp();
		ledWrite(currentColor, LOW);
		delay(100);
		if (lastSeqElIdx == MAX_SEQUENCE_LENGTH) {
			setSequenceMode(tSequenceMode::off);
			// game over
			Serial.println("GAME OVER YOU WIN");
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
		//Serial.println(currentColor);

	}
}

void speedUp() {
	Serial.println("speed up");
	if (seqIntervall > 400) {
		seqIntervall = seqIntervall - 20;
		timer.resetDelay(seqIntervall, timerIdflashNext);
	}
	//timer.deleteTimer(timerIdSequenceOut);
	//timerIdflashNext= timer.setInterval(seqIntervall, flashNext);

	//Serial.write("timerIdflashNext 2: \n");
	//Serial.println(timerIdflashNext);

}

tLedColor getNextColor() {
	if ((currentSeqMode == tSequenceMode::demo)) {
		if (currentColor == white) {
			return yellow;
		} else {
			return (tLedColor) (currentColor + 1);
		}
	} else if ((currentSeqMode == tSequenceMode::writing)) {

		if (seqFlashIdx <= lastSeqElIdx) {
			currentColor = colorSequence[seqFlashIdx];
			Serial.print("seq  color: ");
		} else {
			currentColor = (tLedColor) random(4);
			//if (currentColor == red) {
			//	currentColor = yellow;
			//} else {
			//	currentColor = (tLedColor) (currentColor + 1);
			//}

			colorSequence[++lastSeqElIdx] = currentColor;
			setSequenceMode(tSequenceMode::listening);
			Serial.print("new  color: ");
		}

	}
	Serial.println(currentColor);
	return currentColor;

}
