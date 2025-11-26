#include "Polynomial.h"
#include <cmath>
#include <iostream>
#include <vector>

Polynomial::Polynomial(std::vector<double> c) : coefficients(c) {
  for (auto it = coefficients.end() - 1; it != coefficients.begin();) {
    if (*it >= -0.0001 && *it <= 0.0001) {
      coefficients.erase(it);
      --it;
    } else {
      break;
    }
  }
}

double Polynomial::apply(double x) {
  double result = 0;

  for (int i = 0, n = coefficients.size(); i < n; i++) {
    result += coefficients[i] * std::pow(x, i);
  }

  return result;
}
Polynomial Polynomial::operator+(Polynomial &that) {
  Polynomial biggest =
      (coefficients.size() < that.coefficients.size()) ? that : *this;
  Polynomial smallest =
      coefficients.size() < that.coefficients.size() ? *this : that;

  for (int i = 0, n = smallest.coefficients.size(); i < n; i++) {
    biggest.coefficients[i] += smallest.coefficients[i];
  }

  return biggest;
}

Polynomial Polynomial::operator-(Polynomial &that) {
  Polynomial biggest =
      (coefficients.size() < that.coefficients.size()) ? that : *this;
  Polynomial smallest =
      coefficients.size() < that.coefficients.size() ? *this : that;

  for (int i = 0, n = smallest.coefficients.size(); i < n; i++) {
    biggest.coefficients[i] -= smallest.coefficients[i];
  }

  return biggest;
}

Polynomial Polynomial::operator*(Polynomial &that) {
  std::vector<double> result(coefficients.size() + that.coefficients.size() - 1,
                             0);

  for (int i = 0; i < (int)coefficients.size(); i++) {
    for (int j = 0; j < (int)that.coefficients.size(); j++) {
      result[i + j] += coefficients[i] * that.coefficients[j];
    }
  }

  return Polynomial(result);
}

void Polynomial::derive() {
  for (int i = 0, n = coefficients.size(); i < n; i++) {
    coefficients[i] *= i;
  }
  coefficients.erase(coefficients.begin());
}

void Polynomial::print() {
  for (int i = 0, n = coefficients.size(); i < n; i++) {
    std::cout << coefficients[i] << " x^" << i;
    if (i != n - 1)
      std::cout << " + ";
  }
  std::cout << std::endl;
}
