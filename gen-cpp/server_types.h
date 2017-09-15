/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef server_TYPES_H
#define server_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace LW {

class Student;

typedef struct _Student__isset {
  _Student__isset() : sno(false), sname(false), ssex(false), sage(false) {}
  bool sno :1;
  bool sname :1;
  bool ssex :1;
  bool sage :1;
} _Student__isset;

class Student {
 public:

  Student(const Student&);
  Student& operator=(const Student&);
  Student() : sno(0), sname(), ssex(0), sage(0) {
  }

  virtual ~Student() throw();
  int32_t sno;
  std::string sname;
  bool ssex;
  int16_t sage;

  _Student__isset __isset;

  void __set_sno(const int32_t val);

  void __set_sname(const std::string& val);

  void __set_ssex(const bool val);

  void __set_sage(const int16_t val);

  bool operator == (const Student & rhs) const
  {
    if (!(sno == rhs.sno))
      return false;
    if (!(sname == rhs.sname))
      return false;
    if (!(ssex == rhs.ssex))
      return false;
    if (!(sage == rhs.sage))
      return false;
    return true;
  }
  bool operator != (const Student &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Student & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Student &a, Student &b);

inline std::ostream& operator<<(std::ostream& out, const Student& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif
