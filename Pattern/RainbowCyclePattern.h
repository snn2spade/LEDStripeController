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
	static void show();
	static void setup(int);
private:
	static byte *  wheel(byte WheelPos);
	static int speedDelay;
};

#endif
