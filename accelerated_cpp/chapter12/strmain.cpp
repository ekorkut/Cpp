#include <iostream>
#include "Str.hpp"



int main() {
  Str in;
  std::cout << "******* Input operator test *******" << std::endl;
  std::cout << "Enter a string:" << std::endl;
  std::cin >> in;
  std::cout << "You entered " << in << std::endl;
  

  std::cout << "****** Constructor test *******" << std::endl;
  Str s("hello, world");
  std::cout << s << std::endl;

  std::cout << "****** += test *******" << std::endl;
  Str s1("hello, ");
  s1 += "Erman!";  
  std::cout << s1 << std::endl;

  std::cout << "*******+ test *******" << std::endl;
  Str s2 = s + s1 + in;
  std::cout << s2 << std::endl;

  std::cout << "*******double conversion test *******" << std::endl;
  double x = 5;
  double y;
  y = x + in;
  std::cout << y << std::endl;

  return 0;
}
