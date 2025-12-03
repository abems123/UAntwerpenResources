// A.h
#ifndef EX_3_1_A
#define EX_3_1_A

#include <memory>

class B;

class A {
public:
  A() = default;
  ~A();
  void setB(std::shared_ptr<B> b);
  void print() const;

private:
  std::weak_ptr<B> m_b;
};

#endif // EX_3_1_A
