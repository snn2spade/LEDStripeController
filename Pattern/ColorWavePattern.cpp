/*
 * ColorWavePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "ColorWavePattern.h"
#include "../WifiController.h"

ColorWavePattern::ColorWavePattern(NeopixelUtils * neoPixelUtils) {
	this->neoPixelUtils = neoPixelUtils;
	this->numLED = neoPixelUtils->getNumLED();
	this->isStart = false;
}

ColorWavePattern::~ColorWavePattern() {
	// TODO Auto-generated destructor stub
}

void ColorWavePattern::show(byte red, byte green, byte blue, int WaveDelay) {
	isStart = true;
	int Position = 0;

	for (int i = 0; i < numLED * 2; i++) {
		WifiController::handleClient();
		if (!isStart)
			break;
		Position++; // = 0; //Position + Rate;
		for (int i = 0; i < numLED; i++) {
			// sine wave, 3 offset waves make a rainbow!
			//float level = sin(i+Position) * 127 + 128;
			//setPixel(i,level,0,0);
			//float level = sin(i+Position) * 127 + 128;
			neoPixelUtils->setPixel(i,
					((sin(i + Position) * 127 + 128) / 255) * red,
					((sin(i + Position) * 127 + 128) / 255) * green,
					((sin(i + Position) * 127 + 128) / 255) * blue);
		}

		neoPixelUtils->showStrip();
		delay(WaveDelay);
	}
}
void ColorWavePattern::showExample() {
	for (int i = 0; i < 2; i++) {
		if(!isStart)
			break;
		show(0x22, 0xff, 0x22, 50);
	}
}

void ColorWavePattern::stop() {
	isStart = false;
}
