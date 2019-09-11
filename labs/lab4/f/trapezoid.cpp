#include <iostream>

int main(){

	int width, height;
	std::cout << "input width: ";
	std::cin >> width;
	std::cout << "input height: ";
	std::cin >> height;
	
	std::cout << "shape:\n";

	int stars = width;
	for (int r = 0; r < height; r++){
		for (int c = 0; c < width; c++){
			std::cout << (c >= r && c <= width - r - 1? "*" : " ");
		}

		std::cout << "\n";
	}

	return 0;

}
