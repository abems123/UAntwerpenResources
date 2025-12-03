// A.cpp
#include "A.h"
#include "B.h"

#include <iostream>

void A::setB(std::shared_ptr<B> b) { m_b = std::move(b); }

A::~A() { std::cout << "A deleted!" << std::endl; }

void A::print() const {
  std::cout << "I'm an A! With:" << std::endl;

  if (auto l = m_b.lock())
    m_b.lock()->print();
}
