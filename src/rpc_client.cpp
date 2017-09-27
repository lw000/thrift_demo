// ipc_client.cpp :
//

#include <gen-cpp/Server.h>
#include <src/rpc_client.h>
#include <thrift/transport/TSocket.h>  
#include <thrift/transport/TBufferTransports.h>  
#include <thrift/protocol/TBinaryProtocol.h>  

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

#include "log4z.h"
using namespace zsummer::log4z;

IPCClient::IPCClient(char* host, int prot) {
	boost::shared_ptr<TSocket> socket(new TSocket(host, prot));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
}

IPCClient::~IPCClient() {
}

IPCRequest::IPCRequest() {
}

IPCRequest::~IPCRequest() {
}

void IPCRequest::send() {

}

int run_ipc_client(const char* host, int prot) {
	boost::shared_ptr<TSocket> socket(new TSocket(host, prot));
	//boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	LW::ServerClient client(protocol);

	try {
		transport->open();

		{
			LW::Student s;
			s.sno = rand() % 10000000 + 1;
			s.sname = "xiaoshe";
			s.ssex = 1;
			s.sage = rand() % 120 + 1;
			client.put(s);
		}

		{
			clock_t t = clock();
			for (int i = 0; i < 10000; i++) {
				clock_t t = clock();
				int c = client.sum(1000);
				clock_t t1 = clock();
				LOGFMTA("exec [%d] [%d], times: %f", i, c, ((double) t1 - t) / CLOCKS_PER_SEC);
			}
			clock_t t1 = clock();
			LOGFMTA("all exec times: %f", ((double) t1 - t) / CLOCKS_PER_SEC);
		}

		transport->close();

	} catch (TException &e) {
		printf("ERROR: %s\n", e.what());
	}

	return 0;
}
