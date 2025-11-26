#include "Integer.h"

Integer::Integer() : m_val(0) {}

Integer::Integer(int i) : m_val(i) {}

Integer::Integer(const Integer &that) : m_val(that.m_val) {}

Integer &Integer::operator=(const Integer &that) {
  if (this != &that) {
    this->m_val = that.m_val;
  }
  return *this;
}

Integer &Integer::operator+=(const Integer &that) {
  m_val += that.m_val;
  return *this;
}

Integer &Integer::operator-=(const Integer &that) {
  m_val -= that.m_val;
  return *this;
}

Integer &Integer::operator/=(const Integer &that) {
  m_val /= that.m_val;
  return *this;
}
Integer &Integer::operator*=(const Integer &that) {
  m_val *= that.m_val;
  return *this;
}

Integer &Integer::operator%=(const Integer &that) {
  m_val %= that.m_val;
  return *this;
}

Integer &Integer::twice() {
  this->m_val *= 2;
  return *this;
}

Integer Integer::operator+(const Integer &that) const {
  return Integer(this->m_val + that.m_val);
}

Integer Integer::operator-(const Integer &that) const {
  return Integer(this->m_val - that.m_val);
}

Integer &Integer::operator++() {
  this->m_val++;
  return *this;
}

Integer &Integer::operator++(int) {
  Integer &original = *this;
  this->m_val++;
  return original;
}

Integer &Integer::operator--() {
  this->m_val--;
  return *this;
}

Integer &Integer::operator--(int) {
  Integer &original = *this;
  this->m_val--;
  return original;
}

Integer Integer::operator*(const Integer &that) const {
  return Integer(this->m_val * that.m_val);
}

Integer Integer::operator/(const Integer &that) const {
  return Integer(m_val / that.m_val);
}

Integer Integer::operator%(const Integer &that) const {
  return Integer(m_val % that.m_val);
}

Integer Integer::operator+() { return *this; }

Integer Integer::operator-() {
  m_val *= -1;
  return *this;
}
