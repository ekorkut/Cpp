#ifndef GUARD_Frame_Pic
#define GUARD_Frame_Pic

#include "Pic_base.hpp"

class Frame_Pic: public Pic_base {
private:
  Ptr<Pic_base> p;

  friend Picture frame(const Picture&);

  Frame_Pic(const Ptr<Pic_base>& pic): p(pic){
  }
  Pic_base::wd_sz width() const {
    return p->width() + 4;
  }
  Pic_base::ht_sz height() const {
    return p->height() + 4;
  }
  void display(std::ostream&, Pic_base::ht_sz,bool) const;
};

#endif
