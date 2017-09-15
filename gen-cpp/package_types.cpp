/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "package_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace LW {


LWException::~LWException() throw() {
}


void LWException::__set_errorCode(const int32_t val) {
  this->errorCode = val;
}

void LWException::__set_message(const std::string& val) {
  this->message = val;
}

uint32_t LWException::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->errorCode);
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t LWException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("LWException");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->errorCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->message);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(LWException &a, LWException &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.message, b.message);
  swap(a.__isset, b.__isset);
}

LWException::LWException(const LWException& other0) : TException() {
  errorCode = other0.errorCode;
  message = other0.message;
  __isset = other0.__isset;
}
LWException& LWException::operator=(const LWException& other1) {
  errorCode = other1.errorCode;
  message = other1.message;
  __isset = other1.__isset;
  return *this;
}
void LWException::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "LWException(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "message=" << to_string(message);
  out << ")";
}

const char* LWException::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: LWException";
  }
}


MsgConnected::~MsgConnected() throw() {
}


void MsgConnected::__set_cmd(const int32_t val) {
  this->cmd = val;
}

uint32_t MsgConnected::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->cmd);
          this->__isset.cmd = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MsgConnected::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MsgConnected");

  xfer += oprot->writeFieldBegin("cmd", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->cmd);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MsgConnected &a, MsgConnected &b) {
  using ::std::swap;
  swap(a.cmd, b.cmd);
  swap(a.__isset, b.__isset);
}

MsgConnected::MsgConnected(const MsgConnected& other2) {
  cmd = other2.cmd;
  __isset = other2.__isset;
}
MsgConnected& MsgConnected::operator=(const MsgConnected& other3) {
  cmd = other3.cmd;
  __isset = other3.__isset;
  return *this;
}
void MsgConnected::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MsgConnected(";
  out << "cmd=" << to_string(cmd);
  out << ")";
}


MsgChat::~MsgChat() throw() {
}


void MsgChat::__set_v(const int32_t val) {
  this->v = val;
}

void MsgChat::__set_mid(const int32_t val) {
  this->mid = val;
}

void MsgChat::__set_sid(const int32_t val) {
  this->sid = val;
}

void MsgChat::__set_cmd(const int32_t val) {
  this->cmd = val;
}

uint32_t MsgChat::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->v);
          this->__isset.v = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->mid);
          this->__isset.mid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->sid);
          this->__isset.sid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->cmd);
          this->__isset.cmd = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MsgChat::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MsgChat");

  xfer += oprot->writeFieldBegin("v", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->v);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mid", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->mid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sid", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->sid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("cmd", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->cmd);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MsgChat &a, MsgChat &b) {
  using ::std::swap;
  swap(a.v, b.v);
  swap(a.mid, b.mid);
  swap(a.sid, b.sid);
  swap(a.cmd, b.cmd);
  swap(a.__isset, b.__isset);
}

MsgChat::MsgChat(const MsgChat& other4) {
  v = other4.v;
  mid = other4.mid;
  sid = other4.sid;
  cmd = other4.cmd;
  __isset = other4.__isset;
}
MsgChat& MsgChat::operator=(const MsgChat& other5) {
  v = other5.v;
  mid = other5.mid;
  sid = other5.sid;
  cmd = other5.cmd;
  __isset = other5.__isset;
  return *this;
}
void MsgChat::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MsgChat(";
  out << "v=" << to_string(v);
  out << ", " << "mid=" << to_string(mid);
  out << ", " << "sid=" << to_string(sid);
  out << ", " << "cmd=" << to_string(cmd);
  out << ")";
}

} // namespace