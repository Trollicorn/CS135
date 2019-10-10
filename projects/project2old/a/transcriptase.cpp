#include <iostream>
#include <fstream>

char complement(char c){ //assumes c is one of A,T,C,G
	return c == 'A' ? 'U' : c == 'T' ? 'A' : c == 'C' ? 'G' : 'C';
}

int main(){
	std::ifstream file("dna.txt");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::string strand;
	while(getline(file,strand)){
		//std::cout << strand << "\n";
		int len = strand.length();
		char transcript[len+1];
		transcript[len] = '\0';
		for (int i = 0; i < len; i++){
			transcript[i] = complement(std::toupper(strand[i]));
		}
		std::cout << transcript << "\n";
	}
	file.close();
	return 0;
}
