#include <iostream>
#include "Str.hpp"


using std::cin;
using std::cout;


int main() {

  Str s1;
  cout << "Size of default constructor: " << s1.size() << std::endl;
  Str s2 = "cengiz";
  cout << "Output of initialization with string literal: " << s2 << std::endl;

  Str s3(10,'*');
  cout << "Output of initialization with * character: " << s3 << std::endl;

  cout << "Output of index operator (0th and 2th chars of cengiz): " << s2[0] << s2[2] << std::endl;

  cout << "Print through iterator: ";
  for (Str::const_iterator iter = s2.begin(); iter != s2.end(); iter++)
    cout << *iter;
  cout << std::endl;

  Str s4 = s3;
  cout << "Copy constructor: " << s4 << std::endl;
  
  //Assigment
  s4 = s2;
  cout << "Assignment:" << s4 << std::endl;

  
  
  return 0;
}
