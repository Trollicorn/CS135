//Mohammed Uddin

#include <iostream>
using namespace std;

int smaller(int a, int b){
	return a < b ? a : b;
}


int main(){
	cout << "enter first number: ";
	int a, b;
	cin >> a;
	cout << "enter second number: ";
	cin >> b;
	cout << endl << endl << "the smaller of the two is " << smaller(a,b) << endl;
	return 0;
}
