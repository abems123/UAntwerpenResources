#include <ostream>

class Integer {
  int m_val;

  public:
    Integer();
    explicit Integer(int i);

    Integer(const Integer& that);

    Integer& operator=(const Integer& that);
    Integer operator+(const Integer& that) const;
    Integer operator-(const Integer& that) const;

    Integer& operator+=(const Integer& that);
    
    Integer& operator++();
    Integer operator++(int);

    Integer& twice();

    friend std::ostream& operator<<(std::ostream& out, const Integer& i);
};


