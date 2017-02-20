#include <iostream>

int main(int argc, char** argv) {

  std::cout << "argc = " << argc << std::endl;
  std::cout << "argv[0]= " << argv[0] << std::endl;
  
  if (argc > 1) {

    std::cout << argv[1];
    for (int i = 2;i != argc; i++) {
      std::cout << " " << argv[i];
    }
  }

  std::cout << std::endl;



  return 0;
}
