#include <string>
#include <vector>
#include <cctype>
#include <algorithm>


using std::string;
using std::vector;

typedef string::const_iterator iter;


bool notspace(char c) {
  return !isspace(c);
}

bool space(char c) {
  return isspace(c);
}

vector<string> split(const string& s) {
  vector<string> ret;

  iter i = s.begin();

  while (i != s.end()) {
    i = find_if(i,s.end(),notspace);
    iter j = find_if(i,s.end(),space);
    if (i != s.end()){
      ret.push_back(string(i,j));
    }
    i = j;
  }
  
  return ret;
}
