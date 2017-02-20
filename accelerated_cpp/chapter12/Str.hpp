#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <cstring>
#include "Vec.hpp"

class Str {
public:
  typedef Vec<char>::size_type size_type;
  // Constructor
  Str() { };
  Str(const char* cp) {
    std::copy(cp, cp + strlen(cp),std::back_inserter(data));
  }

  // Operators
  char& operator[](size_type i) {
    return data[i];
  }
  const char& operator[](size_type i) const {
    return data[i];
  }

  friend std::istream& operator>>(std::istream& in, Str& s);
  
  Str& operator+=(const Str&s) {
    std::copy(s.data.begin(),s.data.end(),std::back_inserter(data));
    return *this;
  }
  // Conversion to double
  operator double() const {
    return size();
  }

  // Other utils
  size_type size() const {
    return data.size();
  }

private:
  Vec<char> data;
};

// + operator
Str operator+(const Str& s1, const Str& s2) {
  Str r = s1;
  r += s2;
  return r;
}

// Input-output operators
std::ostream& operator<<(std::ostream& o, const Str& s) {
  for(Str::size_type i = 0; i != s.size(); i++) {
    o << s[i];
  }
  return o;
}

std::istream& operator>>(std::istream& in, Str& s) {
  s.data.clear();

  char c;
  while (in.get(c) && isspace(c)) {
    // Nothing to do
  }
  if (in) {
    do
      s.data.push_back(c);
    while (in.get(c) && !isspace(c));
  }
  if (in)
    in.unget();
  
  return in;
}


#endif
