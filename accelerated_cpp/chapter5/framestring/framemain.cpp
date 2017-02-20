#include <iostream>
#include <string>
#include <vector>
#include "frame.hpp"
#include "../splitstring/split.hpp"


using std::vector;
using std::string;

int main() {

  string input;
  std::cout << "Please enter the string to frame after splitting:" << std::endl;
  while(getline(std::cin,input)) {  
    // Read and split input
    vector<string> result = split(input);
    // Frame it
    vector<string> framed = frame(result);
    // Display framed string
    for (vector<string>::const_iterator iter = framed.begin();iter != framed.end();iter++)
      std::cout << *iter << std::endl;            
  }
  
  

  return 0;
}
