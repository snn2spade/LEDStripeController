/*
 * taskScheduler.h
 *
 *  Created on: Sep 12, 2560 BE
 *      Author: snn2spade
 */

#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <TaskScheduler.h>
class TaskManager {
public:
	static Scheduler * runner;
	static Task * handleHTTPTask;
	static Task * handleStateTask;
	static Task * refreshLEDTask;
	static void setup();
	static void handleClientRequest();
	static void handleStateChange();
	static int modeState;
};

#endif /* TASKMANAGER_H_ */
