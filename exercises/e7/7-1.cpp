//Mohammed Uddin
#include <iostream>
void sort2(double *p, double *q){
	if (*p > *q){
		double temp = *q;
		*q = *p;
		*p = temp;
	}
}

int main(){
	double x = 8.9;
	double y = 4.5;
	std::cout << x << ' ' << y << '\n';
	sort2(&x,&y);
	std::cout << x << ' ' << y << '\n';
}
