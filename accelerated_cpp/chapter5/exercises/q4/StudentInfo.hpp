#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <iostream>
#include <string>
#include <vector>
#include <list>

struct StudentInfo {
  std::string name;
  double midterm,final;
  std::vector<double> homeworks;
};

typedef std::vector<StudentInfo> studentcontainer;

std::istream& readstudent(std::istream&, StudentInfo&);
double grade(const StudentInfo&);
bool compare (const StudentInfo&, const StudentInfo&);
bool fgrade(const StudentInfo&);
studentcontainer extract_fails(studentcontainer&);
void printgrades(const studentcontainer&, std::ostream&);

#endif
