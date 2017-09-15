# package.thrift

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


