#include <vector>
#include <iostream>
#include "Vec.hpp"

using std::vector;

int main() {

  vector<int> a(10,5);

  std::cout << "Elements of the standard vector a:" << std::endl;
  for(vector<int>::const_iterator iter = a.begin();iter != a.end();iter++)
    std::cout << *iter << " ";
  std::cout << std::endl;


  vector<int> b = a;

  b.push_back(7);
  b.erase(b.begin());
  b.push_back(9);

  std::cout << "Elements of the standard vector a:" << std::endl;
  for(vector<int>::const_iterator iter = a.begin();iter != a.end();iter++)
    std::cout << *iter << " ";
  std::cout << std::endl;

  std::cout << "Elements of the standard vector b:" << std::endl;
  for(vector<int>::const_iterator iter = b.begin();iter != b.end();iter++)
    std::cout << *iter << " ";
  std::cout << std::endl;


  std::cout << " NOW MY OWN VEC IMPLEMENTATION" << std::endl;

  Vec<int> c(10,5);
  std::cout << "Elements of my vector c:" << std::endl;
  for(Vec<int>::const_iterator iter = c.begin();iter != c.end();iter++)
    std::cout << *iter << " ";
  std::cout << std::endl;


  Vec<int> d = c;

  d.push_back(7);
  d.push_back(9);

  std::cout << "Elements of my vector c:" << std::endl;
  for(Vec<int>::const_iterator iter = c.begin();iter != c.end();iter++)
    std::cout << *iter << " ";
  std::cout << std::endl;

  std::cout << "Elements of my vector d:" << std::endl;
  for(Vec<int>::const_iterator iter = d.begin();iter != d.end();iter++)
    std::cout << *iter << " ";
  std::cout << std::endl;


  
  return 0;
}
