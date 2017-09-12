/*
 * wifiController.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "WifiController.h"
#include "HTMLGenerator.h"
#include "Pattern/ColorWavePattern.h"
#include "Pattern/FirePattern.h"
#include "Pattern/RainbowCyclePattern.h"
#include "Pattern/SnowSparklePattern.h"
#include "Pattern/TwinklePattern.h"

MDNSResponder mdns;
String webPage;
ESP8266WebServer * WifiController::server = new ESP8266WebServer(80);
int * WifiController::redInput = new int(11);
int * WifiController::greenInput = new int(11);
int * WifiController::blueInput = new int(128);
int * WifiController::modeInput = new int(0);
bool * WifiController::isStartInput = new bool(false);
void WifiController::setup() {
	// STATE: wait for station mode connection
	Serial.print("STATE: establish station mode connection ");
	WiFi.begin("wongpian  2.4G", "***REMOVED***");
	//WiFi.begin("Earth's wifi 2.4 Ghz", "***REMOVED***");
	while (WiFi.status() != WL_CONNECTED) {
		if (WiFi.status() == WL_NO_SSID_AVAIL) {
			Serial.println("\nSSID is cannot be reached");
		} else if (WiFi.status() == WL_CONNECT_FAILED) {
			Serial.println("\nnetwork password is incorrect");
		}
		delay(500);
		Serial.print(".");
	}
	Serial.print("\n-- Connected, IP address: ");
	Serial.println(WiFi.localIP());

	// STATE: prepare mDNS responder
	Serial.println("STATE: prepare mDNS responder");
	if (mdns.begin("esp8266", WiFi.localIP())) {
		Serial.println("-- MDNS responder started");
	}

	// STATE: init webServerAPI
	Serial.println("STATE: initial web server API");
	WifiController::initWebServerAPI();
	WifiController::server->begin();
	Serial.print("-- server has started on http://");
	Serial.println(WiFi.localIP());

	// STATE: setup hardware interface port
	Serial.println("STATE: setup hardware interface");
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.println("INFO: start loop section");
}

void WifiController::initWebServerAPI() {
	WifiController::server->on("/", []() {
		Serial.println("INFO: client has request for Homepage");
		HTMLGenerator::sendHomepage();
		Serial.println("INFO: already send response for Homepage");
	});
	WifiController::server->on("/setcolor",
			[]() {
				*WifiController::redInput = WifiController::server->arg("red").toInt();
				*WifiController::greenInput = WifiController::server->arg("green").toInt();
				*WifiController::blueInput = WifiController::server->arg("blue").toInt();
				WifiController::server->send(200, "text/html", "set color completed");
			});
	WifiController::server->on("/mode",
			[]() {
				*WifiController::modeInput = WifiController::server->arg("mode").toInt();
				WifiController::server->send(200, "text/html", "set mode completed");
			});
	WifiController::server->on("/start", []() {
		*WifiController::isStartInput = true;
		WifiController::server->send(200, "text/html", "start completed");
	});
	WifiController::server->on("/stop", []() {
		*WifiController::isStartInput = false;
		WifiController::server->send(200, "text/html", "stop completed");
	});
	WifiController::server->on("/setupmode1", []() {
		int delay = WifiController::server->arg("delay").toInt();
		ColorWavePattern::setup(delay);
		WifiController::server->send(200, "text/html", "setup completed");
	});
	WifiController::server->on("/setupmode2", []() {
		int cooling = WifiController::server->arg("cooling").toInt();
		int sparking = WifiController::server->arg("sparking").toInt();
		int delay = WifiController::server->arg("delay").toInt();
		FirePattern::setup(cooling,sparking,delay);
		WifiController::server->send(200, "text/html", "setup completed");
	});
	WifiController::server->on("/setupmode3", []() {
		int delay = WifiController::server->arg("delay").toInt();
		RainbowCyclePattern::setup(delay);
		WifiController::server->send(200, "text/html", "setup completed");
	});
	WifiController::server->on("/setupmode4", []() {
		int sparkle = WifiController::server->arg("sparkle").toInt();
		int minDelay = WifiController::server->arg("mindelay").toInt();
		int maxDelay = WifiController::server->arg("maxdelay").toInt();
		SnowSparklePattern::setup(sparkle,minDelay,maxDelay);
		WifiController::server->send(200, "text/html", "setup completed");
	});
	WifiController::server->on("/setupmode5", []() {
		int count = WifiController::server->arg("count").toInt();
		int delay = WifiController::server->arg("delay").toInt();
		TwinklePattern::setup(count,delay);
		WifiController::server->send(200, "text/html", "setup completed");
	});
	WifiController::server->on("/resetcolor", []() {
		switch(*modeInput){
			case 4:
				SnowSparklePattern::resetToDefaultColor();
				break;
		}
		WifiController::server->send(200, "text/html", "reset color completed");
	});
}

void WifiController::handleClient() {
	WifiController::server->handleClient();
}
