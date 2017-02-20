#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "grade.hpp"
#include "StudentInfo.hpp"
#include "analysis.hpp"


using std::cout;
using std::cin;
using std::setprecision;
using std::vector;
using std::istream;
using std::string;

typedef vector<StudentInfo>::const_iterator stu_const_iter;


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
  
  // Find students who did all homeworks and who did not
  vector<StudentInfo> did, didnot;
  for(stu_const_iter iter = students.begin();iter != students.end();iter++) {
    if (did_all_hw(*iter)) {
      did.push_back(*iter);
    }
    else {
      didnot.push_back(*iter);
    }
  }
  
  // Print who did and who did not
  cout << "Students who did are: " << std::endl;
  for(stu_const_iter iter = did.begin();iter != did.end();iter++) {
    cout << iter->name << std::endl;
  }

  cout << "Student who did NOT are:" << std::endl;
  for(stu_const_iter iter = didnot.begin();iter != didnot.end();iter++) {
    cout << iter->name << std::endl;
  }



  write_analysis(std::cout,"median",median_analysis,did, didnot);

  return 0;
}
