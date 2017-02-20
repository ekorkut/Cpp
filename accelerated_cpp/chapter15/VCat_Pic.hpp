#ifndef GUARD_VCat_Pic
#define GUARD_VCat_Pic

class Pic_base;
#include "Pic_base.hpp"

class VCat_Pic: public Pic_base {
private:
  Ptr<Pic_base> top;
  Ptr<Pic_base> bottom;

  friend Picture vcat(const Picture&, const Picture&);

  VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t),bottom(b) {
  }
  Pic_base::wd_sz width() const {
    return std::max(top->width(),bottom->width());
  }
  Pic_base::ht_sz height() const {
    return top->height()+bottom->height();
  }
  void display(std::ostream&, Pic_base::ht_sz,bool) const;
  

};

#endif
