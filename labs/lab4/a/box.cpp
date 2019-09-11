#include <iostream>

int main(){

	int width, height;
	std::cout << "input width: ";
	std::cin >> width;
	std::cout << "input height: ";
	std::cin >> height;
	
	std::cout << "shape:\n";

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			std::cout << "*";
		}
		std::cout << "\n";
	}

	return 0;

}
