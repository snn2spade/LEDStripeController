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
	static void show();
	static void setup(int,int,int);
	static void resetToDefaultColor();
private:
	static int SparkleDelay;
	static int minSpeedDelay;
	static int maxSpeedDelay;
};

#endif /* SNOWSPARKLEPATTERN_H_ */
