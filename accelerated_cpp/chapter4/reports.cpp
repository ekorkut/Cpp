#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::setprecision;
using std::vector;
using std::istream;
using std::string;

double grade(double final, double midterm, double homework) {
  return (0.2*midterm + 0.4*final + 0.4*homework);
}

double median(vector<double> hw) {
  vector<double>::size_type size = hw.size();
  
  if (size == 0) {
    cout << "You must enter at least one grade"
      " try again" << std::endl;
    return 1;
  }

  sort(hw.begin(), hw.end());

  double median;
  double mid = size/2;

  if (size % 2 == 0) {
    median = (hw[mid-1] + hw[mid])/2;
  }
  else {
    median = hw[mid];
  }
  return median;
}


double grade(double final, double midterm, const vector<double>& hmw) {
  if (hmw.size() == 0) {
    throw std::domain_error("Student has done no homework");
  }
  return grade(final,midterm,median(hmw));
}

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

struct StudentInfo {
  string name;
  double midterm,final;
  vector<double> homeworks;
};

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


int main() {
  // Ask for name
  std::string name;
  cout << "Please enter the data: " << std::endl;

  StudentInfo s;
  vector<StudentInfo> students;
  while(readstudent(cin,s)) {
    students.push_back(s);
  }

  std::cout << "Read " << students.size() << " students!" << std::endl;
  sort(students.begin(),students.end(),compare);

  for(vector<StudentInfo>::size_type ct = 0; ct != students.size();ct++) {
    try {
      double final_grade = grade(students[ct]);
      cout << students[ct].name << ": " << final_grade << std::endl;
    }
    catch (std::domain_error e) {
      cout << students[ct].name << e.what();
      cout << std::endl;
    }
  }

  return 0;
}
