#include <string>
#include <iostream>
#include <map>

using std::string;
using std::map;



int main() {
  string s;

  map<string,int> counters;

  while (std::cin >> s)
    ++counters[s];

  // Write them

  for(map<string,int>::const_iterator iter = counters.begin(); iter != counters.end();iter++) {
    std::cout << iter->first << ": " << iter->second << std::endl; 
  }

  return 0;
}
