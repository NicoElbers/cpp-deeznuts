#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> iptr1 = std::make_unique<int>(42);
  int *iptr2 = new int;

  delete iptr2;
  // iptr1.reset();

  std::cout << "trying 1" << std::endl;
  std::cout << iptr2 << std::endl;
  std::cout << "trying 2" << std::endl;
  std::cout << *iptr2 << std::endl;
  return 0;
}
