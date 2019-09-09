#include <iostream>

int main(){
	int myData[10];
	for (int i = 0; i < 10; i++){
		myData[i] = 1;
	}
	int i = 0;
	int v = 1;
	while (i > -1 && i < 10){
		myData[i] = v;
		for (int i = 0; i < 10; i++){
			std::cout << myData[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "input index: ";
		std::cin >> i;
		std::cout << "input value: ";
		std::cin >> v;
	}
	std::cout << std::endl << "index out of range" << std::endl;
	return 0;
}
