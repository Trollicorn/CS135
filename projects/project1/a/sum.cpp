/*
Author: Mohammed Uddin
Course: CSCI 136
Instructor: Maryash
Assignment: Project 1A

reads a sequence of integers in a file and reports their sum
*/

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
