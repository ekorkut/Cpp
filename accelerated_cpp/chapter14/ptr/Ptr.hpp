#ifndef GUARD_Ptr
#define GUARD_Ptr

#include <stdexcept>
#include <iostream>
template <class T>
class Ptr {
public:
  // Make unique
  void make_unique() {
    if (*refcounter != 1) {
      --*refcounter;
      refcounter = new std::size_t(1);
      p = p ? p->clone() : 0;
    }
  }
  // Constructor
  Ptr() {
    p = 0;
    refcounter = new std::size_t(1);
  }
  // Copy constructor
  Ptr(const Ptr& c) {
    p = c.p;
    refcounter = c.refcounter;
    (*refcounter)++;
  }
  // Assignment operator
  Ptr& operator=(const Ptr& rhs) {
    (*(rhs.refcounter))++;
    (*refcounter)--;
    if (*refcounter == 0) {
      delete p;
      delete refcounter;
    }
    p = rhs.p;    
    refcounter = rhs.refcounter;
    return *this;
  }
  // Destructor
  ~Ptr() {
    (*refcounter)--;
    if (*refcounter == 0) {
      delete p;
      delete refcounter;
    }
  }
  // Construct from pointer
  Ptr(T* tp) {
    p = tp;
    refcounter = new std::size_t(1);

    printNumInstances();
  }
  

  // Pointer operators
  T& operator*() const {
    if(p)
      return *p;
    throw std::runtime_error("Unbound Ptr");
  }
  T* operator->()const {
    if(p)
      return p;
    throw std::runtime_error("Unbound Ptr");
  } 
  // Convert to bool
  operator bool() const {
    return p;
  }
  // Compare
  static bool comparePtr(const Ptr& h1, const Ptr& h2) {
    return h1->name() < h2->name();
  }
  void printNumInstances() const {
    std::cout << "Number of instances is now " << *refcounter << std::endl;
  }


private:
  T* p;
  std::size_t* refcounter;
};

#endif
