#ifndef GUARD_Core
#define GUARD_Core

#include <iostream>
#include <string>
#include <vector>

class Core {
public:
  friend class StudentInfo;
  Core();
  Core(std::istream&);
  virtual ~Core() { };
  std::string name() const;
  virtual std::istream& read(std::istream&);
  virtual double grade() const;
protected:
  std::istream& read_common(std::istream&);
  double midterm, final;
  std::vector<double> homeworks;
  virtual Core* clone() const { return new Core(*this);}
private:
  std::string n;

};


std::istream& readhomeworks(std::istream& in, std::vector<double>& hmw);
bool compare(const Core& c1, const Core& c2);
bool compare_Coreptr(const Core* c1, const Core* c2);

#endif
