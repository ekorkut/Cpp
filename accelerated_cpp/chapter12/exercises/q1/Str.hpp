#ifndef GUARD_Str
#define GUARD_Str

#include <cstddef>
#include <cstring>
#include <iostream>


class Str {
public:
  typedef size_t size_type;
  typedef char* iterator;
  typedef const char* const_iterator;
  typedef char value_type;
  typedef std::ptrdiff_t difference_type;
  typedef char& reference;
  typedef const char& const_reference;
  size_t size() const {
    return num;
  }
  // Constructors
  Str() {
    init();
  }

  Str(const char* c) {
    // Allocate and copy   
    size_t s = std::strlen(c);
    allocate(s);
    for (size_t ct = 0; ct < num; ct++)
      data[ct] = c[ct];
  }

  Str(size_t n, char c) {
    allocate(n);
    for (size_t ct = 0; ct < num; ct++)
      data[ct] = c;    
  }
  // Destructor
  ~Str() {
    deallocate();
  }
  // Copy constructor
  Str(const Str& other);
  // Assignment
  Str& operator=(const Str& other);
  // Operator: []
  char& operator[](size_t i);
  const char& operator[](size_t i) const;
  // Operator: << 
  friend std::ostream& operator<<(std::ostream&,const Str&);
  // Iterators
  iterator begin() {
    return data;
  }
  const_iterator begin() const {
    return data;
  }  
  iterator end() {
    return data+num;
  }
  const_iterator end() const {
    return data+num;
  }
private:
  char* data;
  size_t num;
  void allocate(size_t n) {
    num = n;
    data = new char[num];
  }
  void deallocate() {
    if (data != NULL) {
      delete[] data;
    }
    init();
  }
  void init() {
    data = NULL;
    num = 0;
  }
};

// Output stream
std::ostream& operator<<(std::ostream&, const Str&);


#endif
