#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;


int main(){
  
  vector<int> numbers;
  cout << "Enter integers to separate into quartiles: " << endl;
  int x;
  while (cin >> x) {
    numbers.push_back(x);
  }
  // Sort numbers
  vector<int>::size_type N = numbers.size();
  sort(numbers.begin(),numbers.end());


  for (vector<int>::size_type ct = 0; ct !=N; ct++) {
    if (ct == 0)
      cout << "Numbers in largest quarter:" << endl;
    else {
      if (ct == N/4) {
	cout << "Numbers in 2nd largest quarter:" << endl;
      }
      else {
	if (ct == N/2) {
	  cout << "Numbers in 3rd largest quarter:" << endl;
	}
	else {
	  if (ct == 3*N/4) {
	    cout << "Numbers in last quarter:" << endl;
	  }
	}
      }
    }
    cout << numbers[ct] << endl;
    
  
  }
  
  
  return 0;
}
