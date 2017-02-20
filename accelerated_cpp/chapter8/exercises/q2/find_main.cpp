#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::vector;
using std::list;


template <class In,class Value>

In myfind(In b, In e, Value v) {
  for (In iter = b; iter!=e;iter++) {
    if (*iter == v) {
      return iter;
    }
  }
  

  return e;
}

int main() {



  vector<int> positive1;
  positive1.push_back(1);
  positive1.push_back(2);
  positive1.push_back(3);



  cout << "Vector<int> positive example:" << std::endl;
  bool myans = myfind(positive1.begin(), positive1.end(), 2) == positive1.end();
  bool libans = find(positive1.begin(),positive1.end(),2) == positive1.end();

  cout << "My answer: " <<  myans << std::endl;
  cout << "Library answer: " << libans  << std::endl;


  list<double> negative1;
  negative1.push_back(1.0);
  negative1.push_back(2);
  negative1.push_back(3.0);


  cout << "list<double> negative answer:" << std::endl;
  myans = myfind(negative1.begin(), negative1.end(),1.1) == negative1.end();
  libans = find(negative1.begin(), negative1.end(), 1.1) == negative1.end();
  cout << "My answer:" << myans << std::endl;
  cout << "Library answer:" << libans << std::endl;
  


  return 0;


  return 0;
}
