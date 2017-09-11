/*
 * NeopixelUtils.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "NeopixelUtils.h"

NeopixelUtils::NeopixelUtils(int numLED, Adafruit_NeoPixel * strip) {
	this->strip = strip;
	this->numLED = numLED;
}

NeopixelUtils::~NeopixelUtils() {
	// TODO Auto-generated destructor stub
}

void NeopixelUtils::showStrip() {
	strip->show();
}

void NeopixelUtils::setPixel(int Pixel, byte red, byte green, byte blue) {
	strip->setPixelColor(Pixel, strip->Color(red, green, blue));
}

void NeopixelUtils::setAll(byte red, byte green, byte blue) {
	for (int i = 0; i < numLED; i++) {
		setPixel(i, red, green, blue);
	}
	showStrip();
}

Adafruit_NeoPixel * NeopixelUtils::getStrip() {
	return strip;
}

int NeopixelUtils::getNumLED() {
	return numLED;
}

