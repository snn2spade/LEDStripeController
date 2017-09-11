/*
 * wifiController.h
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#ifndef WIFICONTROLLER_H_
#define WIFICONTROLLER_H_

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

class WifiController {
public:
	static void setup();
	static void initWebServerAPI();
	static void handleClient();
	static int * redInput;
	static int * greenInput;
	static int * blueInput;
	static int * modeInput;
	static bool * isStartInput;
	static ESP8266WebServer * server;
};

#endif /* WIFICONTROLLER_H_ */
