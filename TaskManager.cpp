/*
 * taskScheduler.cpp
 *
 *  Created on: Sep 12, 2560 BE
 *      Author: snn2spade
 */

#include "TaskManager.h"
#include "LEDController.h"
#include "WifiController.h"

Scheduler * TaskManager::runner = new Scheduler();
Task * TaskManager::handleHTTPTask = new Task(100, TASK_FOREVER, &TaskManager::handleClientRequest);
Task * TaskManager::handleStateTask = new Task(200, TASK_FOREVER, &TaskManager::handleStateChange);
Task * TaskManager::refreshLEDTask = new Task(TASK_IMMEDIATE, TASK_FOREVER);
int TaskManager::modeState = -1;

void TaskManager::handleClientRequest() {
	WifiController::handleClient();
}

void TaskManager::handleStateChange() {
	if (*(WifiController::isStartInput)) {
		if (modeState != *(WifiController::modeInput)) {
			modeState = *(WifiController::modeInput);
			Serial.print("Mode was changed to: ");
			Serial.println(modeState);
			LEDController::setMode(*(WifiController::modeInput));
		}
		LEDController::start();
	} else {
		LEDController::stop();
	}
}
void TaskManager::setup() {
	TaskManager::runner->init();
	TaskManager::runner->addTask(*TaskManager::handleHTTPTask);
	TaskManager::handleHTTPTask->enable();
	TaskManager::runner->addTask(*TaskManager::handleStateTask);
	TaskManager::handleStateTask->enable();
	TaskManager::runner->addTask(*TaskManager::refreshLEDTask);
	TaskManager::refreshLEDTask->disable();
}
