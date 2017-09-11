/*
 * RainbowCyclePattern.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef FIREPATTERN_H_
#define FIREPATTERN_H_

#include "../NeopixelUtils.h"
class FirePattern {
public:
	FirePattern(NeopixelUtils  * neopixelUtils);
	virtual ~FirePattern();
	void show(int Cooling, int Sparking, int SpeedDelay);
	void showExample();
	void stop();
private:
	NeopixelUtils * neoPixelUtils;
	void setPixelHeatColor(int Pixel, byte temperature);
	int numLED;
	bool isStart;
};

#endif
