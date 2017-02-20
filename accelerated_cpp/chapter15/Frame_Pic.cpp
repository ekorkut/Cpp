#include <iostream>
#include <string>
#include "Frame_Pic.hpp"
#include "Pic_base.hpp"

void Frame_Pic::display(std::ostream& os, Pic_base::ht_sz row, bool do_pad) const {
  if (row >= height())  {
    if (do_pad)
      pad(os,0,width());
  }
  else {
    if (row == 0 || row == height()-1) {
      os << std::string(width(),'*');
    }
    else if(row == 1 || row == height()-2) {
      os << "*";
      pad(os,1,width()-1);
      os << "*";
    }
    else {
      os << "* ";
      p->display(os,row-2,true);
      os << " *";
    }
  }

}
