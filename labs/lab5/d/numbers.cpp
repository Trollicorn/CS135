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

int countPrimes(int a, int b){
	int c = 0;
	for (int i = a; i <= b; i++){
		if (isPrime(i)){
			c++;
		}
	}
	return c;
}

int main(){
	std::cout << countPrimes(2,3) << '\n';
	std::cout << countPrimes(2,10) << '\n';
	std::cout << countPrimes(8,1003) << '\n';
}
