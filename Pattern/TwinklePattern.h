/*
 * TwinklePattern.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef PATTERN_TWINKLEPATTERN_H_
#define PATTERN_TWINKLEPATTERN_H_

#include "../NeopixelUtils.h"
class TwinklePattern {
public:
	TwinklePattern(NeopixelUtils * neoPixelUtils);
	virtual ~TwinklePattern();
	void show(int Count, int SpeedDelay, bool OnlyOne);
	void showExample();
	void stop();
private:
	int numLED;
	NeopixelUtils * neoPixelUtils;
	bool isStart;
};

#endif /* PATTERN_TWINKLEPATTERN_H_ */
