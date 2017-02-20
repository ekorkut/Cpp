#include <iostream>
int main() {
  long r = 1;

  for (int ct = 1; ct != 10; ct++)
    r *= ct;

  std::cout << "Result is " << r << "." << std::endl;
  return 0;
}
