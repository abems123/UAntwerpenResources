#include <iostream>
#include <string>

using namespace std;

string toBinary(int i){
	if (i == 0)
	{return "0";}
	if (i == 1)
	{return "1";}

	return toBinary(i/2) + to_string(i%2);
}
int main(){
	int n;
	cout<< "Enter a number : ";cin >> n;
	std::cout << toBinary(n) << std::endl;
}
