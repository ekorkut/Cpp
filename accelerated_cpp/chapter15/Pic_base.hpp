#ifndef GUARD_Pic_base
#define GUARD_Pic_base

#include <vector>
#include <string>
#include <iostream>

#include "Picture.hpp"
#include "Frame_Pic.hpp"
#include "HCat_Pic.hpp"
#include "VCat_Pic.hpp"
#include "String_Pic.hpp"

class Picture;
class Pic_base {
public:
  virtual ~Pic_base();
private:
  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;

  virtual wd_sz width() const = 0;
  virtual ht_sz height() const = 0;
  virtual void display(std::ostream&, ht_sz,bool) const = 0;

  friend class Frame_Pic;
  friend class HCat_Pic;
  friend class VCat_Pic;
  friend class String_Pic;
  friend std::ostream& operator<<(std::ostream&, const Picture&);
protected:
  static void pad(std::ostream& os, wd_sz beg, wd_sz end);
};


#endif
