#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::vector;
using std::list;

template <class In>
bool myequal(In b, In e, In b2) {
  for (In iter = b; iter != e; iter++) {
    if (*iter != *b2) {
      return false;
    }
    b2++;
  }
  return true;
}




int main() {

  vector<int> positive1;
  positive1.push_back(1);
  positive1.push_back(2);
  positive1.push_back(3);

  vector<int> positive2 = positive1;  

  cout << "Vector<int> positive example:" << std::endl;
  cout << "My answer: " << myequal(positive1.begin(), positive1.end(), positive2.begin()) << std::endl;
  cout << "Library answer: " << equal(positive1.begin(),positive1.end(), positive2.begin()) << std::endl;


  list<double> negative1;
  negative1.push_back(1.0);
  negative1.push_back(2);
  negative1.push_back(3.0);

  list<double> negative2;
  negative2.push_back(1.0);
  negative2.push_back(2);
  negative2.push_back(3.1);


  cout << "list<double> negative answer:" << std::endl;
  cout << "My answer:" << myequal(negative1.begin(), negative1.end(),negative2.begin()) << std::endl;
  cout << "Library answer:" << equal(negative1.begin(), negative1.end(), negative2.begin())<< std::endl;
  


  return 0;
}
