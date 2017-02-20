#include <fstream>
#include <vector>
#include <algorithm>
#include "Ptr.hpp"
#include "Core.hpp"
#include "Grad.hpp"



int main() {
  std::vector<Ptr<Core> > students;
  
  Ptr<Core> record;
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
  
  sort(students.begin(),students.end(),Ptr<Core>::comparePtr);

   std::cout << "All students" << std::endl;
   for (std::vector<Ptr<Core> >::size_type i = 0;i != students.size();i++) {
     std::cout << students[i]->name() << " " << students[i]->grade() << std::endl;
   }
   
   return 0;
}
