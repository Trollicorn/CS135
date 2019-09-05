#include <iostream>

int main() {
	int s;
	int sum = 0;
	while (std::cin >> s) {
		sum += s;
	}
	std::cout << sum << std::endl;
	return 0;
}
