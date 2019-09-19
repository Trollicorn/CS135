#include <iostream>

bool isDivisibleBy(int n, int d){
	return !(n % d);
}

bool isPrime(int n){
	if (n == 2){
		return true;
	}
	for (int i = 2; i < n; i++){
		if (! (n%i)){
			return false;
		}
	}
	return true;
}

int main(){
	std::cout << isPrime(2) << '\n';
	std::cout << isPrime(3) << '\n';
	std::cout << isPrime(56) << '\n';
	std::cout << isPrime(47) << '\n';
}
