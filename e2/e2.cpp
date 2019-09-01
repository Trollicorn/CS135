#include <iostream>
using namespace std;
//Mohammed Uddin
int price_per_100(int price, int efficiency){
	return 100 * price/efficiency;
}

int miles_possible(int fuel, int efficiency){
	return fuel * efficiency;
}


int main(){
	cout << "enter number of gallons of gas in tank:" << endl;
	int fuel;
	cin >> fuel;
	cout << "enter fuel efficiency (miles per gallon):" << endl;
	int efficiency;
	cin >> efficiency;
	cout << "enter price per gallon of gas:" << endl;
	int price;
	cin >> price;
	cout << "going 100 miles will cost you " << price_per_100(price,efficiency) << endl;
	cout << "you can drive for " << miles_possible(fuel,efficiency) << " more miles" << endl;
	return 0;

}
