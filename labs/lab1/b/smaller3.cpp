#include <iostream>

int smaller(int a, int b){
	//returns the smallest of two given integers
	return a < b ? a : b;
}

int smaller3(int a, int b, int c){
	//returns the smallest of three given integers
	return smaller(smaller(a,b),c);
}

int main(){
	std::cout << "enter first number: ";
	int a, b, c;
	std::cin >> a;
	std::cout << "enter second number: ";
	std::cin >> b;
	std::cout << "enter third number: ";
	std::cin >> c;
	std::cout << std::endl << "the smaller of the three is " << smaller3(a,b,c) << std::endl;
	return 0;
}
