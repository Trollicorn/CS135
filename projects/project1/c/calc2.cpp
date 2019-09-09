/*
Author: Mohammed Uddin
Course: CSCI 136
Instructor: Maryash
Assignment: Project 1B

reads multiple sequences of one or more non-negative integers in a file to be added or subtracted with each sequence seperated by semicolons and reports the value of each computation
*/

#include <iostream>

int main() {
	char c;
	int sum = 0; //tracks overall value
	int curr = 0; //tracks current number
	int o = 1; //sign (positive/negative)
	while (std::cin >> c) {
		if (c == ';'){
			sum += curr * o;
			std::cout << sum << std::endl;
			sum = 0;
			curr = 0;
			o = 1;
		}
		else if (isdigit(c)){ //update current number
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
	
	return 0;
}
