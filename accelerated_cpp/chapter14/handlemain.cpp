#include <fstream>
#include <vector>
#include <algorithm>
#include "Handle.hpp"
#include "Core.hpp"
#include "Grad.hpp"



int main() {
  std::vector<Handle<Core> > students;
  
  Handle<Core> record;
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
  
  sort(students.begin(),students.end(),Handle<Core>::compareHandle);

   std::cout << "All students" << std::endl;
   for (std::vector<Handle<Core> >::size_type i = 0;i != students.size();i++) {
     std::cout << students[i]->name() << " " << students[i]->grade() << std::endl;
   }
   
   return 0;
}
