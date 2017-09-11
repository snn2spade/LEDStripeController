/*
 * snowSparkle.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef SNOWSPARKLEPATTERN_H_
#define SNOWSPARKLEPATTERN_H_

#include "../NeopixelUtils.h"
class SnowSparklePattern {
public:
	SnowSparklePattern(NeopixelUtils * neoPixelUtils);
	virtual ~SnowSparklePattern();
	void show(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay);
	void showExample();
	void stop();
private:
	NeopixelUtils * neoPixelUtils;
	int numLED;
	bool isStart;
};

#endif /* SNOWSPARKLEPATTERN_H_ */
