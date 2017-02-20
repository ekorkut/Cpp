#include <iostream>
#include <vector>
#include <string>
#include "split.hpp"

using std::string;
using std::vector;


int main() {

  string input;
  std::cout << "Please enter the string to split:" << std::endl;
  while(getline(std::cin,input)) {  
    vector<string> result = split(input);
    std::cout << "Split is done. Splitted strings are:" << std::endl;
    
    for (vector<string>::const_iterator iter = result.begin();iter != result.end();iter++)
      std::cout << *iter << std::endl;        
  }
  
  return 0;
}
