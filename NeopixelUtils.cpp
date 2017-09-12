/*
 * NeopixelUtils.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "NeopixelUtils.h"
#define PIN D1
#define NUM_LEDS 60

Adafruit_NeoPixel * NeopixelUtils::strip = new Adafruit_NeoPixel(NUM_LEDS, PIN,
		NEO_GRB + NEO_KHZ800);
void NeopixelUtils::showStrip() {
	NeopixelUtils::getStrip()->show();
}

void NeopixelUtils::setPixel(int Pixel, byte red, byte green, byte blue) {
	NeopixelUtils::getStrip()->setPixelColor(Pixel,
			NeopixelUtils::getStrip()->Color(red, green, blue));
}

void NeopixelUtils::setAll(byte red, byte green, byte blue) {
	for (int i = 0; i < NeopixelUtils::getNumLED(); i++) {
		setPixel(i, red, green, blue);
	}
	showStrip();
}

Adafruit_NeoPixel * NeopixelUtils::getStrip() {
	return strip;
}

int NeopixelUtils::getNumLED() {
	return NUM_LEDS;
}

