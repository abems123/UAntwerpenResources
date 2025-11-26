#include "Polynomial.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

  std::vector<double> c = {9.0, 1.0, 2.0, 0, 0};
  Polynomial p(c);

  p.print();

  std::cout << p.apply(3.0) << std::endl;

  p.derive();
  p.print();

  // ik ga de rest niet doen, ik heb hier geen tijd voor
  return 0;
}
