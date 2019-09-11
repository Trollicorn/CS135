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
	double min = INT_MAX, max = INT_MIN;

	while (file >> date >> eastV){
		min = min > eastV ? eastV : min;
		max = max < eastV ? eastV : max;
		
		file.ignore(INT_MAX, '\n');	
	}
	std::cout << "min storage in east basin: " << min << " billion gallons\n";
	std::cout << "max storage in east basin: " << max << " billion gallons\n";
	return 0;
}
