//Mohammed Uddin
#include <iostream>
class Rectangle{
	private:
		float width;
		float height;
	public:
		Rectangle(float w, float h){
			width = w;
			height = h;
		}
		float get_perimeter(){
			return 2*width+2*height;
		}
		float get_area(){
			return width*height;
		}
		void resize(float f){
			width *=f;
			height *=f;
		}
};

int main(){
	Rectangle r(4.0,5.0);
	std::cout << r.get_perimeter() << ' ' << r.get_area() << '\n';
	r.resize(2.0);
	std::cout << r.get_perimeter() << ' ' << r.get_area() << '\n';
}
