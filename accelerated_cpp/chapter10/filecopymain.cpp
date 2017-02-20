#include <fstream>
#include <string>



int main(int argc, char** argv) {
  
  int fail_count = 0;

  std::ifstream infile("in");
  std::ofstream outfile("out");

  std::string s;

  while (getline(infile,s)) {
    outfile << s << std::endl;
  }


  return fail_count;
}
