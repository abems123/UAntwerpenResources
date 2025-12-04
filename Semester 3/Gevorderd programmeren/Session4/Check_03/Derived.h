#include "Base.h"

class Derived : public Base {
public:
  virtual void
  print_info(); // NOTE: 'virtual' is optional here, 'override' might be better.
};
