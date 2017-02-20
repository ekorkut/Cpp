#include <iostream>
#include <iomanip>

double powerof10(int n) {
  double ret = 1;
  
  for (int ct = 0; ct != n; ct++)
    ret *= 10;

  return ret;
}

int numdigits(double number) {
  int ret = 0;
  int ct = 0;
  while ((number/powerof10(ct)) >= 1.0) {
    ret++;
    ct++;
  }
  return ret;
}

int main() {

  double limit = 1000;
  double n = numdigits(limit-1);
  std::cout << "Number of digits in upper limit is " << n << std::endl;
  for (double ct = 0; ct != limit; ct++) {
    std::cout << std::setw(n) << ct << std::setw(1) << " " << std::setw(2*n) << (ct*ct) << std::endl;
  }
    
  return 0;
}
