#ifndef GUARD_Grad
#define GUARD_Grad

#include <iostream>
#include "Core.hpp"
class Grad: public Core {
public:
  Grad();
  Grad(std::istream&);
  std::istream& read(std::istream&);
  double grade() const;
protected:
  virtual Grad* clone() const { return new Grad(*this);}
private:
  double thesis;
};

#endif

