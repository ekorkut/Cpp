#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "split.hpp"


using std::string;
using std::map;
using std::vector;



map<string,vector<int> > crossref(std::istream& in, vector<string> find_words(const string&) = split) {
    map<string,vector<int> > table;
    string line;
    int linenumber = 0;
    while (getline(in,line)) {
      ++linenumber;
      vector<string> words = find_words(line);
      for (vector<string>::const_iterator iter = words.begin(); iter != words.end();iter++) {
	table[*iter].push_back(linenumber);	  
	} 
    }
    
    return table;


}

int main() {

  map<string,vector<int> > table = crossref(std::cin);
  // write results
  for(map<string,vector<int> >::const_iterator iter = table.begin(); iter != table.end();iter++) {
    std::cout << iter->first << " occurs in lines ";
    vector<int> numbers = iter->second;
    for(vector<int>::const_iterator numiter = numbers.begin(); numiter != numbers.end();numiter++) {
      std::cout << *numiter << " ";
    }
    std::cout << std::endl;
  }

  

  return 0;
}
