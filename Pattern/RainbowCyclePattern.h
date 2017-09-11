/*
 * RainbowCyclePattern.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef RAINBOWCYCLEPATTERN_H_
#define RAINBOWCYCLEPATTERN_H_

#include "../NeopixelUtils.h"
class RainbowCyclePattern {
public:
	RainbowCyclePattern(NeopixelUtils  * neopixelUtils);
	virtual ~RainbowCyclePattern();
	void show(int speedDelay);
	void showExample();
	void stop();
private:
	byte *  wheel(byte WheelPos);
	NeopixelUtils * neoPixelUtils;
	bool isStart;
};

#endif
