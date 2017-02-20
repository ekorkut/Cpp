#include <vector>
#include <string>


using std::vector;
using std::string;

vector<string> frame(const vector<string>&s) {
  
  vector<string> ret;

  // Find the longest string length
  typedef string::size_type string_size;  
  string_size maxlen = 0;
  for(vector<string>::const_iterator iter = s.begin(); iter != s.end(); iter++) {
    string_size ss = (*iter).size();
    if (ss > maxlen ) {
      maxlen = ss;
    }
  }

  // First line - border
  string border = string(maxlen+4,'*'); 
  ret.push_back(border);
  for(vector<string>::const_iterator iter = s.begin(); iter != s.end();iter++) {
    string_size padsize = maxlen - (*iter).size();
    string thisone = "* " + (*iter) + string(padsize,' ') + " *";
    ret.push_back(thisone);
  }
  ret.push_back(border);
  return ret;

}
