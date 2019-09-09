//Mohammed Uddin
#include <iostream>

int main(){
	std::cout << "input word" << std::endl;
	std::string str;
	std::cin >> str;
	for (int i = 0; i < str.length(); i++){
		std::cout << str[i] << std::endl;
	}
	return 0;
}
