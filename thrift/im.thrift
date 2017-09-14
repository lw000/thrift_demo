# im.thrift

namespace cpp LW

exception LWException {
  	1: i32 errorCode,
  	2: string message
}

struct MsgConnected {
	1: i32 cmd,
}

struct MsgChat {
  	1: i32 v,
  	2: i32 mid,
  	3: i32 sid,
  	4: i32 cmd
}

struct Student {
	1: i32 sno,
	2: string sname,
	3: bool ssex,
	4: i16 sage,
}

service LWServer {
	void login(1: string name, 2: string psd)
	void logout()
	i32 put(1: Student s)
	i32 send(1: i32 s, 2: i32 t, 3: string data)
	i32 add(1: i32 a, 2: i32 b);
	i32 sum(1: i32 v);
}
