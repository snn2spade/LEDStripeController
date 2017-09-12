/*
 * HTMLGenerator.cpp
 *
 *  Created on: Sep 10, 2560 BE
 *      Author: snn2spade
 */

#include "HTMLGenerator.h"
#include "WifiController.h"
HTMLGenerator::HTMLGenerator() {
	// TODO Auto-generated constructor stub

}

HTMLGenerator::~HTMLGenerator() {
	// TODO Auto-generated destructor stub
}

void HTMLGenerator::sendHomepage() {
	char numstr[21]; // enough to hold all numbers up to 64-bits
	itoa(1, numstr, 10);
	std::string modeHiddeninput = std::string(
			"<input id='modeInput' type='hidden' name='mode' value='") + numstr
			+ std::string("'>");
	std::string res = "<!DOCTYPE html>";
	res += "<html lang='en'>";
	res += "<head>";
	res += "<meta charset='utf-8'>";
	res +=
			"<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>";
	res +=
			"<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css' integrity='sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ' crossorigin='anonymous'>";
	res +=
			"<script src='https://code.jquery.com/jquery-3.1.1.slim.min.js' integrity='sha384-A7FZj7v+d/sdmMqp/nOQwliLvUsJfDHW+k9Omg/a/EheAdgtzNs3hpfag6Ed950n' crossorigin='anonymous'></script>";
	res +=
			"<script src='https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js' integrity='sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb' crossorigin='anonymous'></script>";
	res +=
			"<script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js' integrity='sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn' crossorigin='anonymous'></script>";
	res += "";
	res +=
			"<link href='https://gitcdn.github.io/bootstrap-toggle/2.2.2/css/bootstrap-toggle.min.css' rel='stylesheet'>";
	res +=
			"<script src='https://gitcdn.github.io/bootstrap-toggle/2.2.2/js/bootstrap-toggle.min.js'></script>";
	res += "<title>LED Controller WS2812B</title>";
	res += "";
	res += "</head>";
	res += "<body>";
	res += "<div class='container'>";
	res += "<div class='jumbtron'>";
	res += "<h1 class='display-4'>WS2812B LED controller</h1>";
	res += "<p class='lead'>LED Stripe controller on ESP8266</p>";
	res += "<hr class='my-4'>";
	res += "</div>";
	res += "<div class='row'>";
	res += "<div class='col-md-6 mt-3'>";
	res += "<div class='card'>";
	res += "<h4 class='card-header'>Color</h4>";
	res += "<div class='card-block'>";
	res += "<form action='./setcolor' method='get' class='form-horizontal'>";
	res += "<div class='form-group'>";
	res += "<label class='col-2'>Red:</label>";
	res += "<div class='col-10'>";
	res +=
			"<input type='number' min='0' max='255' class='form-control RGBInput' id='redInput' name='red' placeholder='Enter 0 - 255'>";
	res += "</div>";
	res += "</div>";
	res += "<div class='form-group'>";
	res += "<label class='col-2'>Green:</label>";
	res += "<div class='col-10'>";
	res +=
			"<input type='number' min='0' max='255' class='form-control RGBInput' id='greenInput' name='green' placeholder='Enter 0 - 255'>";
	res += "</div>";
	res += "</div>";
	res += "<div class='form-group'>";
	res += "<label class='col-2'>Blue:</label>";
	res += "<div class='col-10'>";
	res +=
			"<input type='number' min='0' max='255' class='form-control RGBInput' id='blueInput' name='blue' placeholder='Enter 0 - 255'>";
	res += "</div>";
	res += "</div>";
	res += "<div class='form-group'>";
	res += "<label class='col-2'>Color</label>";
	res += "<div class='col-10'>";
	res +=
			"<input style='height:38px' class='form-control' type='color' id='colorWheel' value='#FFFFFF'>";
	res += "</div>";
	res += "</div>";
	res += "<div class='form-group'>";
	res += "<div class='col-10'>";
	res +=
			"<button type='submit' class='btn btn-primary btn-block'>Submit</button>";
	res += "</div>";
	res += "</div>";
	res += "</form>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "<div class='col-md-6'>";
	res += "<div class='row mt-3'>";
	res += "<div class='col-12'>";
	res += "<div class='card'>";
	res += "<h4 class='card-header'>Control</h4>";
	res += "<div class='card-block'>";
	res += "<form action='./setcolor' method='get' class='form-horizontal'>";
	res += "<div class='form-group'>";
	res += "<label class='col-2'>Start/Stop: </label>";
	res += "<div class='col-10'>";
	res +=
			"<input id='startCheckBox' type='checkbox' checked data-toggle='toggle'>";
	res += "</div>";
	res += "</div>";
	res += "</form>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "<div class='row mt-3'>";
	res += "<div class='col-12'>";
	res += "<div class='card'>";
	res += "<h4 class='card-header'>Mode</h4>";
	res += "<div class='card-block'>";
	res += "<form action='./setcolor' method='get' class='form-horizontal'>";
	res += "<div class='list-group'>";
	res += modeHiddeninput;
	res +=
			"<a href='#' id='mode1' class='list-group-item list-group-item-action '>Color Wipe</a>";
	res +=
			"<a href='#' id='mode2' class='list-group-item list-group-item-action '>Set Fire to the rain!</a>";
	res +=
			"<a href='#' id='mode3' class='list-group-item list-group-item-action '>Rainbow cycle</a>";
	res +=
			"<a href='#' id='mode4' class='list-group-item list-group-item-action '>Snow sparkle</a>";
	res +=
			"<a href='#' id='mode5' class='list-group-item list-group-item-action '>Twinkle</a>";
	res += "</div>";
	res += "</form>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "<div class='row mt-3'>";
	res += "<div class='col-12'>";
	res += "<p>powered by snn2spade, 2017</p>";
	res += "</div>";
	res += "</div>";
	res += "</div>";
	res += "<script type='text/javascript' language='javascript'>";
	res += "function toHex(d) {";
	res += "return ('0'+(Number(d).toString(16))).slice(-2).toUpperCase()";
	res += "}";
	res += "$( '.RGBInput' ).change(function() {";
	res += "let string = '#';";
	res += "string = string + toHex($('#redInput').val());";
	res += "string = string + toHex($('#greenInput').val());";
	res += "string = string + toHex($('#blueInput').val());";
	res += "console.log(string);";
	res += "$('#colorWheel').val(string);";
	res += "});";
	res += "$( '#colorWheel' ).change(function() {";
	res += "let string = $('#colorWheel').val();";
	res += "string = string.toUpperCase();";
	res += "let redDec = parseInt(string.substr(1,2),16);";
	res += "let greenDec = parseInt(string.substr(3,2),16);";
	res += "let blueDec = parseInt(string.substr(5,2),16);";
	res += "$('#redInput').val(redDec);";
	res += "$('#greenInput').val(greenDec);";
	res += "$('#blueInput').val(blueDec);";
	res += "});";
	res += "$('form').submit(function () {";
	res += "//alert('Send completed.');";
	res += "});";
	res += "window.onload = function(){";
	res += "let mode = $('#modeInput').val();";
	res += "mode = parseInt(mode);";
	res += "switch(mode){";
	res += "case 1:";
	res += "$('#mode1').addClass('active');";
	res += "break;";
	res += "case 2:";
	res += "$('#mode2').addClass('active');";
	res += "break;";
	res += "case 3:";
	res += "$('#mode3').addClass('active');";
	res += "break;";
	res += "case 4:";
	res += "$('#mode4').addClass('active');";
	res += "break;";
	res += "case 5:";
	res += "$('#mode5').addClass('active');";
	res += "break;";
	res += "}";
	res += "};";
	res += "</script>";
	res += "</body>";
	res += "</html>";
	WifiController::server->send(200, "text/html", res.c_str());
}

