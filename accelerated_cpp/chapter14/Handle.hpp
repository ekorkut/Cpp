#ifndef GUARD_Handle
#define GUARD_Handle

#include <stdexcept>
template <class T>
class Handle {
public:
  // Constructor
  Handle():p(0) {
  }
  // Copy constructor
  Handle(const Handle&c):p(0) {
    if (c.p) {
      p = c.p->clone();
    }
  }
  // Assignment operator
  Handle& operator=(const Handle&c) {
    if (&c != this) {
      delete p;
      if (c.p)
	p = c.p->clone();
    }
    return *this;
  }
  // Destructor
  ~Handle() {
    delete p;
  }
  // Construct from pointer
  Handle(T* tp) {
    p = tp;
  }

  // Pointer operators
  T& operator*() const {
    if(p)
      return *p;
    throw std::runtime_error("Unbound handle");
  }
  T* operator->()const {
    if(p)
      return p;
    throw std::runtime_error("Unbound Handle");
  } 
  // Convert to bool
  operator bool() const {
    return p;
  }
  // Compare
  static bool compareHandle(const Handle& h1, const Handle& h2) {
  return h1->name() < h2->name();
}


private:
  T* p;
};

#endif
