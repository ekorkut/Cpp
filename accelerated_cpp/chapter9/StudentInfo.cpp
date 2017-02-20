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

istream& StudentInfo::read(istream& in) {
  in >> n >> midterm >> final;
  readhomework(in,homeworks);
  return in;
}

double StudentInfo::grade() const {
  return ::grade(final,midterm,homeworks);
}

std::string StudentInfo::name() const {
  return n;
}

bool StudentInfo::valid() const {
  return !homeworks.empty();
}


bool compare(const StudentInfo& s1, const StudentInfo& s2) {
  return s1.name() < s2.name();
}





