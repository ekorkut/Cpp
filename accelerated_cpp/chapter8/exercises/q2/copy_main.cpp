#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout;
using std::vector;
using std::list;

template <class In,class Out>
void mycopy(In b, In e, Out d) {
  for (In iter = b; iter != e; iter++) {
    *d = *iter;
    d++;
  }
}


int main() {


  vector<int> positive1;
  positive1.push_back(1);
  positive1.push_back(2);
  positive1.push_back(3);

  vector<int> myans1,libans1;

  cout << "Vector<int> positive example:" << std::endl;
  vector<int>::iterator startpoint = positive1.begin();
  startpoint++;
  mycopy(startpoint, positive1.end(),back_inserter(myans1));
  copy(startpoint, positive1.end(), back_inserter(libans1));

  // Print them
  cout << "My answer: ";
  for(vector<int>::const_iterator iter = myans1.begin(); iter!= myans1.end();iter++)
    cout << *iter << " ";
  cout << std::endl;

  cout << "Library answer: ";
  for(vector<int>::const_iterator iter = libans1.begin(); iter != libans1.end();iter++)
    cout << *iter << " ";
  cout << std::endl;


  list<double> positive2;
  positive2.push_back(1.0);
  positive2.push_back(2);
  positive2.push_back(3.0);

  list<double> myans2,libans2;
  list<double>::iterator endpoint = positive2.end();
  endpoint--;
  endpoint--;
  mycopy(positive2.begin(),endpoint,back_inserter(myans2));
  copy(positive2.begin(),endpoint,back_inserter(libans2));



  cout << "list<double> positive answer:" << std::endl;

    // Print them
  cout << "My answer: ";
  for(list<double>::const_iterator iter = myans2.begin(); iter!= myans2.end();iter++)
    cout << *iter << " ";
  cout << std::endl;

  cout << "Library answer: ";
  for(list<double>::const_iterator iter = libans2.begin(); iter != libans2.end();iter++)
    cout << *iter << " ";
  cout << std::endl;


  return 0;
}
