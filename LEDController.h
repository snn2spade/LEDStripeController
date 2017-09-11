/*
 * LEDController.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef LEDCONTROLLER_H_
#define LEDCONTROLLER_H_

#include <Adafruit_NeoPixel.h>
#include "NeopixelUtils.h"
#include "Pattern/RainbowCyclePattern.h"
#include "Pattern/FirePattern.h"
#include "Pattern/ColorWavePattern.h"
#include "Pattern/SnowSparklePattern.h"
#include "Pattern/TwinklePattern.h"

#define PIN D1
#define NUM_LEDS 60


class LEDController {
public:
	LEDController();
	virtual ~LEDController();
	void setup();
	RainbowCyclePattern * rainbowCycleMode;
	FirePattern * fireMode;
	ColorWavePattern * colorWaveMode;
	SnowSparklePattern * snowSparkleMode;
	TwinklePattern * twinklePatternMode;
	void playExample();
	void stop();
private:
	Adafruit_NeoPixel * strip;
	NeopixelUtils * neopixelUtils;
};

#endif /* LEDCONTROLLER_H_ */
