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
	static void show();
	static void setup(int,int,int);
private:
	static int Cooling, Sparking, SpeedDelay;
	static void setPixelHeatColor(int Pixel, byte temperature);
};

#endif
