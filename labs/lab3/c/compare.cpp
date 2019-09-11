#include <iostream>
#include <fstream>
#include <climits>

int main(){
	
	std::ifstream file("../reservoir.tsv");
	if (file.fail()){
		std::cerr << "file not found" << '\n';
	}

	std::string metadata; //stores metadata
	getline(file,metadata);
	
	std::string date, start, end;
	double eastV, eastE, westV, westE;
	
	std::cout << "input start date: ";
	std::cin >> start;
	std::cout << "input end date: ";
	std::cin >> end;
	bool check = false;

	while (file >> date >> eastV >> eastE >> westV >> westE){
		
		if (! start.compare(date)){
			check = true;
		}
		if (check){
			std::cout << (eastE > westE ? "east" : "west") << '\n';
		}
		
		if (! end.compare(date)){
			return 0;
		}

		file.ignore(INT_MAX, '\n');	
	}
	return 1;
}
