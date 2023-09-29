#include <iostream>
#include <ostream>

int main() {
  int favNumber;
  int more;
  std::cout << "What is your fav num?" << std::endl << "> ";
  std::cin >> favNumber >> more;
  std::cout << "wOw, my favorite number is not " << favNumber << std::endl;
  return 0;
}
