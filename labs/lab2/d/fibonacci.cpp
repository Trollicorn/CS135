#include <iostream>

int main(){
	int fib[60];
	fib[0] = 0;
	fib[1] = 1;
	std::cout << "0" << std::endl << "1" << std::endl;
	for (int i = 2; i < 60; i++){
		fib[i] = fib[i-2] + fib[i-1];
		std::cout << fib[i] << std::endl;
	}
	//eventually, the numbers will overload and become negative
	//due to size constraints on the integer type
	return 0;
}
