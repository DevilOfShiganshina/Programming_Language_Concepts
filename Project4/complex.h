#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

struct complex {
  complex(int = 0, int = 1);

  complex operator+(const complex &) const;
  complex operator-(const complex &) const;
  complex operator*(const complex &) const;
  complex operator/(const complex &) const;

  complex operator+(int) const;
  complex operator-(int) const;
  complex operator*(int) const;
  complex operator/(int) const;

  friend complex operator+(int, const complex &);
  friend complex operator-(int, const complex &);
  friend complex operator*(int, const complex &);
  friend complex operator/(int, const complex &);

  friend std::ostream &operator<<(std::ostream &, const complex &);

private:
  int norm;
  int imag;
};

#endif