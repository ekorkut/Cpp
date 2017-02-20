#include <iostream>
#include "Core.hpp"
#include "Grad.hpp"

using std::cout;

int main() {
  // Read a core
  cout << "Reading a core" << std::endl;
  Core c(std::cin);


  // Read a grad
  cout << "Reading a grad" << std::endl;
  Grad g(std::cin);
  
  return 0;
}
