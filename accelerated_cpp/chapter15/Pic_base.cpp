#include "Pic_base.hpp"

static void pad(std::ostream& os, wd_sz beg, wd_sz end) {  
  while(beg != end) {
    os << " ";
    ++beg;
  }
}
