#include "Time.h"
#include <iostream>

int main() {
  Time t1(10, 59, 55);
  t1.print();
  Time t2;
  t2.print();
  t2.setTime(5, 9, 25);
  t2.print();

  std::cout << t1.equals(t2) << std::endl;
  std::cout << t1.equals(Time(10, 59, 55));

  std::cout << "this is the new current one" << std::endl;

  return 0;
}
