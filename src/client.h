#ifndef __ipc_client_h__
#define __ipc_client_h__

int run_ipc_client(char* host, int prot);

class IPCClient
{
public:
	IPCClient(char* host, int prot);
	~IPCClient();

private:

};

class IPCRequest
{
public:
	IPCRequest();
	~IPCRequest();

public:
	void send();

private:

};

#endif // !__ipc_client_h__
