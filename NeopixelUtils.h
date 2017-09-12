/*
 * NeopixelUtils.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef NEOPIXELUTILS_H_
#define NEOPIXELUTILS_H_

#include <Adafruit_NeoPixel.h>
class NeopixelUtils {
public:
	static void showStrip();
	static void setPixel(int Pixel, byte red, byte green, byte blue);
	static void setAll(byte red, byte green, byte blue);
	static Adafruit_NeoPixel * getStrip();
	static int getNumLED();
private:
	static Adafruit_NeoPixel * strip;
};

#endif /* NEOPIXELUTILS_H_ */
