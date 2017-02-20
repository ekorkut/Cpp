#include <iostream>
#include <vector>
#include <string>
#include "Picture.hpp"

using std::cout;
using std::vector;
using std::string;

int main() {
 
  vector<string> vs;
  vs.push_back("Erman");
  vs.push_back("Korkut");
  Picture p = vs;

  Picture p2 = frame(p);

  Picture p3 = hcat(p2,p);



 
  return 0;
}
