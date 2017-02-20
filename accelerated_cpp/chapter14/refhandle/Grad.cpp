#include <iostream>
#include <algorithm>
#include "Grad.hpp"

using std::istream;

Grad::Grad():thesis(0) {
}
Grad::Grad(istream& in) {
  read(in);
}

istream& Grad::read(istream& in) {
  read_common(in);
  in >> thesis;
  readhomeworks(in,homeworks);
  return in;
}

double Grad::grade()const {
  return std::min(Core::grade(),thesis);
}
