#include <iostream>
int main() {
  int first;
  std::cout << "Enter the first number: " << std::endl;
  std::cin >> first;
  
  int second;
  std::cout << "Enter the second number: " << std::endl;
  std::cin >> second;

  if (first < second)
    std::cout << "The bigger one is the second one, that is, " << second << "." << std::endl;
  else
    std::cout << "The bigger one is the first one, that is, " << first << "." << std::endl;

  return 0;
}
