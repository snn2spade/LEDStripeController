/*
 * TwinklePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "TwinklePattern.h"
#include "../WifiController.h"
#include "../NeopixelUtils.h"
#include "../TaskManager.h"

int TwinklePattern::Count = 20;
int TwinklePattern::SpeedDelay = 100;
bool TwinklePattern::OnlyOne = false;

int countIndex = 0;
void TwinklePattern::show() {

	if (countIndex == Count) {
		NeopixelUtils::setAll(0, 0, 0);
		countIndex = 0;
	} else {
		NeopixelUtils::setPixel(random(NeopixelUtils::getNumLED()),
				random(0, 255), random(0, 255), random(0, 255));
		NeopixelUtils::showStrip();
		TaskManager::refreshLEDTask->delay(SpeedDelay);
		if (OnlyOne) {
			NeopixelUtils::setAll(0, 0, 0);
		}
		countIndex++;
	}
}

void TwinklePattern::setup(int Count, int SpeedDelay) {
	TwinklePattern::Count = Count;
	TwinklePattern::SpeedDelay = SpeedDelay;
	TwinklePattern::OnlyOne = false;

}

