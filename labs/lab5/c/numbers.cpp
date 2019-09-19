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

int nextPrime(int n){
	int next = n+1;
	while (true){
		if (isPrime(next)){
			return next;
		}
		next++;
	}
}

int main(){
	std::cout << nextPrime(2) << '\n';
	std::cout << nextPrime(3) << '\n';
	std::cout << nextPrime(47) << '\n';
}
