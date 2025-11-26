#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <algorithm>
#include <vector>

class Polynomial {
  std::vector<double> coefficients{0};

public:
  Polynomial(std::vector<double> c);

  double apply(double x);
  void derive();

  void print();

  Polynomial operator+(Polynomial &that);
  Polynomial operator-(Polynomial &that);
  Polynomial operator*(Polynomial &that);
};

#endif
