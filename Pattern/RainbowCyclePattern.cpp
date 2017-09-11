/*
 * RainbowCyclePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "RainbowCyclePattern.h"
#include "../WifiController.h"

RainbowCyclePattern::RainbowCyclePattern(NeopixelUtils * neoPixelUtils) {
	this->neoPixelUtils = neoPixelUtils;
	this->isStart = false;
}

RainbowCyclePattern::~RainbowCyclePattern() {
	// TODO Auto-generated destructor stub
}

void RainbowCyclePattern::show(int speedDelay) {
	isStart = true;
	byte *c;
	uint16_t i, j;

	for (j = 0; j < 256 * 2; j++) { // 5 cycles of all colors on wheel
		if (!isStart)
			break;
		WifiController::handleClient();
		for (i = 0; i < neoPixelUtils->getNumLED(); i++) {
			c = wheel(((i * 256 / neoPixelUtils->getNumLED()) + j) & 255);
			neoPixelUtils->setPixel(i, *c, *(c + 1), *(c + 2));
		}
		neoPixelUtils->showStrip();
		delay(speedDelay);
	}
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

void RainbowCyclePattern::showExample() {
	show(20);
}
void RainbowCyclePattern::stop() {
	isStart = false;
}

