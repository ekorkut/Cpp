#include <iostream>
#include "HCat_Pic.hpp"
#include "Pic_base.hpp"

void HCat_Pic::display(std::ostream& os, Pic_base::ht_sz row, bool do_pad) const {
  left->display(os,row,do_pad || row < right->height());
  right->display(os,row,do_pad);
}
