/*
 * StudentServer.h
 *
 *  Created on: Sep 15, 2017
 *      Author: root
 */

#ifndef STUDENTSERVERHANDLERHANDLER_H_
#define STUDENTSERVERHANDLERHANDLER_H_

#include <gen-cpp/Server.h>

using namespace ::LW;

class StudentServerHandler: public LW::ServerIf {
public:
	StudentServerHandler();
	virtual ~StudentServerHandler();

public:
	virtual int32_t put(const Student& s);

	virtual void login(const std::string& name, const std::string& psd);

	virtual void logout();

	virtual int32_t send(const int32_t s, const int32_t t,
			const std::string& data);

	virtual int32_t add(const int32_t a, const int32_t b);

	virtual int32_t sum(const int32_t v) ;

};

#endif /* STUDENTSERVERHANDLERHANDLER_H_ */
