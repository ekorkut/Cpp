#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::vector;
using std::list;

 
template <class In>
In mysearch(In b, In e, In b2, In e2) {
  In iter = b;

  while (iter!=e) {
    if (*iter == *b2) {
      In start = iter;
      start++;
      In inner = b2;
      inner++;
      while(inner!= e2) {
	if (*start != *inner) {
	  break;
	} 
	start++; inner++;
      }
      if (inner == e2) {
	// Found it, return
	return iter;
      }
    }
    iter++;
  }
  return e;
}

int main() {


  vector<int> positive1;
  positive1.push_back(1);
  positive1.push_back(1);
  positive1.push_back(2);

  vector<int> positive2;
  positive2.push_back(1);
  positive2.push_back(2);

  bool myans,libans;

  cout << "Vector<int> positive example:" << std::endl;
  myans = mysearch(positive1.begin(),positive1.end(),positive2.begin(),positive2.end()) != positive1.end();
  libans = search(positive1.begin(),positive1.end(),positive2.begin(),positive2.end()) != positive1.end();
  cout << "My answer: " << myans << std::endl;
  cout << "Library answer: " << libans << std::endl;


  list<double> negative1;
  negative1.push_back(1.0);
  negative1.push_back(2);
  negative1.push_back(3.0);

  list<double> negative2;
  negative2.push_back(2);
  negative2.push_back(3.1);


  cout << "list<double> negative answer:" << std::endl;
  myans = mysearch(negative1.begin(),negative1.end(),negative2.begin(),negative2.end()) != negative1.end();
  libans = search(negative1.begin(),negative1.end(),negative2.begin(), negative2.end()) != negative1.end();
  cout << "My answer:" << myans << std::endl;
  cout << "Library answer:" << libans << std::endl;
  


  return 0;
}
