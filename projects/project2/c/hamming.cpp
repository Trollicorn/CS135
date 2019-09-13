#include <iostream>
#include <fstream>

char complement(char c){ //assumes c is one of A,T,C,G
	return c == 'A' ? 'U' : c == 'T' ? 'A' : c == 'C' ? 'G' : 'C';
}

std::string dictionary_read(std::ifstream &dict, std::string codon){
	std::string key, value;
	dict.clear();
	dict.seekg(0);
	while (dict >> key >> value){
		if (!codon.compare(key)){
			return value;
		}
		//std::cout << "key: " << key << '\n';
		//std::cout << "value: " << value << '\n';
	}
	return "ERR";
}

int hamming(std::string a, std::string b){
	int diff = 0;
	for (int i = 0; i < a.length(); i++){
		if (a[i] != b[i]){
			diff++;
		}	
	}
	return diff;
}

int main(){
	std::ifstream codons("codons.tsv");
	if (codons.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::ifstream file("mutations.txt");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::string strand;
	std::string mutate;
	while(getline(file,strand)){
		getline(file,mutate);
		std::cout << hamming(strand,mutate) << "\n";
		int len = strand.length();
		bool start = false;
		for (int i = 0; i < len; i += 3){
			char codon[4];
			for (int j = 0; j < 3; j++){
				codon[j] = complement(strand[i+j]);
			}
			codon[4] = '\0';
			//std::cout << dictionary_read(codons, codon) << ' ';
			std::string protein = dictionary_read(codons,codon);
			if (! protein.compare("Stop")){
				start = false;
			}
			if (start){
				std::cout << '-' << protein;
			}
			if (! protein.compare("Met")){
				std::cout << protein;
				start = true;
			}
		}
		std::cout << '\n';
	}
	codons.close();
	file.close();
	return 0;
}
