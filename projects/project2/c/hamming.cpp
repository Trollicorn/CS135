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
		bool startA = false;
		bool startB = false;
	//	std::string proteinA (' ',len*2);
		char proteinA[len*2];
		char proteinB[len*2];
	//	std::cout << mutate << '\n';
		int indexA = 0;
		int indexB = 0;
		for (int i = 0; i < len; i += 3){
			char codonA[5]; 
			char codonB[5];
			for (int j = 0; j < 3; j++){
				codonA[j] = complement(strand[i+j]);
	//			std::cout << complement(mutate[i+j]) << '\n';
				codonB[j] = complement(mutate[i+j]);
			}
			codonA[4] = '\0';
			codonB[4] = '\0';
	//		std::cout << codonA << '-';
	//		std::cout << codonB << '\n';
			std::string proA = dictionary_read(codons,codonA);
			std::string proB = dictionary_read(codons,codonB);
			if (! proA.compare("Stop")){
				proteinA[indexA] = '\0';
				startA = false;
			}
			if (! proB.compare("Stop")){
				proteinB[indexB] = '\0';
				startB = false;
			}
			if (startA){
				proteinA[indexA] = '-';
				indexA++;
				for (int p = 0; p < 3; p++){
					proteinA[indexA] = proA[p];
					indexA++;
				}
			}
			if (startB){
				proteinB[indexB] = '-';
				indexB++;
				for (int p = 0; p < 3; p++){
					proteinB[indexB] = proB[p];
					indexB++;
				}
			}
			if (! proA.compare("Met")){
				for (int p = 0; p < 3; p++){
					proteinA[indexA] = proA[p];
					indexA++;
				}
				startA = true;
			}
			if (! proB.compare("Met")){
				for (int p = 0; p < 3; p++){
					proteinB[indexB] = proB[p];
					indexB++;
				}
				startB = true;
			}
		}
		proteinA[indexA] = '\0';
		proteinB[indexB] = '\0';
		std::string A(proteinA);
		std::string B(proteinB);

		std::cout << (A.compare(B) ? "yes" : "no") << '\n';
	//	std::cout << proteinA << '\n';
	//	std::cout << proteinB << '\n';
	}
	codons.close();
	file.close();
	return 0;
}
