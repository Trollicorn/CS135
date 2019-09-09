#include <iostream>

int main(){
	std::cout << "enter lower bound: ";
	int L;
	std::cin >> L;
	std::cout << "enter upper bound: ";
	int U;
	std::cin >> U;
	std::cout << std::endl;
	for (int i = L; i < U; i++){
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}
