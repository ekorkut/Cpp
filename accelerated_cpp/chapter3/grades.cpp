#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::setprecision;

int main() {
  // Ask for name
  std::string name;
  cout << "Please enter your first name: ";
  cin >> name;
  cout << "Hello " << name << "!" << std::endl;

  // Final and midterm
  double final, midterm;
  cout << "Enter your final exam grade: ";
  cin >> final;
  cout << "Enter your midterm grade: ";
  cin >> midterm;

  // Homework grades
  cout << "Enter your homework grades followed by EOF: ";
  std::vector<double> homeworks;
  double x;
  while (cin >> x) {
    homeworks.push_back(x);
  }

  // Calculate homeworks grade

  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = homeworks.size();
  
  if (size == 0) {
    cout << "You must enter at least one grade"
      " try again" << std::endl;
    return 1;
  }

  sort(homeworks.begin(), homeworks.end());

  double median;
  double mid = size/2;

  if (size % 2 == 0) {
    median = (homeworks[mid-1] + homeworks[mid])/2;
  }
  else {
    median = homeworks[mid];
  }

  std::streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << 0.2*midterm + 0.4*final + 0.4*median
       << setprecision(prec) << std::endl;


  return 0;
}
