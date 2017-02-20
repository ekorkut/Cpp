#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::setprecision;
using std::vector;
using std::istream;

double grade(double final, double midterm, double homework) {
  return (0.2*midterm + 0.4*final + 0.4*homework);
}

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


double grade(double final, double midterm, const vector<double>& hmw) {
  if (hmw.size() == 0) {
    throw std::domain_error("Student has done no homework");
  }
  return grade(final,midterm,median(hmw));
}

istream& readhomework(istream& in, vector<double>& hmw) {
  hmw.clear();
  double x;
  while(in >> x) {
    hmw.push_back(x);
  }
  in.clear();
  return in;
}


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
  vector<double> homeworks;
  readhomework(cin,homeworks);
  try {
    double final_grade = grade(final,midterm,homeworks); 
    std::streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
	 << final_grade
	 << setprecision(prec) << std::endl;
  }
  catch (std::domain_error) {
    cout << "You must enter homework grades, try again!" << std::endl;
  } 


  return 0;
}
