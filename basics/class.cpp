#include <iostream>

class Circle {
private:
  double radius;

public:
  Circle();
  Circle(int);
  Circle(Circle const &);
  ~Circle(){};
  void setRadius(double r);
  double getRadius();
};

int main() {
  Circle c1;
  Circle c2(10);
  c1.setRadius(69);
  std::cout << c1.getRadius() << std::endl;
}

void Circle ::setRadius(double r) { radius = r; }

double Circle ::getRadius() { return radius; }

Circle ::Circle() { radius = 0; }

Circle ::Circle(int r) { radius = r; }

Circle ::Circle(Circle const &o) { radius = o.radius; }
