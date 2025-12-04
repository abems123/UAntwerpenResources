#include "Base.h"
#include <iostream>

using namespace std;

Base::Base() { cout << "Base::Base()" << endl; }

Base::Base(const Base &) { cout << "Base::Base(const Base&)" << endl; }
