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
	
	std::string date, early, late;
	int start, end;
	std::string  eastV, eastE, westV, westE;
	
	std::cout << "input earlier date: ";
	std::cin >> early;
	std::cout << "input later date: ";
	std::cin >> late;
	
	std::string data[365][2];

	int i = 0;

	while (file >> date >> eastV >> eastE >> westV >> westE){
	
		data[i][0] = date;
		data[i][1] = westE;

		if (! early.compare(date)){
			start = i;
		}
		
		if (! late.compare(date)){
			end = i;
		}

		i++;
		file.ignore(INT_MAX, '\n');
	}

	for (int i = end; i >= start; i--){
		std::cout << data[i][0] << " " << data[i][1] << " ft\n";
	}

	return 0;
}
