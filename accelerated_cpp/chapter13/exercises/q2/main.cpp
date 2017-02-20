#include <iostream>
#include "Core.hpp"
#include "Grad.hpp"

int main() {
  Core* p1 = new Core;
  Core* p2 = new Grad;
  
  Core s1;
  Grad s2;
  std::cout << " Now begins the output" << std::endl;

  p1->grade(); // Should call Core::grade
  p1->name(); // Should call Core::name

  p2->grade(); // Should call Grad::grade, then Core::grade
  p2->name(); // Should call Core::name


  s1.grade(); // Should call Core::grade
  s1.name(); // Should call Core::name


  s2.grade(); // Should call Grad::grade, then Core::grade
  s2.name(); // Should call Core::name

}
