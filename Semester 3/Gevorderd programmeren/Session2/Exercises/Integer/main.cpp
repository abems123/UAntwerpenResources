#include "Integer.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Integer &i) {
  out << i.m_val;
  return out;
}

int main() {
  // Test default constructor
  Integer a;
  std::cout << "Default constructor: a = " << a << std::endl;

  // Test parameterized constructor
  Integer b(5);
  std::cout << "Parameterized constructor: b = " << b << std::endl;

  // Test copy constructor
  Integer c(b);
  std::cout << "Copy constructor: c = " << c << std::endl;

  // Test assignment operator
  a = c;
  std::cout << "Assignment operator: a = " << a << std::endl;

  // Test arithmetic operators
  Integer x(10);
  Integer y(5);

  Integer sum = x + y;
  Integer difference = x - y;
  Integer product = x * y;
  Integer quotient = x / y;
  Integer remainder = x % y;

  std::cout << "x + y = " << sum << std::endl;
  std::cout << "x - y = " << difference << std::endl;
  std::cout << "x * y = " << product << std::endl;
  std::cout << "x / y = " << quotient << std::endl;
  std::cout << "x % y = " << remainder << std::endl;

  // Test compound assignment operators
  x += y;
  std::cout << "x += y: x = " << x << std::endl;

  x -= y;
  std::cout << "x -= y: x = " << x << std::endl;

  x *= y;
  std::cout << "x *= y: x = " << x << std::endl;

  x /= y;
  std::cout << "x /= y: x = " << x << std::endl;

  x %= y;
  std::cout << "x %= y: x = " << x << std::endl;

  // Test unary operators
  Integer z(-5);
  Integer pos_z = +z;
  Integer neg_z = -z;

  std::cout << "+z = " << pos_z << std::endl;
  std::cout << "-z = " << neg_z << std::endl;

  // Test increment and decrement operators
  Integer n(7);
  Integer post_inc_n = n++;
  Integer pre_inc_n = ++n;
  Integer post_dec_n = n--;
  Integer pre_dec_n = --n;

  std::cout << "n++ = " << post_inc_n << ", n = " << n << std::endl;
  std::cout << "++n = " << pre_inc_n << ", n = " << n << std::endl;
  std::cout << "n-- = " << post_dec_n << ", n = " << n << std::endl;
  std::cout << "--n = " << pre_dec_n << ", n = " << n << std::endl;

  // // Test comparison operators
  Integer m1(10);
  Integer m2(5);

  if (m1 == m2) {
    std::cout << "m1 == m2" << std::endl;
  }
  if (m1 != m2) {
    std::cout << "m1 != m2" << std::endl;
  }
  if (m1 < m2) {
    std::cout << "m1 < m2" << std::endl;
  }
  if (m1 > m2) {
    std::cout << "m1 > m2" << std::endl;
  }
  if (m1 <= m2) {
    std::cout << "m1 <= m2" << std::endl;
  }
  if (m1 >= m2) {
    std::cout << "m1 >= m2" << std::endl;
  }

  // Test the twice function
  Integer i(2);
  i.twice().twice().twice();
  std::cout << "i.twice().twice().twice(): i = " << i << std::endl;

  // Test using getValue() with a const Integer
  const Integer j = 6;
  std::cout << "j.getValue(): " << j.getValue() << std::endl;

  return 0;
}
