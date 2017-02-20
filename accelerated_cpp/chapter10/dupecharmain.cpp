#include <algorithm>
#include <cstring>
#include <iostream>




char* duplicate_chars(const char* p) {
  size_t len = strlen(p) + 1;

  char* ret = new char[len];

  std::copy(p,p+len,ret);

  return ret;

}

int main() {

  char  p[] = "hello";

  char* out = duplicate_chars(p);

  std::cout << "copied string is " << out << std::endl;

  delete out;
  return 0;
}
