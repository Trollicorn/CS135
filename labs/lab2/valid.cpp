#include <iostream>

int main(){
	std::cout << "input valid integer: ";
	int num;
	std::cin >> num;
	while (num < 1 || num > 99){
		std::cout << "re-enter: ";
		std::cin >> num;
	}
	std::cout << "number squared is " << num*num << std::endl;
	return 0;
}
