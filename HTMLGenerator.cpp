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

std::string HTMLGenerator::intToStr(int val){
	char str[10];
	sprintf(str, "%d", val);
	return str;
}


void HTMLGenerator::sendHomepage() {
	//  retrieve current mode
	int modeInputInt = *(WifiController::modeInput);
	char str[10];
	sprintf(str, "%d", modeInputInt);
	std::string modeInput = str;
	// Retrieve current start state
	std::string startInput;
	if(*(WifiController::isStartInput)){
		startInput = "<span style='color:green;'>STARTED</span>";
	}
	else{
		startInput = "<span style='color:red;'>STOP</span>";
	}
	std::string connectionMode;
	if(*WifiController::isAPMode){
		connectionMode = "AP Mode";
	}
	else{
		connectionMode = "AP & Station Mode";
	}
	// Retrieve current color
	std::string redInput = HTMLGenerator::intToStr(*(WifiController::redInput));
	std::string blueInput = HTMLGenerator::intToStr(*(WifiController::blueInput));
	std::string greenInput = HTMLGenerator::intToStr(*(WifiController::greenInput));
	std::string res = "<!DOCTYPE html>";
	res += "	<html lang='en'>	";
	res += "	<head>	";
	res += "	<meta charset='utf-8'>	";
	res += "	<meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>	";
	res += "	<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css' integrity='sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ' crossorigin='anonymous'>	";
	res += "	<script src='https://code.jquery.com/jquery-3.2.1.min.js'></script>	";
	res += "	<script src='https://cdnjs.cloudflare.com/ajax/libs/tether/1.4.0/js/tether.min.js' integrity='sha384-DztdAPBWPRXSA/3eYEEUWrWCy7G5KFbe8fFjk5JAIxUYHKkDx6Qin1DkWx51bBrb' crossorigin='anonymous'></script>	";
	res += "	<script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/js/bootstrap.min.js' integrity='sha384-vBWWzlZJ8ea9aCX4pEW3rVHjgjt7zpkNpZk+02D9phzyeVkE+jo0ieGizqPLForn' crossorigin='anonymous'></script>	";
	res += "		";
	res += "	<title>LED Controller WS2812B</title>	";
	res += "		";
	res += "	</head>	";
	res += "	<body>	";
	res += "	<div class='container'>	";
	res += "	<div class='jumbtron'>	";
	res += "	<h1 class='display-4'>WS2812B LED controller</h1>	";
	res += "	<p class='lead'>LED Stripe controller on ESP8266 <span> | connection mode: "+connectionMode+"</span></p>	";
	res += "	<hr class='my-4'>	";
	res += "	</div>	";
	res += "	<div class='row'>	";
	res += "	<div class='col-md-6 mt-3'>	";
	res += "	<div class='card'>	";
	res += "	<h4 class='card-header'>Color</h4>	";
	res += "	<div class='card-block'>	";
	res += "	<form id='colorForm' action='/setcolor' method='post' class='form-horizontal'>	";
	res += "	<div class='form-group'>	";
	res += "	<label class='col-2'>Red:</label>	";
	res += "	<div class='col-10'>	";
	res += "	<input type='number' value='"+redInput+"' min='0' max='255' class='form-control RGBInput' id='redInput' name='red' placeholder='Enter 0 - 255'>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='form-group'>	";
	res += "	<label class='col-2'>Green:</label>	";
	res += "	<div class='col-10'>	";
	res += "	<input type='number' value='"+greenInput+"' min='0' max='255' class='form-control RGBInput' id='greenInput' name='green' placeholder='Enter 0 - 255'>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='form-group'>	";
	res += "	<label class='col-2'>Blue:</label>	";
	res += "	<div class='col-10'>	";
	res += "	<input type='number' value='"+blueInput+"' min='0' max='255' class='form-control RGBInput' id='blueInput' name='blue' placeholder='Enter 0 - 255'>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='form-group'>	";
	res += "	<label class='col-2'>Color</label>	";
	res += "	<div class='col-10'>	";
	res += "	<input style='height:38px' class='form-control' type='color' id='colorWheel' value='#FFFFFF'>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='form-group'>	";
	res += "	<div class='col-10'>	";
	res += "	<button id='colorBtn' type='submit' class='btn btn-primary btn-block'>Submit</button>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</form>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='col-md-6'>	";
	res += "	<div class='row mt-3'>	";
	res += "	<div class='col-12'>	";
	res += "	<div class='card'>	";
	res += "	<h4 class='card-header'>Control</h4>	";
	res += "	<div class='card-block'>	";
	res += "	<p>Status: <span>"+startInput+"</span></p>	";
	res += "	<div class='btn-group'>	";
	res += "	<form method='get' action='/start' class='form-inline'>	";
	res += "	<button id='startBtn' type='submit' class='btn btn-primary'>Start</button>	";
	res += "	</form>	";
	res += "	<form method='get' action='/stop' class='form-inline'>	";
	res += "	<button id='stopBtn' type='submit' style='margin:0 0 0 5px' class='btn btn-danger'>Stop</button>	";
	res += "	</form>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='row mt-3'>	";
	res += "	<div class='col-12'>	";
	res += "	<div class='card'>	";
	res += "	<h4 class='card-header'>Mode</h4>	";
	res += "	<div class='card-block'>	";
	res += "	<form id='modeForm' action='/mode' method='get' class='form-horizontal'>	";
	res += "	<div class='list-group'>	";
	res += "	<input id='modeInput' type='hidden' name='mode' value='"+modeInput+"'>	";
	res += "	<a data-mode='1' class='modeBtn list-group-item list-group-item-action '>Color Wipe</a>	";
	res += "	<a data-mode='2' class='modeBtn list-group-item list-group-item-action '>Set Fire to the rain!</a>	";
	res += "	<a data-mode='3' class='modeBtn list-group-item list-group-item-action '>Rainbow cycle</a>	";
	res += "	<a data-mode='4' class='modeBtn list-group-item list-group-item-action '>Snow sparkle</a>	";
	res += "	<a data-mode='5' class='modeBtn list-group-item list-group-item-action '>Twinkle</a>	";
	res += "	<a data-mode='6' class='modeBtn list-group-item list-group-item-action '>Solid</a>	";
	res += "	</div>	";
	res += "	</form>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<div class='row mt-3'>	";
	res += "	<div class='col-12'>	";
	res += "	<p>powered by snn2spade, 2017</p>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	</div>	";
	res += "	<script type='text/javascript' language='javascript'>	";
	res += "	function toHex(d) {	";
	res += "	return ('0'+(Number(d).toString(16))).slice(-2).toUpperCase()	";
	res += "	}	";
	res += "	function updateColorWheel(){	";
	res += "	let string = '#';	";
	res += "	string = string + toHex($('#redInput').val());	";
	res += "	string = string + toHex($('#greenInput').val());	";
	res += "	string = string + toHex($('#blueInput').val());	";
	res += "	console.log(string);	";
	res += "	$('#colorWheel').val(string);	";
	res += "	}	";
	res += "	$( '.RGBInput' ).change(function() {	";
	res += "	updateColorWheel();	";
	res += "	});	";
	res += "	$( '#colorWheel' ).change(function() {	";
	res += "	let string = $('#colorWheel').val();	";
	res += "	string = string.toUpperCase();	";
	res += "	let redDec = parseInt(string.substr(1,2),16);	";
	res += "	let greenDec = parseInt(string.substr(3,2),16);	";
	res += "	let blueDec = parseInt(string.substr(5,2),16);	";
	res += "	$('#redInput').val(redDec);	";
	res += "	$('#greenInput').val(greenDec);	";
	res += "	$('#blueInput').val(blueDec);	";
	res += "	$('#colorWheel').val(string);	";
	res += "	});	";
	res += "	$('.modeBtn').click(function(e){	";
	res += "	e.preventDefault();	";
	res += "	let mode = $(this).attr('data-mode');	";
	res += "	$('input#modeInput').val(parseInt(mode));	";
	res += "	$('form#modeForm').submit();	";
	res += "	});	";
	res += "	$('#colorBtn').click(function(e){	";
	res += "	e.preventDefault();	";
	res += "	let red = parseInt($('#redInput').val());	";
	res += "	let blue = parseInt($('#blueInput').val());	";
	res += "	let green = parseInt($('#greenInput').val());	";
	res += "	if(isNaN(red) || isNaN(green) || isNaN(blue)){	";
	res += "	console.log('color input cannot be empty');	";
	res += "	}	";
	res += "	else{	";
	res += "	$.ajax({	";
	res += "	url:'/setcolor',	";
	res += "	type:'get',	";
	res += "	data:$('form#colorForm').serialize(),	";
	res += "	success:function(msg){	";
	res += "	console.log(msg);	";
	res += "	}	";
	res += "	});	";
	res += "	}	";
	res += "	});	";
	res += "	window.onload = function(){	";
	res += "	let mode = $('#modeInput').val();	";
	res += "	console.log('current mode: '+mode);	";
	res += "	$('.modeBtn').each(function() {	";
	res += "	if( $(this).attr('data-mode') == mode){	";
	res += "	$(this).addClass('active');	";
	res += "	}	";
	res += "	});	";
	res += "	};	";
	res += "	$(document).ready(function(){	";
	res += "	updateColorWheel();	";
	res += "	});	";
	res += "	</script>	";
	res += "	</body>	";
	res += "	</html>	";
	WifiController::server->send(200, "text/html", res.c_str());
}

