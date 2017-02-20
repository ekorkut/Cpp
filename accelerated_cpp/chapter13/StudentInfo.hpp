#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <iostream>
#include <string>
#include <vector>
#include "Core.hpp"

class StudentInfo {
public:
  // Constructor
  StudentInfo():cp(0) {
  }
  StudentInfo(std::istream& in):cp(0) { 
    read(in);
  }
  // Copy constructor
  StudentInfo(const StudentInfo&);
  // Assignment operator
  StudentInfo& operator=(const StudentInfo&);
  // Destructor
  ~StudentInfo() {
    delete cp;
  }


  std::istream& read(std::istream&);
  double grade() const;
  std::string name() const;

  static bool compare(const StudentInfo& s1, const StudentInfo& s2) {
    return s1.name() < s2.name();
  }
  
private:  
  Core* cp;  
};



#endif
