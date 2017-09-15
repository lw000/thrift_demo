# server.thrift

namespace cpp LW

struct Student {
	1: i32 sno,
	2: string sname,
	3: bool ssex,
	4: i16 sage,
}

service Server {
	void login(1: string name, 2: string psd)
	void logout()
	i32 put(1: Student s)
	i32 send(1: i32 s, 2: i32 t, 3: string data)
	i32 add(1: i32 a, 2: i32 b);
	i32 sum(1: i32 v);
}