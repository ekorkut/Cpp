#include <iostream>
#include <vector>
#include "StudentInfo.hpp"
#include "grade.hpp"

using std::istream;
using std::vector;
using std::string;

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

StudentInfo::StudentInfo() : midterm(0),final(0) {
  sgrade = 0;
}

istream& StudentInfo::read(istream& in) {
  in >> n >> midterm >> final;
  readhomework(in,homeworks);
  sgrade = ::grade(final,midterm,homeworks);
  return in;
}

double StudentInfo::grade() const {
  return sgrade;
}

string StudentInfo::lettergrade() const {
  double g = grade();

  static const double numbers[] = {
    97,94,90,87,84,80,77,74,70,60,0
  };
  static const char* letters[] = {
    "A+","A","A-","B+","B","B-","C+","C","C-","D","F"
  };


  static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

  for (int ct = 0; ct < ngrades; ct++) {
    if (g > numbers[ct])
      return letters[ct];
  }
  return "WTF?";
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





