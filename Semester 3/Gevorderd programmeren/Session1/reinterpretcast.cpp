#include <iostream>

using namespace std;

int main(){
  
// Suppose we have a good old double
double foo = 1.234;
// Let's make a pointer to that double which pretends to point to an integer
int* bar = reinterpret_cast<int*>(&foo);
// Look at the garbage!
cout << (*bar) << endl;
}
