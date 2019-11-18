//Mohammed Uddin
#include <iostream>
#include <cmath>

struct Point{
	double x;
	double y;
};

struct Triangle{
	Point A;
	Point B;
	Point C;
};

double distance(Point a, Point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double perimeter(Triangle t){
	return distance(t.A,t.B)+distance(t.B,t.C)+distance(t.C,t.A);
}

int main(){
	Point c;
	c.x = 3.0;
	c.y = 0.0;
	Point d;
	d.x = 0.0;
	d.y = 0.0;
	Point e;
	e.x = 0.0;
	e.y = 4.0;
	Triangle t;
	t.A = c;
	t.B = d;
	t.C = e;
	std::cout << "A: (" << c.x << ',' << c.y << ")\n";
	std::cout << "B: (" << d.x << ',' << d.y << ")\n";
	std::cout << "C: (" << e.x << ',' << e.y << ")\n";
	std::cout << "Perimeter of triangle ABC: " << perimeter(t) << '\n';
}
