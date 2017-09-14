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

#include <src/client.h>
#include <src/server.h>

#include <log4z/log4z.h>
using namespace zsummer::log4z;

static void thread_run_ipc_client(int port) {
	//run_ipc_client("localhost", port);
	run_ipc_client("47.91.140.210", port);
}

static void thread_run_ipc_server(int port) {
	run_ipc_server(port);
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

	if (argc < 2) {
		printf("please input s or c. \n");
		return 0;
	}

	ILog4zManager::getInstance()->start();

	std::string s(argv[1]);

	if (s.compare("s") == 0) {
		std::thread t(thread_run_ipc_server, 8001);
		t.join();
	} else if (s.compare("c") == 0) {
		std::thread t(thread_run_ipc_client, 8001);
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

