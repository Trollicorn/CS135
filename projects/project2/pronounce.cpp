#include <iostream>
#include <fstream>

//OPTIMZE SPLIT LATER
bool splitOnSpace(std::string s, std::string &before, std::string &after) {
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
	return after.size();
}
//E

int numWords(std::string line){
	int num = 1;
	for(int i = 0; i < line.length(); i++){
		if (isspace(line[i])){
			num++;
		}
	}
	return num;
}

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

void replace(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::string line;
	int words = numWords(input);
//	std::cout << words;
	for (int i = 0; i < words; i++){
		std::string pre = "";
		std::string before; //a e i o u
		std::string after;
		splitOnSpace(input,before,after); //bef: a aft: e i o u
//		std::cout << after << '\n';
		for (int j = 0; j < i; j++){
			pre = pre + before + " "; // pre: "a"
			splitOnSpace(after,before,after); // bef: e aft: i o u
		}
//		splitOnSpace(input,before,after);
		//one done
		while(std::getline(file,line)){
			std::string junkpre = "";
			std::string junk;
			std::string word;
			std::string pronunciation;
			splitOnSpace(line,word,pronunciation);
			splitOnSpace(pronunciation,junk,pronunciation);//phenomes only, no space
			std::string replaced = pronunciation;
			splitOnSpace(replaced,junk,replaced);//not 1st
			for (int k = 0; k < i; k++){
				junkpre = junkpre + junk + " ";
				splitOnSpace(replaced,junk,replaced);
			}
			if (!pre.compare(junkpre) && !after.compare(replaced) && input.compare(pronunciation)){
		//		std::cout << "pre: " << pre << " after: " << after << " input: " << input << '\n';
				std::cout << ' ' << word;
			}
		}
		file.clear();
		file.seekg(0);
	}
}

int main(){
	std::string word;// = "accord";
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
	std::string garbage;
	splitOnSpace(pronunciation,garbage,pronunciation);//get rid of starting space
	std::cout << "Replace phenome  :";
	replace(pronunciation);
	std::cout << '\n';
}
