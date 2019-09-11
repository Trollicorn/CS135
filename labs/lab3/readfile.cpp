#include <iostream>
#include <fstream>
#include <climits>

int main(){
	
	std::ifstream file("reservoir.tsv");
	if (file.fail()){
		std::cerr << "file not found" << '\n';
	}

	std::string metadata; //stores metadata
	getline(file,metadata);
	
	std::string date;
	double eastV, eastE, westV, westE;
	
	while (file >> date >> eastV >> eastE >> westV >> westE){
		file.ignore(INT_MAX, '\n');
		std::cout << date << " " << eastV << " " << eastE << " " << westV << " " << westE << '\n';
	}
	return 0;

}
