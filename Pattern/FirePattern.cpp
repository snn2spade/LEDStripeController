/*
 * RainbowCyclePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "FirePattern.h"
#include "../WifiController.h"
#include "../NeopixelUtils.h"
#include "../TaskManager.h"

int FirePattern::Cooling = 20;
int FirePattern::Sparking = 20;
int FirePattern::SpeedDelay = 50;
void FirePattern::show() {
	static byte heat[60];
	int cooldown;

	// Step 1.  Cool down every cell a little
	for (int i = 0; i < NeopixelUtils::getNumLED(); i++) {
		cooldown = random(0, ((Cooling * 10) / NeopixelUtils::getNumLED()) + 2);

		if (cooldown > heat[i]) {
			heat[i] = 0;
		} else {
			heat[i] = heat[i] - cooldown;
		}
	}

	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = NeopixelUtils::getNumLED() - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}

	// Step 3.  Randomly ignite new 'sparks' near the bottom
	if (random(255) < Sparking) {
		int y = random(7);
		heat[y] = heat[y] + random(160, 255);
		//heat[y] = random(160,255);
	}

	// Step 4.  Convert heat to LED colors
	for (int j = 0; j < NeopixelUtils::getNumLED(); j++) {
		setPixelHeatColor(j, heat[j]);
	}

	NeopixelUtils::showStrip();
	TaskManager::refreshLEDTask->delay(SpeedDelay);
}

void FirePattern::setPixelHeatColor(int Pixel, byte temperature) {
	// Scale 'heat' down from 0-255 to 0-191
	byte t192 = round((temperature / 255.0) * 191);

	// calculate ramp up from
	byte heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2; // scale up to 0..252

	// figure out which third of the spectrum we're in:
	if (t192 > 0x80) {                     // hottest
		NeopixelUtils::setPixel(Pixel, 255, 255, heatramp);
	} else if (t192 > 0x40) {             // middle
		NeopixelUtils::setPixel(Pixel, 255, heatramp, 0);
	} else {                               // coolest
		NeopixelUtils::setPixel(Pixel, heatramp, 0, 0);
	}
}
void FirePattern::setup(int Cooling, int Sparking, int SpeedDelay) {
	FirePattern::Cooling = Cooling;
	FirePattern::Sparking = Sparking;
	FirePattern::SpeedDelay = SpeedDelay;
}

