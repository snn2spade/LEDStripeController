/*
 * ColorWavePattern.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef COLORWAVEPATTERN_H_
#define COLORWAVEPATTERN_H_

#include "../NeopixelUtils.h"
#include <TaskScheduler.h>
class ColorWavePattern {
public:
	static void setup(int waveDelay);
	static void show();
private:
	static int waveDelay;
};

#endif /* COLORWAVEPATTERN_H_ */
