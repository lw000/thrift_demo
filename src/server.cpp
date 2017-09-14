// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <src/server.h>
#include "gen-cpp/LWServer.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/PosixThreadFactory.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace ::LW;

class LWServerHandler: virtual public LWServerIf {
public:
	LWServerHandler() {
		// Your initialization goes here
	}

	virtual int32_t put(const Student& s) {
//		printf("%5d, %15d, %3d, %s \n", s.sage, s.sno, s.ssex, s.sname.c_str());
		int c = 0;
		for (int i = 0; i < 1000; i++) {
			c += i;
		}

		return 0;
	}

	virtual void login(const std::string& name, const std::string& psd) {

	}

	virtual void logout() {

	}

	virtual int32_t send(const int32_t s, const int32_t t,
			const std::string& data) {
		return 0;
	}

	virtual int32_t add(const int32_t a, const int32_t b) {
		return 0;
	}

	virtual int32_t sum(const int32_t v) {
		int c = 0;
		for (int i = 0; i < v; i++) {
			c += i;
		}
		return c;
	}
};

int run_ipc_server_1(int port) {
	shared_ptr<LWServerHandler> handler(new LWServerHandler());
	shared_ptr<TProcessor> processor(new LWServerProcessor(handler));
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
	shared_ptr<TTransportFactory> transportFactory(
			new TBufferedTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	TSimpleServer server(processor, serverTransport, transportFactory,
			protocolFactory);

	server.serve();

	return 0;
}

int run_ipc_server(int port) {
	shared_ptr<LWServerHandler> handler(new LWServerHandler());
	shared_ptr<TProcessor> processor(new LWServerProcessor(handler));
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
	shared_ptr<TTransportFactory> transportFactory(
			new TBufferedTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	TSimpleServer server(processor, serverTransport, transportFactory,
			protocolFactory);

	shared_ptr<ThreadManager> threadManager =
			ThreadManager::newSimpleThreadManager(15);
	shared_ptr<PosixThreadFactory> threadFactory =
			shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
	threadManager->threadFactory(threadFactory);

	threadManager->start();

	server.serve();

	return 0;
}

