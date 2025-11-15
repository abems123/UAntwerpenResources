#include <iostream>

int mul(int x, int y) {
  if (x == 0 || y == 0)
    return 0;

  static int i{0};
  i++;
  
  if (y == i || -y == i)
    return x;
  
  if ((x > 0 && y > 0) || (x < 0 && y > 0) || i > 1)
    return x + mul(x,y);
  else 
    return -(x + mul(x,y));
}

int main(){
  int x,y;
  std::cin >> x;
  std::cin >> y;

  std::cout << mul(x,y) << std::endl;
}
