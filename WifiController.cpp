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
bool * WifiController::isAPMode = new bool(true);

int * WifiController::redInput = new int(11);
int * WifiController::greenInput = new int(11);
int * WifiController::blueInput = new int(128);
int * WifiController::modeInput = new int(1);
bool * WifiController::isStartInput = new bool(false);

void WifiController::setupClientHandler(){
	WifiController::initClientHandler();
	WifiController::server->begin();

}

void WifiController::startAPMode() {
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.println("STATE: establish access point mode connection ");
	WiFi.softAP("Led Controller");
	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
}

void WifiController::stopAPMode(){
	WiFi.softAPdisconnect();
	WiFi.disconnect();
	WiFi.mode(WIFI_STA);
	delay(100);
}

void WifiController::stopSTAMode(){
	WiFi.disconnect();
	WiFi.mode(WIFI_AP);
	delay(100);
}

void WifiController::startSTAMode(String ssid,String pass){
	Serial.println("STATE: STOP Access Point mode");
	WifiController::stopAPMode();
	Serial.println("STATE: establish station mode connection ");
	Serial.println("STATE: try to connect ssid: '"+ssid+"', pass:'"+pass+"'");
	WiFi.begin(ssid.c_str(),pass.c_str());
	//WiFi.begin("Earth's wifi 2.4 Ghz", "***REMOVED***");
	int retryCount = 0;
	while(WiFi.status() != WL_CONNECTED){
		digitalWrite(LED_BUILTIN, LOW);
		delay(500);
		digitalWrite(LED_BUILTIN, HIGH);
		retryCount++;
		if (WiFi.status() == WL_NO_SSID_AVAIL) {
			Serial.print("SSID is cannot be reached ");
		} else if (WiFi.status() == WL_CONNECT_FAILED) {
			Serial.print("network password is incorrect ");
		}
		else{
			Serial.print("Unknown status but not yet connected ");
		}
		Serial.println(retryCount);
		if(retryCount > 25 || WiFi.status() == WL_CONNECT_FAILED){
			Serial.println("STATE: Connection Time Out");
			Serial.println("STATE: STOP Station mode");
			WifiController::stopSTAMode();
			Serial.println("STATE: Start Access Point mode");
			WifiController::startAPMode();
			digitalWrite(LED_BUILTIN, LOW);
			return;
		}

	}
	digitalWrite(LED_BUILTIN, HIGH);
	isAPMode = new bool(false);
	Serial.println("STATE: Connected to Local network, IP address: ");
	Serial.println(WiFi.localIP());

	Serial.print("-- server has started on http://");
	Serial.println(WiFi.localIP());
}

void WifiController::initClientHandler() {
	WifiController::server->on("/connect", []() {
		String ssid = WifiController::server->arg("ssid");
		String pass = WifiController::server->arg("pass");
		WifiController::startSTAMode(ssid,pass);
		WifiController::server->send(200, "text/html", "Try connecting local network please try again in 15 Second.");
	});
	WifiController::server->on("/networkinfo", []() {
		if(*WifiController::isAPMode)
		{
			WifiController::server->send(200, "text/html", "Connection mode: Access Point");
		}
		else{
			WifiController::server->send(200, "text/html", "Connection mode: Station");
		}
	});
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
				WifiController::server->send(200, "text/html", "Set color completed");
			});
	WifiController::server->on("/mode",
			[]() {
				*WifiController::modeInput = WifiController::server->arg("mode").toInt();
				HTMLGenerator::sendHomepage();
			});
	WifiController::server->on("/start", []() {
		*WifiController::isStartInput = true;
		HTMLGenerator::sendHomepage();
	});
	WifiController::server->on("/stop", []() {
		*WifiController::isStartInput = false;
		HTMLGenerator::sendHomepage();
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
