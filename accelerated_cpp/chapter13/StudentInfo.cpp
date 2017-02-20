#include <iostream>
#include <vector>
#include "StudentInfo.hpp"
#include "grade.hpp"
#include "Core.hpp"
#include "Grad.hpp"

using std::istream;
using std::vector;

StudentInfo::StudentInfo(const StudentInfo& c): cp(0){
  if (c.cp) {
    cp = c.cp->clone();
  }  
}

StudentInfo& StudentInfo::operator=(const StudentInfo&c) {
  if (&c != this) {
    delete cp;

    if (c.cp)
      cp = c.cp->clone();
    else
      cp = 0;
  }
  return *this;

}

istream& StudentInfo::read(istream& in) {
  delete cp;

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








