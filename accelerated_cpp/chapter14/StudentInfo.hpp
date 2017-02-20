#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <iostream>
#include <string>
#include <vector>
#include "Core.hpp"
#include "Handle.hpp"

class StudentInfo {
public:
  // Constructor
  StudentInfo() {
  }
  StudentInfo(std::istream& in) { 
    read(in);
  }

  std::istream& read(std::istream&);
  double grade() const;
  std::string name() const;

  static bool compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
  }
  
private:  
  Handle<Core> cp;  
};



#endif
