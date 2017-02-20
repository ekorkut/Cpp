#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "median.hpp"
#include "StudentInfo.hpp"
#include "grade.hpp"

using std::vector;
using std::string;

double median_analysis(const vector<StudentInfo>& students) {
  vector<double> grades;
  transform(students.begin(),students.end(),back_inserter(grades),grade_aux);

  return median(grades);
}


void write_analysis(std::ostream& s,
		    string analysis,
		    double analysisfunc(const vector<StudentInfo>&),
		    const vector<StudentInfo>& did,
		    const vector<StudentInfo>& didnot) {
  s << analysis << ": median(did)= " << analysisfunc(did) << std::endl;
  s << analysis << ": median(didnot)= " << analysisfunc(didnot) << std::endl;
  return;
}




