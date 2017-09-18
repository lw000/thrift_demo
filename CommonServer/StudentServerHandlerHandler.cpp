/*
 * StudentServer.cpp
 *
 *  Created on: Sep 15, 2017
 *      Author: root
 */

#include <CommonServer/StudentServerHandlerHandler.h>


StudentServerHandler::StudentServerHandler() {
	// TODO Auto-generated constructor stub

}

StudentServerHandler::~StudentServerHandler() {
	// TODO Auto-generated destructor stub
}

int32_t StudentServerHandler::put(const Student& s) {
	printf("%5d, %15d, %3d, %s \n", s.sage, s.sno, s.ssex, s.sname.c_str());

	return 0;
}

void StudentServerHandler::login(const std::string& name, const std::string& psd) {

}

void StudentServerHandler::logout() {

}

int32_t StudentServerHandler::send(const int32_t s, const int32_t t,
		const std::string& data) {
	return 0;
}

int32_t StudentServerHandler::add(const int32_t a, const int32_t b) {
	return 0;
}

int32_t StudentServerHandler::sum(const int32_t v) {
	int c = 0;
	for (int i = 0; i < v; i++) {
		c += i;
	}
	return c;
}


