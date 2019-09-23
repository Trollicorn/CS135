//Mohammed Uddin
#include <iostream>

int main(){
	std::cout << "input sequence: ";
	int a,b,c;
	std::cin >> a >> b >> c;
	std::cout << (a < b && b < c ? "increasing" : a > b && b > c ? "decreasing" : "neither") << '\n';
	return 0;
}
