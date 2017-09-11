/*
 * snowSparkle.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "SnowSparklePattern.h"
#include "../WifiController.h"

SnowSparklePattern::SnowSparklePattern(NeopixelUtils * neoPixelUtils) {
	this->neoPixelUtils = neoPixelUtils;
	this->numLED = neoPixelUtils->getNumLED();
	this->isStart = false;
}

SnowSparklePattern::~SnowSparklePattern() {
	// TODO Auto-generated destructor stub
}

void SnowSparklePattern::show(byte red, byte green, byte blue, int SparkleDelay,
		int SpeedDelay) {
	isStart = true;
	WifiController::handleClient();
	neoPixelUtils->setAll(red, green, blue);
	int Pixel = random(numLED);
	neoPixelUtils->setPixel(Pixel, 0xff, 0xff, 0xff);
	neoPixelUtils->showStrip();
	delay(SparkleDelay);
	neoPixelUtils->setPixel(Pixel, red, green, blue);
	neoPixelUtils->showStrip();
	delay(SpeedDelay);
}

void SnowSparklePattern::showExample() {
	for (int i = 0; i < 20; i++) {
		if(!isStart)
			break;
		show(0x10, 0x10, 0x10, 20, random(100, 1000));
	}
}

void SnowSparklePattern::stop(){
	isStart = false;
}

