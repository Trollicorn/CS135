/*
Author: Mohammed Uddin
Course: CSCI 136
Instructor: Maryash
Assignment: Project 1B

reads a sequence of one or more non-negative integers in a file to be added or subtracted and reports the value of the computation
*/

#include <iostream>

int main() {
	char c;
	int sum = 0; //tracks overall value
	int curr = 0; //tracks current number
	int o = 1; //sign (positive/negative)
	while (std::cin >> c) {
		if (isdigit(c)){ //update current number
			curr = curr*10 + (c - '0');
		}
		else{ //number is finished, add/subtract its value to sum
			sum += curr * o;
			curr = 0;
			if (c == '+'){
				o = 1;
			}
			if (c == '-'){
				o = -1;
			}
		}
	}
	sum += curr * o;
	std::cout << sum << std::endl;
	return 0;
}
