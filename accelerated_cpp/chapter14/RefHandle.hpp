#ifndef GUARD_RefHandle
#define GUARD_RefHandle

#include <stdexcept>
template <class T>
class RefHandle {
public:
  // Constructor
  RefHandle():p(0) {
    refcounter = new std::size_t(1);
  }
  // Copy constructor
  RefHandle(const RefHandle&c):p(c.p) {
    refcounter = c.refcounter;
    *refcounter++;
  }
  // Assignment operator
  RefHandle& operator=(const RefHandle&c) {
    *c.refcounter++;
    *refcounter--;
    if (*refcounter == 0) {
      delete p;
      delete refcounter;
    }
    p = c.p;    
    refcounter = c.refcounter;
    return *this;
  }
  // Destructor
  ~RefHandle() {
    *refcounter--;
    if (*refcounter == 0) {
      delete p;
      delete refcounter;
    }
  }
  // Construct from pointer
  RefHandle(T* tp) {
    p = tp;
    refcounter = new std::size_t(1);
  }

  // Pointer operators
  T& operator*() const {
    if(p)
      return *p;
    throw std::runtime_error("Unbound RefHandle");
  }
  T* operator->()const {
    if(p)
      return p;
    throw std::runtime_error("Unbound RefHandle");
  } 
  // Convert to bool
  operator bool() const {
    return p;
  }
  // Compare
  static bool compareRefHandle(const RefHandle& h1, const RefHandle& h2) {
  return h1->name() < h2->name();
}


private:
  T* p;
  std::size_t* refcounter;
};

#endif
