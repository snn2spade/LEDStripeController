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
	NeopixelUtils(int numLED,Adafruit_NeoPixel * strip);
	virtual ~NeopixelUtils();
	void showStrip();
	void setPixel(int Pixel, byte red, byte green, byte blue);
	void setAll(byte red, byte green, byte blue);
	Adafruit_NeoPixel * getStrip();
	int getNumLED();
private:
	Adafruit_NeoPixel * strip;
	int numLED;
};

#endif /* NEOPIXELUTILS_H_ */
