from __future__ import division

class complex:
  def __init__(self, norm = 0, imag = 0):
    self.norm = norm
    self.imag = imag

  def __add__(self, other):
    if isinstance(other, int):
      return complex(self.norm + other, self.imag)
    elif isinstance(other, complex):
      return complex(self.norm + other.norm, self.imag + other.imag)
    else:
      raise TypeError
  
  def __sub__(self, other):
    if isinstance(other, int):
      return complex(self.norm - other, self.imag)
    elif isinstance(other, complex):
      return complex(self.norm - other.norm, self.imag - other.imag)
    else:
      raise TypeError

  def __mul__(self, other):
    if isinstance(other, int):
      return complex(self.norm * other, self.imag * other)
    elif isinstance(other, complex):
      return complex((self.norm * other.norm) - (self.imag * other.imag), (self.norm * other.imag) + (self.imag * other.norm))
    else:
      raise TypeError

  def __truediv__(self, other):
    if isinstance(other, int):
      return complex(round(self.norm / other, 1), round(self.imag / other, 1))
    elif isinstance(other, complex):
      denom = ((other.norm * other.norm) + (other.imag * other.imag))
      first_num = ((self.norm * other.norm) + (other.imag * other.imag))
      second_num = ((self.imag * other.norm) - (self.norm * other.imag))
      return complex(round(first_num / denom, 1), round(second_num / denom, 1))
    else:
      raise TypeError

  def __floordiv__(self, other):
    if isinstance(other, int):
      return complex(round(self.norm / other, 1), round(self.imag / other, 1))
    elif isinstance(other, complex):
      denom = ((other.norm * other.norm) + (other.imag * other.imag))
      first_num = ((self.norm * other.norm) + (self.imag * other.imag))
      second_num = ((self.imag * other.norm) - (self.norm * other.imag))
      return complex(round(first_num / denom, 1), round(second_num / denom, 1))
    else:
      raise TypeError

  def __div__(self, other):
    if isinstance(other, int):
      return complex(round(self.norm / other, 1), round(self.imag / other, 1))
    elif isinstance(other, complex):
      denom = ((other.norm * other.norm) + (other.imag * other.imag))
      first_num = ((self.norm * other.norm) + (self.imag * other.imag))
      second_num = ((self.imag * other.norm) - (self.norm * other.imag))
      return complex(round(first_num / denom, 1), round(second_num / denom, 1))
    else:
      raise TypeError

  def __radd__(self, other):
    return (self + other)

  def __rsub__(self, other):
    return (complex(other) - self)

  def __rmul__(self, other):
    return (self * other)

  def __rtruediv__(self, other):
    return (complex(other) / self)

  def __rfloordiv__(self, other):
    return (complex(other) / self)

  def __rdiv__(self, other):
    return (complex(other) / self)

  def __float__(self):
    return (float(self.norm) / self.imag)

  def __int__(self):
    return (self.norm / self.imag)

  def __str__(self):
    return ('(' + str(self.norm) + ' + ' + str(self.imag) + "i)")


x = complex(1, 2)
y = complex(3, 4)

print('%s + %s = %s' % (x, y, x + y))
print('%s - %s = %s' % (x, y, x - y))
print('%s * %s = %s' % (x, y, x * y))
print('%s / %s = %s' % (x, y, x / y))
print()
print('%s + %i = %s' % (x, 5, x + 5))
print('%s - %i = %s' % (x, 5, x - 5))
print('%s * %i = %s' % (x, 5, x * 5))
print('%s / %i = %s' % (x, 5, x / 5))
print()
print('%i + %s = %s' % (5, x, 5 + x))
print('%i - %s = %s' % (5, x, 5 - x))
print('%i * %s = %s' % (5, x, 5 * x))
print('%i / %s = %s' % (5, x, 5 / x))