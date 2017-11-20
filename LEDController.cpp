/*
 * LEDController.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "LEDController.h"
#include "TaskManager.h"
#include "NeopixelUtils.h"
#include "Pattern/ColorWavePattern.h"
#include "Pattern/FirePattern.h"
#include "Pattern/RainbowCyclePattern.h"
#include "Pattern/SnowSparklePattern.h"
#include "Pattern/TwinklePattern.h"
#include "Pattern/SolidPattern.h"

void LEDController::setup() {
	NeopixelUtils::getStrip()->begin();
	NeopixelUtils::getStrip()->show();
	NeopixelUtils::getStrip()->setBrightness(NeopixelUtils::getNumLED());
}

void LEDController::stop() {
	TaskManager::refreshLEDTask->disable();
	NeopixelUtils::setAll(0x00, 0x00, 0x00);
}

void LEDController::start() {
	TaskManager::refreshLEDTask->enable();
}

void LEDController::setMode(int mode) {
	switch (mode) {
	case 1:
		TaskManager::refreshLEDTask->setCallback(&ColorWavePattern::show);
		break;
	case 2:
		TaskManager::refreshLEDTask->setCallback(&FirePattern::show);
		break;
	case 3:
		TaskManager::refreshLEDTask->setCallback(&RainbowCyclePattern::show);
		break;
	case 4:
		TaskManager::refreshLEDTask->setCallback(&SnowSparklePattern::show);
		break;
	case 5:
		TaskManager::refreshLEDTask->setCallback(&TwinklePattern::show);
		break;
	case 6:
		TaskManager::refreshLEDTask->setCallback(&SolidPattern::show);
		break;
	}
}

