#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;


int main() {

  // Read the input
  cout << "Enter the words:" << std::endl;
  string s;
  vector<string> input;
  while(cin >> s)
    input.push_back(s);


  map<string,int> counts;
  for (vector<string>::const_iterator iter = input.begin();iter != input.end();iter++) {
    counts[*iter]++;
  }

  // Print occurrences
  cout << "Printing occurrences" << std::endl;
  for (map<string,int>::const_iterator iter = counts.begin(); iter != counts.end();iter++) {
    cout << iter->first << " " << iter->second << std::endl;
  }

  // Groupings
  cout << "Grouped based on occurrences" << std::endl;
  map<int,vector<string> > groups;
  for (map<string,int>::const_iterator iter = counts.begin(); iter != counts.end();iter++) {
    groups[iter->second].push_back(iter->first);
  }
  for (map<int,vector<string> >::const_iterator iter = groups.begin(); iter != groups.end();iter++) {
    cout << iter->first << ":";
    const vector<string>& words = iter->second;
    for (vector<string>::const_iterator worditer = words.begin(); worditer != words.end();worditer++) {
      cout << *worditer << " ";
    }  
    cout << std::endl;
  }

  return 0;
}
 
