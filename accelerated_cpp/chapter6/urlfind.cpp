#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using std::vector;
using std::string;

typedef string::const_iterator string_iter;

bool not_url_char(char c) {
  static const string url_ch = "~;/?:@&$-_.+!*'(),";
  return !(isalnum(c) || 
	   (find(url_ch.begin(),url_ch.end(),c) != url_ch.end()));
}

string_iter url_end(string_iter b, string_iter e) {
  return find_if(b,e,not_url_char);
}

string_iter url_beg(string_iter b, string_iter e) {
  static const string sep = "://";
  string_iter i = b;
  while ((i = search(b,e,sep.begin(),sep.end()))!= e) {
    if ((i != b) && (i+sep.size() != e)) {
      string_iter beg = i;
      // Look back
      while ((beg != b) && isalpha(beg[-1])) {
	--beg;	
      }
      // You found if there is one url char after sep
      if ((beg != i) && !not_url_char(i[sep.size()])) {
	return beg;
      }       
    }
    i += sep.size();    
  }
  return e;    
}





vector<string> find_urls(const string& s) {
  
  vector<string> ret;
  
  string_iter b = s.begin();
  string_iter e = s.end();
  
  while (b != e) {
    b = url_beg(b,e);
    if (b != e) {
      string_iter after = url_end(b,e);
      ret.push_back(string(b,after));
      b = after;
    }       
  }
  return ret; 
}





