#include <iostream>
#include <vector>
#include "StudentInfo.hpp"
#include "grade.hpp"
#include "Core.hpp"
#include "Grad.hpp"

using std::istream;
using std::vector;

istream& StudentInfo::read(istream& in) {

  char ch;
  in >> ch;
  if (ch == 'C')
    cp = new Core(in);
  else
    cp = new Grad(in);
  return in;
}

double StudentInfo::grade() const {
  return cp->grade();
}

std::string StudentInfo::name() const {
  return cp->name();
}








