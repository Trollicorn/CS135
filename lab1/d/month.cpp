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

int days_in(int year, int month){
	if (month == 2){
		return is_leap(year) ? 29 : 28;
	}
	return 30 + (month + ((month > 7) ? 1 : 0)) % 2; 
	//1 3 5 7 8 10 12 is 31
	//4 6 9 11 is 30 
}

int main(){
	std::cout << "enter year: ";
	int year;
	std::cin >> year;
	std:: cout << "enter month: ";
	int month;
	std::cin >> month;
	std::cout << std::endl << days_in(year,month) << " days"  << std::endl;
	return 0;
}
