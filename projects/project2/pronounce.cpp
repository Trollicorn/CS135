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
	for (int i = 0; i < input.length(); i++){
		input[i] = toupper(input[i]);
	}
	std::string line;
	std::string word;
	std::string pronunciation;
	while (std::getline(file,line)){
		splitOnSpace(line,word,pronunciation);
		if (!input.compare(word)){
			return pronunciation;
		}
	}
	return "word not found";
}

int main(){
	std::cout << "word: locomotive\n";
	std::cout << pronounce("locomotive") << '\n';
}




