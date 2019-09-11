#include <iostream>

int main(){

	int size;
	std::cout << "input side length: ";
	std::cin >> size;
	
	std::cout << "shape:\n";

	for (int r = 0; r < size; r++){
		for (int c = 0; c < size; c++){
			std::cout << (c >= r ? "*" : " ");
		}
		std::cout << "\n";
	}

	return 0;

}
