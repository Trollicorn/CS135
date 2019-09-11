#include <iostream>

int main(){

	int size;
	std::cout << "input size: ";
	std::cin >> size;
	
	std::cout << "shape:\n";

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			std::cout << (i == j ? "*" : " ");
		}
		std::cout << "\n";
	}

	return 0;

}
