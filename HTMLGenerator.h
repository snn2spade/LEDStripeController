/*
 * HTMLGenerator.h
 *
 *  Created on: Sep 10, 2560 BE
 *      Author: snn2spade
 */

#ifndef HTMLGENERATOR_H_
#define HTMLGENERATOR_H_
#include <string>

class HTMLGenerator {
public:
	HTMLGenerator();
	virtual ~HTMLGenerator();
	static void sendHomepage();
	static std::string intToStr(int);
};


#endif /* HTMLGENERATOR_H_ */
