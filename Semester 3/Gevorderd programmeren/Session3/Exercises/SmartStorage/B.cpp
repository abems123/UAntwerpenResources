// B.cpp
#include "B.h"
#include "A.h"

#include <iostream>

B::B(std::shared_ptr<A> a) : m_a(std::move(a)) {}

B::~B() { std::cout << "B deleted!" << std::endl; }

void B::print() const { std::cout << "a B!" << std::endl; }
