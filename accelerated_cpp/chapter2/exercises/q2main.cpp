#include <iostream>
#include <string>

using std::cout;
using std::string;
 

int main() {
  cout << "Please enter your name:";

  string name;
  std::cin >> name;
  const string greeting = "Hello, " + name + "!";

  const int vpad = 0;
  const int rows = vpad*2 + 3;
  const int hpad = 5;
  const string::size_type cols = 2*hpad + greeting.size() + 2;

  cout << std::endl;

  int r = 0;
  for (int r = 0;r != rows;r++) {
    string::size_type c = 0;
    while (c != cols) {
      if ((r == vpad+1) && (c == hpad+1)) {
	cout << greeting;
	  c+= greeting.size();
      }
      else {
	if ((r == 0) || (r == rows-1 ) || (c == 0) || (c == cols-1)) {
	  cout << '*';
	}
	else {
	  cout << ' ';
	}	
	c++;
      }
    }      
    cout << std::endl;
  }

  return 0;
}
