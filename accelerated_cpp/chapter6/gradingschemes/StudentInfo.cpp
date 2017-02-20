#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
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

double grade_aux(const StudentInfo& s) {
  try {
    return grade(s);
  }
  catch(std::domain_error) {
    return grade(s.final,s.midterm, 0.0);
  }
}





bool compare(const StudentInfo& s1,const StudentInfo& s2) {
  return s1.name < s2.name;
}

bool did_all_hw(const StudentInfo& s) {
  return ((find(s.homeworks.begin(),s.homeworks.end(),0.0)) ==
    s.homeworks.end());
}


