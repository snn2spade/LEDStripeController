/*
 * SolidPattern.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "SolidPattern.h"
#include "../WifiController.h"
#include "../NeopixelUtils.h"
#include "../TaskManager.h"

void SolidPattern::show() {
	NeopixelUtils::setAll(*WifiController::redInput, *WifiController::greenInput, *WifiController::blueInput);
	NeopixelUtils::showStrip();
}

void SolidPattern::setup() {

}

