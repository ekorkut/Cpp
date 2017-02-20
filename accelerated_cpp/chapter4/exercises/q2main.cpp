#include <iostream>
#include <iomanip>
int main() {

  int n = 2;
  for (int ct = 0; ct != 100; ct++) {
    std::cout << std::setw(n) << ct << std::setw(1) << " " << std::setw(2*n) << (ct*ct) << std::endl;
  }
    
  return 0;
}
