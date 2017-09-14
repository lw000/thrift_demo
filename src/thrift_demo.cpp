// server.cpp
//

#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#endif

#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <thread>
#include <getopt.h>

#include <src/client.h>
#include <src/server.h>

#include <log4z/log4z.h>
using namespace zsummer::log4z;

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
	run_ipc_server(targs->port);
}

int main(int argc, char** argv) {
#if defined(WIN32) || defined(_WIN32)
	WSADATA WSAData;
	int ret;
	if (ret = WSAStartup(MAKEWORD(2, 2), &WSAData))
	{
		std::cout << "can't initilize winsock.dll" << std::endl;
		std::cout << "error code:" << WSAGetLastError() << std::endl;
		return 1;
	}
#endif

	//-t s -h 127.0.0.1 -p 8001
	//-t c -h 127.0.0.1 -p 8001
//	if (argc < 7) {
//		printf("please input s or c. \n");
//		return 0;
//	}

//	std::string type;
//	std::string host;
//	int port;
//
//	int ch = 0;
//	while ((ch = getopt(argc, argv, "t:h:p:")) != -1) {
//		switch (ch) {
//		case 't': {
//			type = optarg;
//		}
//			break;
//		case 'h': {
//			host = optarg;
//		}
//			break;
//		case 'p': {
//			port = atoi(optarg);
//		}
//			break;
//		default: {
//			fprintf(stderr, "Usage: thrift_demo "
//					"[--h=<h>] [--host] "
//					"[--p=<p>] [--port]\n");
//			exit(1);
//		}
//			break;
//		}
//	}

	if (argc < 2) {
		printf("client please input (-t s) or (-t c). \n");
		return 0;
	}

	std::string t;

	int ch = 0;
	while ((ch = getopt(argc, argv, "t:")) != -1) {
		switch (ch) {
		case 't': {
			if (optarg != NULL) {
				t = optarg;
			}
			break;
		}
		default: {
			fprintf(stderr, "(-t s) or (-t c)\n");
			exit(1);
			break;
		}
		}
	}

	ILog4zManager::getInstance()->start();

	//"47.91.140.210"

	if (t.compare("s") == 0) {
		thread_args targs = { "127.0.0.1", 8001 };
		std::thread t(thread_run_ipc_server, &targs);
		t.join();
	} else if (t.compare("c") == 0) {
		thread_args targs = { "127.0.0.1", 8001 };
		std::thread t(thread_run_ipc_client, &targs);
		t.join();
	} else {
		printf("error. \n");
	}

	while (1) {
#ifdef WIN32
		::Sleep(1000);
#else
		::sleep(1);
#endif
	}

#ifdef WIN32
	WSACleanup();
#endif

	return 0;
}

