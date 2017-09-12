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
	static void show();
	static void setup(int,int);
private:
	static int Count, SpeedDelay;
	static bool OnlyOne;
};

#endif /* PATTERN_TWINKLEPATTERN_H_ */
