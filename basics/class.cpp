#include <iostream>

class Circle {
private:
  double radius;

public:
  void setRadius(double r);
  double getRadius();
};

int main() {
  Circle c1;
  c1.setRadius(69);
  std::cout << c1.getRadius() << std::endl;
}

void Circle ::setRadius(double r) { radius = r; }

double Circle ::getRadius() { return radius; }
