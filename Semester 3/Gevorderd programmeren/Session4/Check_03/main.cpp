#include "Derived.h"

int main(int argc, char *argv[]) {
  Base *b_ptr = new Base;
  Derived *d_ptr = new Derived;
  Base *b_ptr2 = new Derived;
  Base &b_ref = *d_ptr;

  b_ptr->print_info();  // Base::print_info()
  d_ptr->print_info();  // Derived::print_info()
  b_ptr2->print_info(); // Derived::print_info() !!!
  b_ref.print_info();   // Derived::print_info() !!!

  return 0;
}
