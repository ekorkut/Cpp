#ifndef GUARD_Ptr
#define GUARD_Ptr
#include <cstddef>

template <class T>
class Ptr {

public:
  // Default Constructor
  Ptr() :p(nullptr),refptr(new std::size_t(1)) {
  }
  // Initialized constructor
  Ptr(T* data) {
    p = data;
    refptr = new std::size_t(1);
  }
  // Copy constructor
  Ptr(const Ptr<T>& r) {
    p = r.p;
    refptr = r.refptr;
    *refptr++;
  }
  // Assignment
  Ptr<T>& operator=(const Ptr<T>& r) {
    ++*r.refptr;
    *refptr--;
    if (*refptr == 0) {
      delete p;
      delete refptr;
    }
    p = r.p;
    refptr = r.refptr;
    
    return *this;
  }
  // Destructor
  ~Ptr() {
    *refptr--;
    if (*refptr == 0) {
      delete p;
      delete refptr;
    }
  }
  T* operator->() const {
    return p;
  }

private:
  T* p;
  std::size_t* refptr;
};




#endif
