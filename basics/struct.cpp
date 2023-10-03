#include <iostream>

struct Student {
  int studentID;
  char name[80];
  float marks;
};

int main() {
  Student s1, s2;

  std::cin >> s1.studentID >> s1.name >> s1.marks;
  std::cout << std::endl
            << s1.studentID << std::endl
            << s1.name << std::endl
            << s1.marks;

  s2 = {6969, "Bob", 8};
  std::cout << std::endl
            << s2.studentID << std::endl
            << s2.name << std::endl
            << s2.marks;

  Student s3 = s2;
  std::cout << std::endl
            << s3.studentID << std::endl
            << s3.name << std::endl
            << s3.marks;

  return 0;
}
