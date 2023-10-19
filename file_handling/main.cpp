#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::fstream fout;
  fout.open("test.log", std::ios::trunc | std::ios::in | std::ios::out);

  char str[] = "this is an output log file!!";

  fout << str << std::endl;

  fout.close();

  return 0;
}
