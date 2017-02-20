#include "Str.hpp"

std::ostream& operator<<(std::ostream& os, const Str& out) {
  for (Str::size_type ct = 0; ct < out.num; ct++) {
    os << out.data[ct];
  }
  return os;
}

char& Str::operator[](size_t i) {
  return data[i];
}
const char& Str::operator[](size_t i) const {
  return data[i];
}

Str::Str(const Str& other) {
  if (this != &other) {
    allocate(other.size());
    for(size_t ct = 0; ct < num; ct++)
      data[ct] = other[ct];	      
  }
}
Str& Str::operator=(const Str& other) {
  if (this != &other) {
    deallocate();
    allocate(other.size());
    for(size_t ct = 0; ct < num; ct++)
      data[ct] = other[ct];	      
  }
  return *this;
}


