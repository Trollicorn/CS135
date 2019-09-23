//Mohammed Uddin
#include <iostream>

int main(){
	int n;
	std::cin >> n;
	std::cout << (n > 0 ? "positive" : n == 0 ? "zero" : "negative") << '\n';
	return 0;
}
