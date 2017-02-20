#include <iostream>
#include "VCat_Pic.hpp"
#include "Pic_base.hpp"

void VCat_Pic::display(std::ostream& os, Pic_base::ht_sz row, bool do_pad) const {
  Pic_base::wd_sz w = 0;
  if (row < top->height()) {
    top->display(os,row,do_pad);
    w = top->width();
  }
  else if (row < height()) {
    bottom->display(row-top->height(),do_pad);
    w = bottom->width();
  }
  if (do_pad)
    pad(os,w,width());


}
