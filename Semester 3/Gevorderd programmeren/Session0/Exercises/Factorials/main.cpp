#include <iostream>
#include "factorials.h"

int main()
{
	int n;

	do{std::cout << "Enter an integer: ";std::cin >> n;}while (n<0);
std::cout << "Recursive : " << getFactorialRec(n) << std::endl;
std::cout << "Iterative : " << getFactorialIter(n) << std::endl;
}
