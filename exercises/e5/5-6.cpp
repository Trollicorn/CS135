#include <iostream>

std::string middle(std::string str){
	return str.length() ? str.substr((str.length()-1)/2, (str.length()+1)%2+1) : "";
}

int main(){
	std::cout << middle("mid") << '\n'; //i
	std::cout << middle("middle") << '\n'; //dd
	std::cout << middle("abcdefghijkl") << '\n'; //fg
	std::cout << middle("") << '\n'; //\n
}
