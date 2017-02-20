#include <iostream>
#include <string>
#include <vector>


using std::string;
using std::vector;
using std::cout;

typedef string::size_type strsize;

strsize width(const vector<string>& v) {
  strsize ret = 0;

  for(vector<string>::const_iterator iter = v.begin(); iter != v.end(); iter++) {
    strsize s = iter->size();
    if (s > ret) {
      ret = s;
    }
  }
  return ret;
}


vector<string> frame(const vector<string>& input) {

  vector<string> ret;

  strsize spacelen = 1;
  string space = string(spacelen,' ');

  strsize w = width(input);

  // Add upper border
  ret.push_back(string(w+2*spacelen+2,'*'));

  for (vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++) {
    strsize wthis = iter->size();
    string pad = string(w-wthis,' ');
    string thisline = "*" + space + *iter + pad + space + "*";
    ret.push_back(thisline);
  }

  // Add lower border
  ret.push_back(string(w+2*spacelen+2,'*'));

  return ret;
}

int main() {
  vector<string> test;
  test.push_back("line 1");
  test.push_back("line 2");
  test.push_back("bu da oyle bi line uzuncana");
  test.push_back("kisa");

  // Display input
  for (vector<string>::const_iterator iter = test.begin(); iter != test.end(); iter++) {
    cout << *iter << std::endl;
  }


  vector<string> framed = frame(test);

  // Display output
  for (vector<string>::const_iterator iter = framed.begin(); iter != framed.end(); iter++) {
    cout << *iter << std::endl;
  }

  
  return 0;
}
