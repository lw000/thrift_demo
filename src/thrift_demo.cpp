// server.cpp
//

#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <stdio.h>
#include <fstream>
#include <thread>
#include <getopt.h>
#include <cassert>

#include <src/rpc_client.h>
#include <src/rpc_server.h>

#if 0
//#include <json/json.h>
#else
#include "rapidjson/document.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/reader.h"

using namespace rapidjson;

#endif

#include "log4z.h"
using namespace zsummer::log4z;

#include "net.h"
#include "utils.h"

struct thread_args {
	std::string addr;
	int port;
};

static void thread_run_ipc_client(void* args) {
	thread_args * targs = (thread_args*) (args);
	run_ipc_client(targs->addr.c_str(), targs->port);
}

static void thread_run_ipc_server(void* args) {
	thread_args * targs = (thread_args*) (args);
	run_ipc_nonblocking_server(targs->addr.c_str(), targs->port);
}

int main(int argc, char** argv) {

	if (argc < 2) {
		return 0;
	}

	std::string conf;
	int ch = 0;
	while ((ch = getopt(argc, argv, "c:")) != -1) {
		switch (ch) {
		case 'c': {
			if (optarg != NULL) {
				conf = optarg;
			}
			break;
		}
		default: {
			fprintf(stderr, "(-c config.conf)\n");
			break;
		}
		}
	}

	if (conf.empty()) {
		return 0;
	}

	//	{
	//		"platform":"s",
	//	    "host": "127.0.0.1",
	//	    "port": 8003
	//	}

	std::string s;
	std::string host;
	int port;
	{
		std::ifstream ifs;
		ifs.open(conf.c_str());
		assert(ifs.is_open());
#if 0
		Json::Reader reader;
		Json::Value root;
		if (!reader.parse(ifs, root, false)) {
			return -1;
		}
		s = root["platform"].asString();
		host = root["host"].asString();
		port = root["port"].asInt();
#else
		std::string line;
		std::string strjson;
		while (std::getline(ifs, line))
		{
			strjson.append(line);
		}

		rapidjson::Document root;
		root.Parse<0>(strjson.c_str());
		if (root.HasParseError()) {
			return -1;
		}
		s = root["platform"].GetString();
		host = root["host"].GetString();
		port = root["port"].GetInt();
#endif
	}
	
	SocketInit sInit;

	ILog4zManager::getInstance()->start();

	//"47.91.140.210"

	thread_args targs = { host, port };

	if (s.compare("s") == 0) {
		std::thread t(thread_run_ipc_server, &targs);
		t.join();
	} else if (s.compare("c") == 0) {
		std::thread t(thread_run_ipc_client, &targs);
		t.join();
	} else {
		printf("error. \n");
	}

	while (1) {
		lw_sleep(1);
	}

	return 0;
}

