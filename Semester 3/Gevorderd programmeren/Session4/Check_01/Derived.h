#include "Base.h"

class Derived : public Base {
public:
  using Base::Base;

  // Derived(int i) : Base(i) {};
};
