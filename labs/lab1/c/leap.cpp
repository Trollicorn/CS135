#include <iostream>

int is_leap(int year){
	//returns whether a given year is a leap year
	return !((year % 4) || (!(year % 100) && (year % 400)));
	//check is year is a multiple of 4
	//if year is not a multiple of 4, returns false
	//if year is a multiple of 4, checks if year is a multiple of 100
	//if year is a multiple of 100, checks if year is a multiple of 400
	//if year is a multiple of 400, returns true, else false
	//if year is not a multiple of 100, returns true
}


int main(){
	std::cout << "enter year: ";
	int year;
	std::cin >> year;
	std::cout << std::endl << (is_leap(year) ? "leap year" : "common year")  << std::endl;
	return 0;
}
