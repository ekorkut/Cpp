#ifndef GUARD_Picture
#define GUARD_Picture

#include <vector>
#include <string>
#include <iostream>

#include "Ptr.hpp"

class Pic_base;
class Picture {
public:
  Picture(const std::vector<std::string>& = std::vector<std::string>());
  Picture(Pic_base* ptr) :p(ptr){
  }
  friend Picture frame(const Picture&);
  friend Picture hcat(const Picture&, const Picture&);
  friend Picture vcat(const Picture&, const Picture&);
  friend std::ostream& operator<<(std::ostream&, const Picture&);

private:
  Ptr<Pic_base> p;

};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);




#endif
