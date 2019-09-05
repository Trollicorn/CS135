#include <iostream>

int smaller(int a, int b){
	//returns the smallest of two given integers
	return a < b ? a : b;
}


int main(){
	std::cout << "enter first number: ";
	int a, b;
	std::cin >> a;
	std::cout << "enter second number: ";
	std::cin >> b;
	std::cout << std::endl << "the smaller of the two is " << smaller(a,b) << std::endl;
	return 0;
}
