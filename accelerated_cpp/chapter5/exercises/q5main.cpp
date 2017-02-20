#include <iostream>
#include <vector>
#include <string>
#include <cctype>


using std::vector;
using std::string;
using std::cin;
using std::cout;


string::size_type width(const vector<string>& input) {
  string::size_type ret = 0;
  for(vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++) {
    string::size_type s = iter->size();
    if (s > ret) {
      ret = s;
    }
  }
  return ret;
}

vector<string> center(const vector<string>& input) {
  // Declare the output
  vector<string> ret;
  // Find the longest width
  string::size_type w = width(input);


  string::size_type space = 1;
  


  // Process input string to eliminate each line's left and right spaces
  for (vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++) {
    string thisline = *iter;
    // Eliminate trailing whitespace
    string::size_type i = 0;
    for (; i != thisline.size();i++) {
      if (!isspace(thisline[i])) break;
    }
    // Eliminate padding whitespace
    string::size_type j = thisline.size();
    for(; j >=0;j--) {
      if (!isspace(thisline[j])) break;
    }

    // Now add if found something
    if (i != j) {
      ret.push_back(thisline.substr(i,j-i));
    }            
      
  }
  
    // Center each line now
  for (vector<string>::iterator iter = ret.begin(); iter!=ret.end(); iter++) {
    string::size_type gap = w - iter->size();
    string::size_type gapleft = gap / 2;
    string::size_type gapright = gap - gapleft;
    *iter = "*" + string(gapleft+space,' ') + (*iter) + string(gapright+space,' ') + "*";    
  }
  // Add the upper border
  ret.insert(ret.begin(),string(w+2*space+1,'*'));

  // Add the lower border
  ret.push_back(string(w+2*space+1,'*'));


  return ret;
}

int main() {

  cout << "Enter the input string:" << std::endl;


  // Read the string
  std::vector<string> input;
  string x;
  while (cin >> x) {
    input.push_back(x);
  }

  // Print the input string
  cout << "The input string is:" << std::endl;

  for (vector<string>::const_iterator iter = input.begin(); iter != input.end(); iter++) {
    cout << *iter << std::endl;
  }



  // Now call the function
  vector<string> centered = center(input);


  cout << "The centered and frame output is:" << std::endl; 
  // Print the output
  for(vector<string>::const_iterator iter = centered.begin();iter != centered.end();iter++) {
    cout << *iter << std::endl;
  }
  


  return 0;
}
