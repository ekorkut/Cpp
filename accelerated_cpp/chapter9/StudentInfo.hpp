#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <iostream>
#include <string>
#include <vector>

class StudentInfo {
public:
  
  std::istream& read(std::istream&);
  double grade() const;
  std::string name() const;
  bool valid() const;
  
private:  
  std::string n;
  double midterm,final;
  std::vector<double> homeworks;
  
};

bool compare(const StudentInfo& s1, const StudentInfo& s2);

#endif
