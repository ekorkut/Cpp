#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>



using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::unordered_map;

typedef vector<string>::size_type vec_sz;


int main() {
  vector<string> words;
  // Read words
  string s;
  while (cin >> s) {
    words.push_back(s);   
  }
  // Print the number of words
  vec_sz N = words.size();
  cout << "There are " << N << " words in this sentence." << endl;

  // Calculate individual occurrences of each word
  unordered_map<string,vec_sz> wordmap;
  for (vec_sz ct = 0; ct < N; ct++) {
    if (wordmap.find(words[ct]) == wordmap.end()) {
      wordmap[words[ct]] = 1;
    }
    else {
      wordmap[words[ct]]++;
    }
  }
  // Report
  for (unordered_map<string,vec_sz>::const_iterator iter = wordmap.begin();iter != wordmap.end(); iter++) {
    cout << "The word " << iter->first << " appears " << iter->second << " times." << endl;
  }


  return 0;
}
