#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;

typedef string::size_type strsize;


strsize width(const vector<string>& input) {
  strsize ret = 0;

  for (vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++) {
    strsize wthis = iter->size();
    if (wthis > ret) {
      ret = wthis;
    }
  }

  return ret;

} 

vector<string> hcat(const vector<string>& left, const vector<string>& right) {

  vector<string> ret;

  // Find the bigger one
  vector<string>::const_iterator leftiter = left.begin();
  vector<string>::const_iterator rightiter = right.begin();


  strsize wleft = width(left);

  while ((leftiter != left.end()) && (rightiter != right.end())) {
    string pad = string(wleft -  leftiter->size(),' ');
    ret.push_back(*leftiter + pad + " " + *rightiter);
    leftiter++;
    rightiter++;
  }
  // Add empty if right is longer
  if (leftiter == left.end()) {
    for (; rightiter != right.end(); rightiter++) {
      ret.push_back(string(wleft+1,' ') + *rightiter);
    }
  }
  else {
    for (; leftiter != left.end(); leftiter++) {
      ret.push_back(*leftiter);
    }
  }

  return ret;
}


int main() {

  vector<string> left1;
  left1.push_back("left line 1");
  left1.push_back("left line 2 uzuncana");
  left1.push_back("l3 kisa");
  left1.push_back("left 4");

  vector<string> right1;
  right1.push_back("right line 1");
  right1.push_back("right line 2 uzuncanaaaaaaaa");

  vector<string> combined = hcat(left1,right1);

  cout << "Case of left being longer, left " << left1.size() << " , right " << right1.size()  << std::endl;
  cout << std::endl;
  cout << std::endl;
  for (vector<string>::const_iterator iter = combined.begin(); iter != combined.end(); iter++) {
    cout << *iter << std::endl;
  } 



  right1.push_back("right line 3");
  right1.push_back("right line 4");
  right1.push_back("right 5 son");

  vector<string> combined2 = hcat(left1,right1);

  cout << "Case of right being longer,left  " << left1.size() << ", right " << right1.size() << std::endl;
  cout << std::endl;
  cout << std::endl;
  for(vector<string>::const_iterator iter = combined2.begin(); iter != combined2.end(); iter++) {
    cout << *iter << std::endl;
  }

  return 0;
}
