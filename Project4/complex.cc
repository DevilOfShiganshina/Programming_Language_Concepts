#include <iostream>
#include "complex.h"

complex::complex(int norm, int imag) : norm(norm), imag(imag) {}

complex complex::operator+(const complex &second) const {
  return complex(norm + second.norm, imag + second.imag);
}

complex complex::operator+(int x) const {
  return complex(norm + x, imag);
}

complex complex::operator-(const complex &second) const {
  return complex(norm - second.norm, imag - second.imag);
}

complex complex::operator-(int x) const {
  return complex(norm - x, imag);
}

complex complex::operator*(const complex &second) const {
  return complex((norm * second.norm) - (imag * second.imag), (norm * second.imag)+(imag * second.norm));
}

complex complex::operator*(int x) const {
  return complex(norm * x, imag * x);
}

complex complex::operator/(const complex &second) const {
  int denom = ((second.norm * second.norm) + (second.imag * second.imag));
  return complex(((norm * second.norm) + (imag * second.imag))/ denom, ((imag * second.norm) - (norm * second.imag)) / denom);
}

complex complex::operator/(int x) const {
  return complex(norm / x, imag / x);
}

complex operator+(int x, const complex &second) {
  return (second + x);
}

complex operator-(int x, const complex &second) {
  return (complex(x) - second);
}

complex operator*(int x, const complex &second) {
  return (second * x);
}

complex operator/(int x, const complex &second) {
  return (complex(x) / second);
}

std::ostream &operator<<(std::ostream &out, const complex &second) {
  out << "(" << second.norm << " + " << second.imag << "i)";
  return out;
}