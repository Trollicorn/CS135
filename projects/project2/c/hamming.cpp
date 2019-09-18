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
		getline(file,mutate);
		std::cout << hamming(strand,mutate) << ' ';
		int len = strand.length();

		bool start;
		char protein[len*2];
		int index;
		std::string str;
		std::string proteinA;
		std::string proteinB;
		for (int m = 0; m < 2; m++){
			str = m ? mutate : strand;
			start = false;
			index = 0;
			for (int i = 0; i < len; i += 3){
				char codon[4];	
				for (int j = 0; j < 3; j++){
					codon[j] = complement(str[i+j]);
				}
				codon[3] = '\0';
				std::string pro = dictionary_read(codons,codon);
				if (! pro.compare("Stop")){
					protein[index] = '\0';
					start = false;
				}
				if (start){
					protein[index] = '-';
					index++;
					for (int p = 0; p < 3; p++){
						protein[index] = pro[p];
						index++;
					}
				}
				if (! pro.compare("Met")){
					for (int p = 0; p < 3; p++){
						protein[index] = pro[p];
						index++;
					}
					start = true;
				}

			}
			protein[index] = '\0';
			std::string temp(protein);
			if (! m){ //working on original strand
				proteinA = temp;
			}else { //working on mutated strand
				proteinB = temp;
			}
		}
		std::cout << (proteinA.compare(proteinB) ? "yes" : "no") << '\n';
	}
	codons.close();
	file.close();
	return 0;
}
