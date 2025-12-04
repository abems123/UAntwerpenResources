#include "Derived.h"
#include <iostream>

using namespace std;

Derived::Derived() { cout << "Derived::Derived()" << endl; }

Derived::Derived(const Derived &) {
  cout << "Derived::Derived(const Derived&)" << endl;
}
