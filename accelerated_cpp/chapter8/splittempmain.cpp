#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <list>
#include <iterator>


using std::string;
using std::list;
using std::vector;


bool space(const char c) {
  return isspace(c);
}

bool notspace(const char c) {
  return !isspace(c);
}


template <class Out>
void printcontainer(std::ostream& o, Out c) {
  typedef typename Out::const_iterator iter;

  iter i = c.begin();

  while (i != c.end()) {
    o << *i << std::endl;
    i++;
  }
}

template <class Out>
void split(const string&s, Out o) {
  string::const_iterator iter = s.begin();

  while (iter != s.end()) {
    iter = find_if(iter,s.end(),notspace);

    string::const_iterator j = find_if(iter,s.end(),space);

    if (iter != s.end()) {
      *o++ = string(iter,j);
    }

    iter = j;
    
  }
}


int main() {
  

  std::cout << "Enter the sentence to split into words" << std::endl;

  string sentence;
  list<string> outlist;

  vector<string> outvec;

  while (getline(std::cin,sentence)) {
    
    split(sentence,back_inserter(outvec));
  }

  // Print the results
  printcontainer(std::cout,outvec);
  
  return 0;
}
