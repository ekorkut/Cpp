#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> words;
  std::string s;
  while(std::cin >> s) {
    words.push_back(s);
  }
  std::vector<std::string>::size_type N = words.size();
  std::cout << "Finished reading " << words.size() << " words" << std::endl;

  // N^2 solution, a better solution exists leveraging map data type


  // Flags to keep track of encountered things
  bool* visited = new bool[N];
  for (int ct = 0; ct < N; ct++){
    visited[ct] = false;
  }
  
  for (int ct = 0; ct < N; ct++){
    if (!visited[ct]) {
      std::string s = words[ct];
      int count = 1;
      for (int ctin = ct+1; ctin < N; ctin++) {
        if (s == words[ctin]) {
          visited[ctin] = true;
          count++;
        }
      }
      std::cout << words[ct] << " appears " << count << " times." << std::endl;
      
    }
  }
  
  delete[] visited;
  return 0;
}
