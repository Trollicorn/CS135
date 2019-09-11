#include <iostream>

int main(){

	int width, height;
	std::cout << "input width: ";
	std::cin >> width;
	std::cout << "input height: ";
	std::cin >> height;

	if (2*height > width){
		std::cout << "\nimposible shape\n";
		return 1;
	}	
	
	std::cout << "\nshape:\n";


	for (int r = 0; r < height; r++){
		for (int c = 0; c < width; c++){
			std::cout << (c >= r && c <= width - r - 1? "*" : " ");
		}

		std::cout << "\n";
	}

	return 0;

}
