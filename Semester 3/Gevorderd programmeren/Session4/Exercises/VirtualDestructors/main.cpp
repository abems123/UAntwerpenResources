#include <iostream>

class Base {
public:
  Base(int value) : m_value(new int(value)) {}
  virtual ~Base() {
    std::cout << "Base::~Base called" << std::endl;
    delete m_value;
  }

private:
  int *m_value;
};

class Derived : public Base {
public:
  Derived(int base_value, int derived_value)
      : Base(base_value), m_derived_value(new int(derived_value)) {}
  ~Derived() {
    std::cout << "Derived::~Derived called, ";
    delete m_derived_value;
  }

private:
  int *m_derived_value;
};

int main() {
  // your code here.

  // If we don't add virtual before the Base destructor, Derived destructor
  // won't get called
  Base *b = new Derived(3, 5);
  delete b;

  return 0;
}
