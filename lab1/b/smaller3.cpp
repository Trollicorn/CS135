//Mohammed Uddin

#include <iostream>
using namespace std;

int smaller(int a, int b){
	return a < b ? a : b;
}


int main(){
	cout << "enter first number: ";
	int a, b, c;
	cin >> a;
	cout << "enter second number: ";
	cin >> b;
	cout << "enter third number: ";
	cin >> c;
	cout << endl << endl << "the smaller of the three is " << smaller(smaller(a,b),c) << endl;
	return 0;
}
