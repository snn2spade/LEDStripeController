/*
 * wifiController.cpp
 *
 *  Created on: Sep 9, 2560 BE
 *      Author: snn2spade
 */

#include "WifiController.h"
#include "HTMLGenerator.h"

MDNSResponder mdns;
String webPage;
ESP8266WebServer * WifiController::server = new ESP8266WebServer(80);
int * WifiController::redInput = new int(0);
int * WifiController::greenInput = new int(0);
int * WifiController::blueInput = new int(0);
int * WifiController::modeInput = new int(0);
bool * WifiController::isStartInput = new bool(false);
void WifiController::setup() {
	// STATE: wait for station mode connection
	Serial.println("\n\n\n");
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
	WifiController::server->on("/",
			[]() {
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
//	server->on("/test", []() {
//		std::string html = HTMLGenerator::getHTML();
//		server->send(200, "text/html", html);
//});
}

void WifiController::handleClient() {
	WifiController::server->handleClient();
}
