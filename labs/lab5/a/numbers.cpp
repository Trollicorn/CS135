#include <iostream>

bool isDivisibleBy(int n, int d){
	return !(n % d);
}

int main(){
	std::cout << (isDivisibleBy(100,25) ? "true":"false") << '\n';
	std::cout << (isDivisibleBy(35,17) ? "true":"false") << '\n';
}
