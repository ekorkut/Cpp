#ifndef GUARD_HCat_Pic
#define GUARD_HCat_Pic
#include "Ptr.hpp"

class Picture;
class Pic_base;

class HCat_Pic: public Pic_base {
private:
  Ptr<Pic_base> left;
  Ptr<Pic_base> right;

  friend Picture hcat(const Picture&, const Picture&);

  HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r):left(l),right(r){
  }
  Pic_base::wd_sz width() const {
    return left->width() + right->width();
  }
  Pic_base::ht_sz height() const {
    return std::max(left->height(),right->height());
  }
  void display(std::ostream&, Pic_base::ht_sz,bool) const;

};





#endif
