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

int main(){
	std::ifstream file("codons.tsv");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	/*
	std::ifstream file("dna2b.txt");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	*/
	std::cout << "GGU, expecting Gly: " << dictionary_read(file,"GGU") << '\n';
	std::cout << "UAA, expecting Stop: " << dictionary_read(file,"UAA") << '\n';
	std::cout << "MUG, expecting ERR: " << dictionary_read(file,"MUG") << '\n'; 
	

	
	/*
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
	*/
	file.close();
	return 0;
}
