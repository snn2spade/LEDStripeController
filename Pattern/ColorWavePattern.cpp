/*
 * ColorWavePattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "ColorWavePattern.h"
#include "../WifiController.h"
#include "../NeopixelUtils.h"
#include "../TaskManager.h"

int ColorWavePattern::waveDelay = 100;

int Position = 0;
void ColorWavePattern::show() {
	Position++; // = 0; //Position + Rate;
	for (int i = 0; i < NeopixelUtils::getNumLED(); i++) {
		// sine wave, 3 offset waves make a rainbow!
		//float level = sin(i+Position) * 127 + 128;
		//setPixel(i,level,0,0);
		//float level = sin(i+Position) * 127 + 128;
		NeopixelUtils::setPixel(i,
				((sin(i + Position) * 127 + 128) / 255) * *WifiController::redInput,
				((sin(i + Position) * 127 + 128) / 255) * *WifiController::greenInput,
				((sin(i + Position) * 127 + 128) / 255) * *WifiController::blueInput);
	}
	NeopixelUtils::showStrip();
	TaskManager::refreshLEDTask->delay(ColorWavePattern::waveDelay);
}

void ColorWavePattern::setup(int waveDelay) {
	ColorWavePattern::waveDelay = waveDelay;
}

