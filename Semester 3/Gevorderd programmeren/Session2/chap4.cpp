#include <iostream>

using namespace std;

class Coordinate {
float _x, _y;
public:
Coordinate() : _x{0}, _y{0} { cout << "default constructor" << endl; };
explicit Coordinate(float x, float y) : _x{x}, _y{y} { cout << "constructor" << endl; };
Coordinate(const Coordinate& other) : _x{other._x}, _y{other._y} { cout << "copy constructor" << endl; };
Coordinate& operator=(const Coordinate& other) {
cout << "assignment" << endl;
_x = other._x;
_y = other._y;
return *this;
}
~Coordinate() {cout << "destructor" << endl; };
};

int main()
{
  Coordinate c_1 = Coordinate{1.0,2.0};
  Coordinate c_2;

  c_2 = c_1;

}
