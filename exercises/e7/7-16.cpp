//Mohammed Uddin
#include <iostream>
#include <cmath>

struct Point{
	double x;
	double y;
};

double distance(Point a, Point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int main(){
	Point c;
	c.x = 3.0;
	c.y = 4.0;
	Point d;
	d.x = 0.0;
	d.y = 0.0;
	std::cout << distance(c,d) << '\n';
}
