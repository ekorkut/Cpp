#include <vector>
#include <stdexcept>
#include "grade.hpp"
#include "median.hpp"


using std::vector;

double grade(double final, double midterm, double homework) {
  return (0.2*midterm + 0.4*final + 0.4*homework);
}

double grade(double final, double midterm, const vector<double>& hmw) {
  if (hmw.size() == 0) {
    throw std::domain_error("Student has done no homework");
  }
  return grade(final,midterm,median(hmw));
}
