#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo {
  std::string name;
  double midterm,final;
  std::vector<double> homeworks;
};


std::istream& readstudent(std::istream&, StudentInfo&);
double grade(const StudentInfo&);
bool compare (const StudentInfo&, const StudentInfo&);

#endif
