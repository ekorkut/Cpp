#include <iostream>
#include <string>

using std::cout;
using std::string;
 

int main() {
  cout << "Please enter the height:" << std::endl;
  string::size_type len;
  std::cin >> len;

  // Square
  cout << "Drawing square: " << std::endl;
  for (int r = 0;r != len;r++) {
    if ((r == 0) || (r == len-1)) {
      string stars(len,'*');
      cout << stars << std::endl;
    }
    else {
      string::size_type c = 0;
      string space(len-2,' ');
      cout << "*" << space << "*" << std::endl;
    }
  }
  // Rectangle
  cout << "Drawing rectangle: " << std::endl;
  string::size_type height = len;
  string::size_type width = len*1.6180;
  for (int r = 0;r != height;r++) {
    if ((r == 0) || (r == height-1)) {
      string stars(width,'*');
      cout << stars << std::endl;
    }
    else {
      string::size_type c = 0;
      string space(width-2,' ');
      cout << "*" << space << "*" << std::endl;
    }
  }
  // Triangle
  cout << "Drawing triangle: " << std::endl;
  for (int r = 0;r != len;r++) {
    if (r == 0) {
	string left(len-r,' ');
	cout << left << "*" << left;
    }
    else {
	string left(len-r,' ');
	string gap;
	if (r == len-1) {
	  string g(2*r-1,'*');
	  gap = g;
	}
	else {
	  string g(2*r-1,' ');
	  gap = g;
	}
	cout << left << "*" << gap << "*" << left;	      
    }    
    cout << std::endl;    
  }
  
  return 0;
}

