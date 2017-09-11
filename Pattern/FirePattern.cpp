/*
 * RainbowCyclePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "FirePattern.h"
#include "../WifiController.h"


FirePattern::FirePattern(NeopixelUtils * neoPixelUtils) {
	this->neoPixelUtils = neoPixelUtils;
	this->numLED = neoPixelUtils->getNumLED();
	this->isStart = false;
}

FirePattern::~FirePattern() {
	// TODO Auto-generated destructor stub
}

void FirePattern::show(int Cooling, int Sparking, int SpeedDelay) {
	isStart = true;
	WifiController::handleClient();
	static byte heat[60];
	int cooldown;

	// Step 1.  Cool down every cell a little
	for (int i = 0; i < numLED; i++) {
		cooldown = random(0, ((Cooling * 10) / numLED) + 2);

		if (cooldown > heat[i]) {
			heat[i] = 0;
		} else {
			heat[i] = heat[i] - cooldown;
		}
	}

	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = numLED - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}

	// Step 3.  Randomly ignite new 'sparks' near the bottom
	if (random(255) < Sparking) {
		int y = random(7);
		heat[y] = heat[y] + random(160, 255);
		//heat[y] = random(160,255);
	}

	// Step 4.  Convert heat to LED colors
	for (int j = 0; j < numLED; j++) {
		setPixelHeatColor(j, heat[j]);
	}

	neoPixelUtils->showStrip();
	delay(SpeedDelay);
}

void FirePattern::setPixelHeatColor(int Pixel, byte temperature) {
	// Scale 'heat' down from 0-255 to 0-191
	byte t192 = round((temperature / 255.0) * 191);

	// calculate ramp up from
	byte heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2; // scale up to 0..252

	// figure out which third of the spectrum we're in:
	if (t192 > 0x80) {                     // hottest
		neoPixelUtils->setPixel(Pixel, 255, 255, heatramp);
	} else if (t192 > 0x40) {             // middle
		neoPixelUtils->setPixel(Pixel, 255, heatramp, 0);
	} else {                               // coolest
		neoPixelUtils->setPixel(Pixel, heatramp, 0, 0);
	}
}

void FirePattern::showExample() {
	for (int i = 0; i < 200; i++) {
		if (!isStart)
			break;
		show(20, 50, 50);
	}
}

void FirePattern::stop() {
	isStart = false;
}

