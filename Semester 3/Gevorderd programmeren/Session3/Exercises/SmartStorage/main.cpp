// main.cpp
#include "A.h"
#include "B.h"
#include <memory>

int main() {
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>(a);
  a->setB(b);
  a->print();
}
