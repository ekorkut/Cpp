#include <vector>
#include <algorithm>
#include <iostream>


using std::vector;
using std::cout;

double median(vector<double> hw) {
  vector<double>::size_type size = hw.size();
  
  if (size == 0) {
    cout << "You must enter at least one grade"
      " try again" << std::endl;
    return 1;
  }

  sort(hw.begin(), hw.end());

  double median;
  double mid = size/2;

  if (size % 2 == 0) {
    median = (hw[mid-1] + hw[mid])/2;
  }
  else {
    median = hw[mid];
  }
  return median;
}
