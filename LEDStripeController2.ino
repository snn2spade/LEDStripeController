#include "TaskManager.h"
#include "LEDController.h"
#include "WifiController.h"

void setup() {
	Serial.begin(115200);
	Serial.println("\n\n\n");
	Serial.println("STATE: TaskManager setup");
	TaskManager::setup();
	Serial.println("STATE: WIFI Controller setup");
    WifiController::startAPMode();
	Serial.println("STATE: Client handler setup");
    WifiController::setupClientHandler();
	Serial.println("STATE: LED Controller setup");
	LEDController::setup();
	Serial.println("INFO: --- setup completed ---");
}

void loop() {
	TaskManager::runner->execute();
}

