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
	
	std::string date;
	double eastV;
	
	std::cout << "input date (mm/dd/yyyy): ";
	std::string input;
	std::cin >> input;

	while (file >> date >> eastV){
		
		if (! input.compare(date)){
			std::cout << "east basin storage: " << eastV << " billion gallons\n";
			return 0;
		}

		file.ignore(INT_MAX, '\n');	
	}
	std::cout << "date not found\n";
	return 1;
}
