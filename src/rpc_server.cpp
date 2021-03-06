// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <CommonServer/StudentServerHandlerHandler.h>
#include <src/rpc_server.h>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
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

int run_ipc_server_simple(const char* host, int port) {
	shared_ptr<StudentServerHandler> handler(new StudentServerHandler());
	shared_ptr<TProcessor> processor(new ServerProcessor(handler));
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(host, port));
	shared_ptr<TTransportFactory> transportFactory(
			new TBufferedTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	TSimpleServer svr(processor, serverTransport, transportFactory,
			protocolFactory);

	svr.serve();

	return 0;
}

int run_ipc_thread_server(const char* host, int port) {
	shared_ptr<StudentServerHandler> handler(new StudentServerHandler());
	shared_ptr<TProcessor> processor(new ServerProcessor(handler));
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(host, port));
	shared_ptr<TTransportFactory> transportFactory(
			new TBufferedTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	shared_ptr<ThreadManager> threadManager =
			ThreadManager::newSimpleThreadManager(4);

	shared_ptr<PlatformThreadFactory> threadFactory =
		shared_ptr<PlatformThreadFactory>(new PlatformThreadFactory());

	threadManager->threadFactory(threadFactory);

	threadManager->start();

	TThreadedServer svr(processor, serverTransport, transportFactory,
			protocolFactory);

	svr.serve();

	return 0;
}

int run_ipc_threadpool_server(const char* host, int port) {
	shared_ptr<StudentServerHandler> handler(new StudentServerHandler());
	shared_ptr<TProcessor> processor(new ServerProcessor(handler));
	shared_ptr<TServerTransport> serverTransport(new TServerSocket(host, port));
	shared_ptr<TTransportFactory> transportFactory(
			new TBufferedTransportFactory());
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	shared_ptr<ThreadManager> threadManager =
			ThreadManager::newSimpleThreadManager(6);

	shared_ptr<PlatformThreadFactory> threadFactory =
		shared_ptr<PlatformThreadFactory>(new PlatformThreadFactory());

	threadManager->threadFactory(threadFactory);

	threadManager->start();

	TThreadPoolServer svr(processor, serverTransport, transportFactory,
			protocolFactory, threadManager);

	svr.serve();

	return 0;
}

int run_ipc_nonblocking_server(const char* host, int port) {
	shared_ptr<StudentServerHandler> handler(new StudentServerHandler());
	shared_ptr<TProcessor> processor(new ServerProcessor(handler));
	shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

	shared_ptr<ThreadManager> threadManager =
			ThreadManager::newSimpleThreadManager(6);

	shared_ptr<PlatformThreadFactory> threadFactory =
			shared_ptr<PlatformThreadFactory>(new PlatformThreadFactory());

	threadManager->threadFactory(threadFactory);

	threadManager->start();

	TNonblockingServer svr(processor, protocolFactory, port, threadManager);

	svr.serve();

	return 0;
}

