#include <vector>
#include <string>

#include "Picture.hpp"
#include "String_Pic.hpp"
#include "Frame_Pic.hpp"
#include "HCat_Pic.hpp"
#include "VCat_Pic.hpp"
#include "Pic_base.hpp"


using std::vector;
using std::string;

Picture::Picture(const vector<string>& r) {
  p = new String_Pic(r);
}


Picture frame(const Picture& pic) {
  return new Frame_Pic(pic.p);
}
Picture hcat(const Picture& l, const Picture& r) {
  return new HCat_Pic(l.p,r.p);
}
Picture vcat(const Picture& t, const Picture& b) {
  return new VCat_Pic(t.p,b.p);
}

std::ostream& operator<<(std::ostream&os, const Picture& pic) {
  const Pic_base::ht_sz ht = pic.p->height();

  for(Pic_base::ht_sz ct = 0; ct < ht; ct++) {
    pic.p->display(os,ct,false);
    os << std::endl;
  }



  return os;
}




