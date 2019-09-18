#include <iostream>
#include <fstream>
#include <string>

char complement(char c){ 
	return c == 'A' ? 'U' : c == 'T' ? 'A' : c == 'C' ? 'G' : c == 'G' ? 'C' : 'R'; //R is an error
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
	//	getline(file,mutate);
	//	std::cout << hamming(strand,mutate) << " ";
		int len = strand.length();
		bool startA = false;
	//	bool startB = false;
	//	std::string proteinA (' ',len*2);
		char proteinA[len*2];
	//	std::string proteinB (' ',len*2);
	//	std::cout << strand << '\n';
		int index = 0;
		for (int i = 0; i < len; i += 3){
			char codonA[4]; 
	//		char codonB[4];
			for (int j = 0; j < 3; j++){
				codonA[j] = complement(strand[i+j]);
	//			std::cout << codonA << '\n';
	//			codonB[j] = complement(mutate[i+j]);
			}
			codonA[4] = '\0';
	//		codonB[4] = '\0';
			std::string proA = dictionary_read(codons,codonA);
	//		std::string proB = dictionary_read(codons,codonB);
			if (! proA.compare("Stop")){
				proteinA[index] = '\0';
				startA = false;
			}
			if (startA){
				proteinA[index] = '-';
				index++;
				for (int p = 0; p < 3; p++){
					proteinA[index] = proA[p];
					index++;
				}
			}
			if (! proA.compare("Met")){
				for (int p = 0; p < 3; p++){
					proteinA[index] = proA[p];
					index++;
				}
				startA = true;
			}
		}
		proteinA[index] = '\0';
		std::cout << proteinA << '\n';
	}
	codons.close();
	file.close();
	return 0;
}
