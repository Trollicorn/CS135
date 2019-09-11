#include <iostream>

int main(){

	int width, height;
	std::cout << "input width: ";
	std::cin >> width;
	std::cout << "input height: ";
	std::cin >> height;
	
	std::cout << "\nshape:\n";

	for (int r = 0; r < height; r++){
		for (int c = 0; c < width; c++){
			std::cout << (r % 6 < 3 && c % 6 < 3 || r % 6 > 2 && c % 6 > 2 ? "*" : " ");
		}

		std::cout << "\n";
	}

	return 0;

}
