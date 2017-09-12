/*
 * RainbowCyclePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "RainbowCyclePattern.h"
#include "../WifiController.h"
#include "../NeopixelUtils.h"
#include "../TaskManager.h"

int RainbowCyclePattern::speedDelay = 100;
int jSize = 256 * 2;
int jIndex = 0;
void RainbowCyclePattern::show() {
	byte *c;
	uint16_t i;
	if (jIndex == 256 * 2) {
		jIndex = 0;
	}
	for (i = 0; i < NeopixelUtils::getNumLED(); i++) {
		c = wheel(((i * 256 / NeopixelUtils::getNumLED()) + jIndex) & 255);
		NeopixelUtils::setPixel(i, *c, *(c + 1), *(c + 2));
	}
	NeopixelUtils::showStrip();
	TaskManager::refreshLEDTask->delay(speedDelay);
	jIndex++;
}

byte * RainbowCyclePattern::wheel(byte WheelPos) {
	static byte c[3];

	if (WheelPos < 85) {
		c[0] = WheelPos * 3;
		c[1] = 255 - WheelPos * 3;
		c[2] = 0;
	} else if (WheelPos < 170) {
		WheelPos -= 85;
		c[0] = 255 - WheelPos * 3;
		c[1] = 0;
		c[2] = WheelPos * 3;
	} else {
		WheelPos -= 170;
		c[0] = 0;
		c[1] = WheelPos * 3;
		c[2] = 255 - WheelPos * 3;
	}

	return c;
}
void RainbowCyclePattern::setup(int speedDelay) {
	RainbowCyclePattern::speedDelay = speedDelay;
}

