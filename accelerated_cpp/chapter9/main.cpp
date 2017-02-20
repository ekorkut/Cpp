#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "grade.hpp"
#include "StudentInfo.hpp"


using std::cout;
using std::cin;
using std::setprecision;
using std::vector;
using std::istream;
using std::string;


int main() {
  // Ask for name
  std::string name;
  cout << "Please enter the data: " << std::endl;

  StudentInfo s;
  vector<StudentInfo> students;
  while(s.read(cin)) {
    students.push_back(s);
  }

  std::cout << "Read " << students.size() << " students!" << std::endl;
  sort(students.begin(),students.end(),compare);

  for(vector<StudentInfo>::size_type ct = 0; ct != students.size();ct++) {
    try {
      double final_grade = students[ct].grade();
      cout << students[ct].name() << ": " << final_grade << std::endl;
    }
    catch (std::domain_error e) {
      cout << students[ct].name() << e.what();
      cout << std::endl;
    }
  }

  return 0;
}
