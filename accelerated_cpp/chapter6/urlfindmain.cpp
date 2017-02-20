#include <iostream>
#include <vector>
#include <string>
#include "urlfind.hpp"

using std::string;
using std::vector;

int main(){

  string input;
  vector<string> urls;
  std::cout << "Please enter the string to find URLs in:" << std::endl;
  while(getline(std::cin,input)) {  
    // Find urls
    urls = find_urls(input);
    // Display framed string
    for (vector<string>::const_iterator iter = urls.begin();iter != urls.end();iter++)
      std::cout << *iter << std::endl;            
  }


  return 0;
}
