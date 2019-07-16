#include <iostream>
#include "complex.h"

int main() {

  complex x(1, 2);
  complex y(3, 4);

  std::cout << x << " + " << y << " = " << x + y << std::endl;
  std::cout << x << " - " << y << " = " << x - y << std::endl;
  std::cout << x << " * " << y << " = " << x * y << std::endl;
  std::cout << x << " / " << y << " = " << x / y << std::endl << std::endl;

  std::cout << x << " + " << 5 << " = " << x + 5 << std::endl;
  std::cout << x << " - " << 5 << " = " << x - 5 << std::endl;
  std::cout << x << " * " << 5 << " = " << x * 5 << std::endl;
  std::cout << x << " / " << 5 << " = " << x / 5 << std::endl << std::endl;

  std::cout << 5 << " + " << x << " = " << 5 + x << std::endl;
  std::cout << 5 << " - " << x << " = " << 5 - x << std::endl;
  std::cout << 5 << " * " << x << " = " << 5 * x << std::endl;
  std::cout << 5 << " / " << x << " = " << 5 / x << std::endl;

  return 0;
}