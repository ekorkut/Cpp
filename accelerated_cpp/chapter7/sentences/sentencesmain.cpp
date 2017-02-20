#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "../split.hpp"

using std::vector;
using std::string;
using std::map;

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string,RuleCollection> Grammar;

int nrand(int n) {
  const int bucket_size = RAND_MAX/n;
  int out;
  do {
    out = rand()/bucket_size;
  }
  while(out >=n);
  return out;
}

Grammar read_grammar(std::istream& in) {
  Grammar ret;
  string line;
  while(getline(in,line)) {
    vector<string> words = split(line);

    if (!words.empty()) {
      ret[words[0]].push_back(Rule(words.begin()+1,words.end()));
    }
  }


  return ret;
}

bool bracketed(const string& s) {
  return ((s.size() > 1) && (s[0] == '<') && s[s.size()-1] == '>');
}

void gen_aux(const Grammar&g, const string& word,vector<string>& out) {
  if (!bracketed(word)) {
      out.push_back(word);
      return;
    }
  else {
    // Rule, expand it
    // Locate the rule
    Grammar::const_iterator it = g.find(word);
    if (it == g.end()) {
      throw std::logic_error("empty rule");
    }
    else {
      const RuleCollection& rc = it->second;
      // Pick one at random
      const Rule& r = rc[nrand(rc.size())];
      // Recurse with elements of the rule
      for(Rule::const_iterator itr = r.begin();itr != r.end(); itr++)
	gen_aux(g,*itr,out);
    }
  }
}

vector<string> gen_sentence(const Grammar& g) {
  vector<string> ret;
  gen_aux(g,"<sentence>",ret);
  return ret;

}

int main() {
  Grammar g = read_grammar(std::cin);
  vector<string> out = gen_sentence(g);
  // Write out the sentence
  std::cout << "The random sentence is: " << std::endl; 
  for(vector<string>::const_iterator it = out.begin();it != out.end(); it++){
    std::cout << *it << " ";
  }
  return 0;

}
