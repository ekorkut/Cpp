#include <fstream>
#include <vector>
#include <algorithm>
#include "RefHandle.hpp"
#include "Core.hpp"
#include "Grad.hpp"



int main() { 

 std::vector<RefHandle<Core> > students;
  
  RefHandle<Core> record;
  char ch;
  
  std::ifstream mixedfile("combined.txt");
  
  while (mixedfile >> ch) {
    if (ch == 'U')
      record = new Core;
    else
      record = new Grad;
    
    record->read(mixedfile);
    students.push_back(record);
  }
  
  sort(students.begin(),students.end(),RefHandle<Core>::compareRefHandle);

   std::cout << "All students" << std::endl;
   for (std::vector<RefHandle<Core> >::size_type i = 0;i != students.size();i++) {
     std::cout << students[i]->name() << " " << students[i]->grade() << std::endl;
   }
   
   return 0;









  /*
  RefHandle<Core> record(new Core);


  //Read a core student
  std::cout << "Enter data for a core student:"<< std::endl;
  record->read(std::cin);


  std::cout << "We read data for " << record->name() << ", his grade is " << record->grade() << "." << std::endl;
  record.printNumInstances();

  RefHandle<Core> newrecord = record;
  std::cout << "Access through a new handle: " << newrecord->name() << ", his grade is " << newrecord->grade() << "." << std::endl;
  newrecord.printNumInstances();
  
  std::cout << "Main returning, memory should be freed" << std::endl;
  return 0;

  */

}
