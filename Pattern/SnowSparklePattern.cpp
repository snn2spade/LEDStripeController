/*
 * snowSparkle.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "SnowSparklePattern.h"
#include "../WifiController.h"
#include "../NeopixelUtils.h"
#include "../TaskManager.h"

int SnowSparklePattern::SparkleDelay = 10;
int SnowSparklePattern::minSpeedDelay = 100;
int SnowSparklePattern::maxSpeedDelay = 1000;
void SnowSparklePattern::show() {
	int SpeedDelay = random(minSpeedDelay, maxSpeedDelay);
	NeopixelUtils::setAll(*WifiController::redInput,
			*WifiController::greenInput, *WifiController::blueInput);
	int Pixel = random(NeopixelUtils::getNumLED());
	NeopixelUtils::setPixel(Pixel, 0xff, 0xff, 0xff);
	NeopixelUtils::showStrip();
	TaskManager::refreshLEDTask->delay(SparkleDelay);
	NeopixelUtils::setPixel(Pixel, *WifiController::redInput,
			*WifiController::greenInput, *WifiController::blueInput);
	NeopixelUtils::showStrip();
	TaskManager::refreshLEDTask->delay(SpeedDelay);
}

void SnowSparklePattern::setup(int SparkleDelay, int minSpeedDelay,
		int maxSpeedDelay) {
	SnowSparklePattern::SparkleDelay = SparkleDelay;
	SnowSparklePattern::minSpeedDelay = minSpeedDelay;
	SnowSparklePattern::maxSpeedDelay = maxSpeedDelay;
}

void SnowSparklePattern::resetToDefaultColor(){
	*WifiController::redInput = 10;
	*WifiController::greenInput = 10;
	*WifiController::blueInput = 10;
}
