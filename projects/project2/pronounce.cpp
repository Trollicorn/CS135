#include <iostream>
#include <fstream>

//OPTIMZE SPLIT LATER
void splitOnSpace(std::string s, std::string &before, std::string &after) {
	// reset strings
	before = "";
	after = "";
	// accumulate before space
	int i = 0;
	while (i < s.size() && not isspace(s[i])) {
		before = before + s[i];
		i++;
	}
	// skip the space
	i++;
	// accumulate after space
	while (i < s.size()) {
		after = after + s[i];
		i++;
	}
}
//E

std::string pronounce(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::string line;
	std::string word;
	std::string pronunciation;
	while (std::getline(file,line)){
		splitOnSpace(line,word,pronunciation);
		if (!input.compare(word)){
			//std::string temp;
			//splitOnSpace(pronunciation,word,pronunciation);
			return pronunciation;
		}
	}
	return "word not found";
}

void identical(std::string input, std::string phenomes){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}	
	std::string line;
	std::string word;
	std::string pronunciation;
	while (std::getline(file,line)){
		splitOnSpace(line,word,pronunciation);
		if (!phenomes.compare(pronunciation) && input.compare(word)){
			std::cout << word << ' ';
		}
	}
	
}

int main(){
	std::string word;
	std::cin >> word;
	for (int i = 0; i < word.length(); i++){
		word[i] = toupper(word[i]);
	}
	std::cout << "Word             : " << word << '\n';
	std::string pronunciation = pronounce(word);
	if (!pronunciation.compare("word not found")){
		std::cerr << "ERROR: WORD NOT FOUND\n";
		exit(1);
	}
	std::cout << "Pronunciation    :" << pronunciation << '\n';
	std::cout << "Identical        : ";
	identical(word,pronunciation);
	std::cout << '\n';
}




