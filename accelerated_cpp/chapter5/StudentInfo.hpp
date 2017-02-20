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


std::istream& readstudent(std::istream&, StudentInfo&);
double grade(const StudentInfo&);
bool compare (const StudentInfo&, const StudentInfo&);
bool fgrade(const StudentInfo&);
std::list<StudentInfo> extract_fails(std::list<StudentInfo>&);
void printgrades(const std::list<StudentInfo>&, std::ostream&);

#endif
