#include <iostream>

int main(){
	std::string str;
	std::cout << "input: ";
	std::getline(std::cin,str);
	for (int i = 0; i < str.length(); i++){
		std::cout << str[i] << ' ' << (int)str[i] << '\n';
	}
	return 0;
}
