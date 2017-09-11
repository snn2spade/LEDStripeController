/*
 * LEDController.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "LEDController.h"

bool isStart = false;
LEDController::LEDController() {
	// Parameter 1 = number of pixels in strip
	// Parameter 2 = pin number (most are valid)
	// Parameter 3 = pixel type flags, add together as needed:
	//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
	//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
	//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
	//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
	strip = new Adafruit_NeoPixel(NUM_LEDS, PIN,
	NEO_GRB + NEO_KHZ800);
	// define neopixelUtils
	neopixelUtils = new NeopixelUtils(NUM_LEDS, strip);
	// define pattern
	rainbowCycleMode = new RainbowCyclePattern(neopixelUtils);
	fireMode = new FirePattern(neopixelUtils);
	colorWaveMode = new ColorWavePattern(neopixelUtils);
	snowSparkleMode = new SnowSparklePattern(neopixelUtils);
	twinklePatternMode = new TwinklePattern(neopixelUtils);
}

LEDController::~LEDController() {
	// TODO Auto-generated destructor stub
}
void LEDController::setup() {
	strip->begin();
	strip->show(); // Initialize all pixels to 'off'
	strip->setBrightness(NUM_LEDS);
}

void LEDController::playExample() {
	rainbowCycleMode->showExample();
	fireMode->showExample();
	colorWaveMode->showExample();
	snowSparkleMode->showExample();
	twinklePatternMode->showExample();
}

void LEDController::stop(){
	rainbowCycleMode->stop();
	fireMode->stop();
	colorWaveMode->stop();
	snowSparkleMode->stop();
	twinklePatternMode->stop();
	neopixelUtils->setAll(0x00, 0x00, 0x00);
}
