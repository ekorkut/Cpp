#include <string>
#include <vector>
#include <iostream>
#include "Core.hpp"
#include "grade.hpp"

using std::string;
using std::istream;
using std::vector;

Core::Core():midterm(0),final(0) {
}

Core::Core(istream& in) {
  std::cout << "Core::Core(istream&)" << std::endl;
  read(in);
}

string Core::name() const {
  return n;
}

double Core::grade() const {
  return ::grade(final,midterm,homeworks);
}

istream& Core::read_common(istream& in){
  in >> n >> final >> midterm;
  return in;
}

istream& Core::read(istream& in) {
  read_common(in);
  readhomeworks(in,homeworks);
  return in;
}

// Read homeworks utility
istream& readhomeworks(istream& in, vector<double>& hmw) {
  if (in) {
    hmw.clear();
    double x;
    while(in >> x) {
      hmw.push_back(x);
    }
    in.clear();
  }
  return in;
}

// compare utility
bool compare(const Core& c1, const Core& c2) {
  return c1.name() < c2.name();
}

bool compare_Coreptr(const Core* c1, const Core* c2) {
  return compare(*c1,*c2);
}




