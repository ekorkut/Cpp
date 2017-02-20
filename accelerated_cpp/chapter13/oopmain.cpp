#include <stdexcept>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Core.hpp"
#include "Grad.hpp"
#include "StudentInfo.hpp"

using std::vector;
using std::ifstream;

int main() {
  /*
  std::cout << "Instantiate Core and Grad" << std::endl;

  Core c;
  Grad g;

  std::cout << "Check their grades" << std::endl;
  try {
    std::cout << "grade(core) = " << c.grade() << std::endl;
  }
  catch (std::domain_error& e) {
    std::cout << "Threw domain error" << std::endl;
  }

  try {
    std::cout << "grade(grad) = " << g.grade() << std::endl;
  }
  catch (std::domain_error& e) {
    std::cout << "Threw domain error" << std::endl;
  }


  std::cout << "Read a core:" << std::endl;
  Core c1(std::cin);
  std::cout << "Read a grad:" << std::endl;
  Grad g1(std::cin);

  std::cout << "Compare them:" << std::endl;
  std::cout << "c1 < g1 = " << compare(c1,g1);
  */
 
  /*
  // Read core and grad from files
  std::cout << "Reading individual files" << std::endl;
  vector<Core> cstudents;
  Core crecord;  
  ifstream cfile("core.txt");
  while (crecord.read(cfile)) {
    cstudents.push_back(crecord);
  }
  sort(cstudents.begin(), cstudents.end(), compare);
  std::cout << "Core students" << std::endl;
  for (vector<Core>::size_type i = 0;i != cstudents.size();i++) {
    std::cout << cstudents[i].name() << " " << cstudents[i].grade() << std::endl;
  }

  vector<Grad> gstudents;
  Grad grecord;  
  ifstream gfile("grad.txt");
  while (grecord.read(gfile)) {
    gstudents.push_back(grecord);
  }
  sort(gstudents.begin(), gstudents.end(), compare);
  std::cout << "Grad students" << std::endl;
  for (vector<Grad>::size_type i = 0;i != gstudents.size();i++) {
    std::cout << gstudents[i].name() << " " << gstudents[i].grade() << std::endl;
  }
  */
  /*
  std::cout << "Reading from mixed files" << std::endl;
  vector<Core*> students;
  Core* record;
  ifstream mixedfile("combined.txt");
  char ch;
  while (mixedfile >> ch) {
    if (ch == 'C')
      record = new Core;
    else
      record = new Grad;
    record->read(mixedfile);
    students.push_back(record);
  }
  sort(students.begin(),students.end(),compare_Coreptr);
  
  std::cout << "All students" << std::endl;
  for (vector<Core*>::size_type i = 0;i != students.size();i++) {
    std::cout << students[i]->name() << " " << students[i]->grade() << std::endl;
    delete students[i];
  }

  */

  std::cout << "Reading from mixed using handle class StudentInfo" << std::endl;
  vector<StudentInfo> students;
  StudentInfo record;
  ifstream mixedfile("combined.txt");


  while(record.read(mixedfile)) {
    students.push_back(record);
  }
  sort(students.begin(),students.end(),StudentInfo::compare);

  std::cout << "All students" << std::endl;
  for (vector<StudentInfo>::size_type i = 0;i != students.size();i++) {
    std::cout << students[i].name() << " " << students[i].grade() << std::endl;
  }
  


  

  
  

  return 0;
}
