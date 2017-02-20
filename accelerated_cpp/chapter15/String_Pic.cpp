#include <iostream>
#include "String_Pic.hpp"
#include "Pic_base.hpp"

Pic_base::wd_sz String_Pic::width() const {
  Pic_base::wd_sz n = 0;
  Pic_base::ht_sz h = this->height();
  for (Pic_base::ht_sz ct = 0; ct < h;ct++) {
    n = std::max(n,data[ct].size());
  }
  return n;

}

void String_Pic::display(std::ostream& os, Pic_base::ht_sz row,bool do_pad) const {
  Pic_base::wd_sz start = 0;
  if (row < height()) {
    os << data[row];
    start = data[row].size();
  }
  if (do_pad) {
    pad(os,start,width());
  }
  
}


