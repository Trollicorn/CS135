//Mohammed Uddin

#include <iostream>
using namespace std;
//Mohammed Uddin
float price_per_100(float price, float efficiency){
	return 100 * price/efficiency;
}

float miles_possible(float fuel, float efficiency){
	return fuel * efficiency;
}


int main(){
	cout << "enter number of gallons of gas in tank:" << endl;
	float fuel;
	cin >> fuel;
	cout << "enter fuel efficiency (miles per gallon):" << endl;
	float efficiency;
	cin >> efficiency;
	cout << "enter price per gallon of gas:" << endl;
	float price;
	cin >> price;
	cout << "going 100 miles will cost you " << price_per_100(price,efficiency) << endl;
	cout << "you can drive for " << miles_possible(fuel,efficiency) << " more miles" << endl;
	return 0;

}
