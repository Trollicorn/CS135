#include <iostream>
#include <fstream>

char complement(char c){ //assumes c is one of A,T,C,G
	return c == 'A' ? 'U' : c == 'T' ? 'A' : c == 'C' ? 'G' : c == 'G' ? 'C' : 'R'; //R is error
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

int main(){
	std::ifstream codons("codons.tsv");
	if (codons.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::ifstream file("frameshift_mutations.txt");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}

	std::string strand;
	while(getline(file,strand)){
		int len = strand.length();
		int index = 0;
		bool found = false;
		for (int i = 0; !found && i < len-2; i++){
			if (strand[i]=='T' && strand[i+1]=='A' && strand[i+2]=='C'){
				index = i;
				found = true;
			}
		}
		bool start = false;
		int end = (len-index)/3;
		int i = index;
		for (int c = 0; c < end; c++){
			char codon[4];
			for (int j = 0; j < 3; j++){
				codon[j] = complement(strand[i+j]);
			}
			codon[4] = '\0';
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
			i+=3;
		}
		std::cout << '\n';
	}
	codons.close();
	file.close();
	return 0;
}
