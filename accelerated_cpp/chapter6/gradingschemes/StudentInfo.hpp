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
double grade_aux(const StudentInfo& s);
bool compare (const StudentInfo&, const StudentInfo&);
bool did_all_hw(const StudentInfo&);


#endif
