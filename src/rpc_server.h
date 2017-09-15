#ifndef __ipc_server_h__
#define __ipc_server_h__

int run_ipc_server_simple(const char* host, int port=8001);
int run_ipc_thread_server(const char* host, int port=8001);
int run_ipc_threadpool_server(const char* host, int port=8001);
int run_ipc_nonblocking_server(const char* host, int port=8001);

#endif // !__ipc_server_h__
