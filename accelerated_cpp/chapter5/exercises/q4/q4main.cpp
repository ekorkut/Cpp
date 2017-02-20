#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "grade.hpp"
#include "StudentInfo.hpp"


using std::cout;
using std::cin;
using std::setprecision;
using std::vector;
using std::istream;
using std::string;
using std::list;



int main() {


  // Ask for name
  std::string name;
  cout << "Please enter the data: " << std::endl;

  StudentInfo s;
  studentcontainer students;
  while(readstudent(cin,s)) {
    students.push_back(s);
  }

  std::cout << "Read " << students.size() << " students!" << std::endl;
  //  students.sort(compare);


  // Find out the failed students
  studentcontainer fail_students;
  fail_students = extract_fails(students);
  
  // Print failed, passed and all students    
  cout << "FAILED STUDENTS " << std::endl;
  printgrades(fail_students,cout);
  
  cout << "PASSED STUDENTS " << std::endl;
  printgrades(students,cout);
    
  return 0;
}
