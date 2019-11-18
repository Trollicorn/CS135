//Mohammed Uddin
#include <iostream>

class Circuit{
	private:
		int switch0 = 0;
		int switch1 = 0;
		int lamp_state = 0;
	public:
		int get_first_switch_state(){
			return switch0;
		}
		int get_second_switch_state(){
			return switch1;
		}
		int get_lamp_state(){
			return lamp_state;
		}
		void toggle_first_switch(){
			switch0 = !switch0;
			lamp_state = !lamp_state;
		}
		void toggle_second_switch(){
			switch1 = !switch1;
			lamp_state = !lamp_state;
		}

};

int main(){
	Circuit l;
	std::cout << l.get_first_switch_state() << ' ' << l.get_second_switch_state() << ' ' << l.get_lamp_state() << '\n';
	l.toggle_first_switch();
	std::cout << l.get_first_switch_state() << ' ' << l.get_second_switch_state() << ' ' << l.get_lamp_state() << '\n';
	l.toggle_second_switch();
	std::cout << l.get_first_switch_state() << ' ' << l.get_second_switch_state() << ' ' << l.get_lamp_state() << '\n';
	l.toggle_first_switch();
	std::cout << l.get_first_switch_state() << ' ' << l.get_second_switch_state() << ' ' << l.get_lamp_state() << '\n';
}
