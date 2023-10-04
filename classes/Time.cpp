#include "Time.h"
#include <iomanip>
#include <iostream>

Time ::Time(const int h, const int m, const int s) {
  hour = h;
  minute = m;
  second = s;
}

void Time ::setTime(const int h, const int m, const int s) {
  hour = h;
  minute = m;
  second = s;
}

void Time ::print() const {
  std::cout << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2)
            << std::setfill('0') << minute << ":" << std::setw(2)
            << std::setfill('0') << second << std::endl;
}

bool Time ::equals(const Time &o) {
  if (hour != o.hour || minute != o.minute || second != o.second)
    return false;
  return true;
}
