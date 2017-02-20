#ifndef GUARD_String_Pic
#define GUARD_String_Pic

#include "Picture.hpp"


class Pic_base;
class String_Pic: public Pic_base {
private:
  friend class Picture;
  std::vector<std::string> data;
  

  // Constructor
  String_Pic(const std::vector<std::string>&v):data(v) {
  }
  //Utils
  wd_sz width() const;
  ht_sz height() const {
    return data.size();
  }
 
  void display(std::ostream&, ht_sz,bool) const;
};



#endif
