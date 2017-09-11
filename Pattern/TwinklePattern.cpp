/*
 * TwinklePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "TwinklePattern.h"
#include "../WifiController.h"

TwinklePattern::TwinklePattern(NeopixelUtils * neoPixelUtils) {
	this->neoPixelUtils = neoPixelUtils;
	this->numLED = neoPixelUtils->getNumLED();
	this->isStart = false;
}

TwinklePattern::~TwinklePattern() {
	// TODO Auto-generated destructor stub
}

void TwinklePattern::show(int Count, int SpeedDelay, bool OnlyOne) {
	isStart = true;
	neoPixelUtils->setAll(0, 0, 0);
	for (int i = 0; i < Count; i++) {
		if(!isStart)
			break;
		WifiController::handleClient();
		neoPixelUtils->setPixel(random(numLED), random(0, 255), random(0, 255),
				random(0, 255));
		neoPixelUtils->showStrip();
		delay(SpeedDelay);
		if (OnlyOne) {
			neoPixelUtils->setAll(0, 0, 0);
		}
	}

	delay(SpeedDelay);
}

void TwinklePattern::showExample() {
	for (int i = 0; i < 5; i++) {
		if(!isStart)
			break;
		show(20, 100, false);
	}
}
void TwinklePattern::stop(){
	isStart =false;
}

