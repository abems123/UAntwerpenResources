#include <ostream>

class Integer {
  int m_val;

public:
  Integer();
  Integer(int i);

  Integer(const Integer &that);

  Integer &operator=(const Integer &that);
  Integer operator+(const Integer &that) const;
  Integer operator-(const Integer &that) const;
  Integer operator*(const Integer &that) const;
  Integer operator/(const Integer &that) const;
  Integer operator%(const Integer &that) const;

  Integer &operator+=(const Integer &that);
  Integer &operator-=(const Integer &that);
  Integer &operator/=(const Integer &that);
  Integer &operator*=(const Integer &that);
  Integer &operator%=(const Integer &that);

  Integer &operator++();
  Integer &operator++(int);
  Integer &operator--();
  Integer &operator--(int);

  Integer &twice();

  Integer operator+();
  Integer operator-();

  inline bool operator==(const Integer &that) { return m_val == that.m_val; }
  inline bool operator!=(const Integer &that) { return m_val != that.m_val; }
  inline bool operator<(const Integer &that) { return m_val < that.m_val; }
  inline bool operator>(const Integer &that) { return m_val > that.m_val; }
  inline bool operator<=(const Integer &that) { return m_val <= that.m_val; }
  inline bool operator>=(const Integer &that) { return m_val >= that.m_val; }

  inline int getValue() const { return m_val; }

  friend std::ostream &operator<<(std::ostream &out, const Integer &i);
};
