#include <iostream>
#include <vector>
#include "StudentInfo.hpp"
#include "grade.hpp"

using std::istream;
using std::vector;


istream& readhomework(istream& in, vector<double>& hmw) {
  if (in) {
    hmw.clear();
    double x;
    while(in >> x) {
      hmw.push_back(x);
    }
    in.clear();
  }
  return in;
}

istream& readstudent(istream& in, StudentInfo& s) {
  in >> s.name >> s.midterm >> s.final;
  readhomework(in,s.homeworks);
  return in;
}

double grade(const StudentInfo& s) {
  return grade(s.final,s.midterm,s.homeworks);
}

bool compare(const StudentInfo& s1,const StudentInfo& s2) {
  return s1.name < s2.name;
}


