// B.h
#ifndef EX_3_1_B
#define EX_3_1_B

#include "A.h"
#include <memory>

class B {
public:
  explicit B(std::shared_ptr<A> a);
  ~B();
  void print() const;

private:
  std::shared_ptr<A> m_a;
};

#endif // EX_3_1_B
