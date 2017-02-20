#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include "StudentInfo_vector.hpp"
#include "grade.hpp"

using std::istream;
using std::vector;
using std::list;

typedef std::vector<StudentInfo> studentcontainer;

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

bool fgrade(const StudentInfo& s1) {
  return grade(s1) < 60;
}

studentcontainer extract_fails(studentcontainer&students) {
  studentcontainer fail;
  studentcontainer::size_type ct = 0;
  studentcontainer::iterator iter = students.begin();
  while(iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    }
    else {
      iter++;
    }
  }
  return fail;
}

void printgrades(const studentcontainer&students, std::ostream& out) {  
  for(studentcontainer::const_iterator iter = students.begin(); iter != students.end();iter++) {
    try {
      double final_grade = grade(*iter);
      out << iter->name << ": " << final_grade << std::endl;
    }
    catch (std::domain_error e) {
      out << iter->name << e.what();
      out << std::endl;
    }
  }

}


