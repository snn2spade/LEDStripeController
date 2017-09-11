/*
 * ColorWavePattern.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef COLORWAVEPATTERN_H_
#define COLORWAVEPATTERN_H_

#include "../NeopixelUtils.h"
class ColorWavePattern {
public:
	ColorWavePattern(NeopixelUtils * neoPixelUtils);
	virtual ~ColorWavePattern();
	void show(byte red, byte green, byte blue, int WaveDelay);
	void showExample();
	void stop();
private:
	int numLED;
	NeopixelUtils * neoPixelUtils;
	bool isStart;
};

#endif /* COLORWAVEPATTERN_H_ */
