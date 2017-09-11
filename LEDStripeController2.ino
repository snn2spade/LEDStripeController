#include "LEDController.h"
#include "WifiController.h"

LEDController ledController = LEDController();

void setup() {
	Serial.begin(115200);
	WifiController::setup();
	ledController.setup();
}

int modeState = -1;
void loop() {
	WifiController::handleClient();
	if(*(WifiController::isStartInput)){
		if(modeState != *(WifiController::modeInput)){
			modeState = *(WifiController::modeInput);
			Serial.print("Mode was changed to: ");
			Serial.println(modeState);
			switch(*(WifiController::modeInput)){
				case(0):
					ledController.playExample();
					break;
			}
		}
	}else{
		ledController.stop();
	}
}

