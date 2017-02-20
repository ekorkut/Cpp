#ifndef GUARD_RefHandle
#define GUARD_RefHandle

#include <stdexcept>
#include <iostream>
template <class T>
class RefHandle {
public:
  // Constructor
  RefHandle() {
    std::cout << "Default constructor" << std::endl;
    p = 0;
    refcounter = new std::size_t(1);
  }
  // Copy constructor
  RefHandle(const RefHandle& c) {
    std::cout << "RefHandle: Copy constructor" << std::endl;
    p = c.p;
    refcounter = c.refcounter;
    (*refcounter)++;
  }
  // Assignment operator
  RefHandle& operator=(const RefHandle& rhs) {
    std::cout << "RefHandle: Assignment operator" << std::endl;
    (*(rhs.refcounter))++;
    (*refcounter)--;
    if (*refcounter == 0) {
      std::cout << "RefHandle: deleting last instance in assignment" << std::endl;
      delete p;
      delete refcounter;
    }
    p = rhs.p;    
    refcounter = rhs.refcounter;
    return *this;
  }
  // Destructor
  ~RefHandle() {
    std::cout << "Destructor called" << std::endl;
    (*refcounter)--;
    std::cout << "Number of remaining instances is " << *refcounter << std::endl;
    if (*refcounter == 0) {
      std::cout << "RefHandle: deleting last instance" << std::endl;
      delete p;
      delete refcounter;
    }
  }
  // Construct from pointer
  RefHandle(T* tp) {
    std::cout << "RefHandle: Constructing from pointer" << std::endl;
    p = tp;
    refcounter = new std::size_t(1);

    printNumInstances();
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
  void printNumInstances() {
    std::cout << "Number of instances is now " << *refcounter << std::endl;
  }


private:
  T* p;
  std::size_t* refcounter;
};

#endif
