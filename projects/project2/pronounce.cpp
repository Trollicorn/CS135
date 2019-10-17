/*
Author: Mohammed Author
Course: CSCI-135
Instructor: Maryash
Assignment: Project 2

takes a word and outputs its pronunciation as a list of phenomes
also outputs words with identical phenomes and words with 1 phenome replaced, 1 phenome inserted, or 1 phenome removed
*/

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
	for (int i = 0; i < words; i++){
		std::string pre = "";
		std::string before;
		std::string after;
		splitOnSpace(input,before,after); //get rid of first word
		for (int j = 0; j < i; j++){ //get rid of other words if necessary
			pre = pre + before + " ";
			splitOnSpace(after,before,after);
		}
		while(std::getline(file,line)){
			std::string junkpre = "";
			std::string junk;
			std::string word;
			std::string pronunciation;
			splitOnSpace(line,word,pronunciation);
			splitOnSpace(pronunciation,junk,pronunciation);//phenomes only, no space
			std::string replaced = pronunciation;
			splitOnSpace(replaced,junk,replaced); //get rid of first word
			if (words == numWords(pronunciation)){
				for (int k = 0; k < i; k++){ //get rid of other words if necessary
					junkpre = junkpre + junk + " ";
					splitOnSpace(replaced,junk,replaced);
				}
				if (!pre.compare(junkpre) && !after.compare(replaced) && input.compare(pronunciation)){
					std::cout << ' ' << word;
				}
			}
		}
		file.clear();
		file.seekg(std::ios::beg);
	}
}

void insert(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::string line;
	int words = numWords(input);
	for (int i = 0; i < words+1; i++){
		std::string pre = "";
		std::string before = "";
		std::string after = input;
		for (int j = 0; j < i; j++){
			splitOnSpace(after,before,after); //move word from after to pre
			pre = pre + before + " ";
		}
//		std::cout << pre << " :: " << after << '\n';
		while(std::getline(file,line)){
			std::string junkpre = "";
			std::string junk;
			std::string word;
			std::string pronunciation;
			splitOnSpace(line,word,pronunciation);
			splitOnSpace(pronunciation,junk,pronunciation);//phenomes only, no space
			std::string junkafter = pronunciation;
			if (words == numWords(pronunciation)-1){
				for (int k = 0; k < i; k++){
					splitOnSpace(junkafter,junk,junkafter);
					junkpre = junkpre + junk + " ";
		//			std::cout << junkpre << " :: " << junkafter << '\n';
				}
				splitOnSpace(junkafter,junk,junkafter);//skip word that is added
	//			std::cout << pre << " :: " << after << '\n';
				if (!pre.compare(junkpre) && !after.compare(junkafter) && input.compare(pronunciation)){
					std::cout << ' ' << word;
				}
			}
		}
		file.clear();
		file.seekg(std::ios::beg);
	}
}

void remove(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	std::string line;
	int words = numWords(input);
	for (int i = 0; i < words; i++){
		std::string pre = "";
		std::string before = "";
		std::string after = input;
		splitOnSpace(input,before,after); //get rid of first word
		for (int j = 0; j < i; j++){ //get rid of other words if necessary
			pre = pre + before + " ";
			splitOnSpace(after,before,after);
		}
		while(std::getline(file,line)){
			std::string junkpre = "";
			std::string junk;
			std::string word;
			std::string pronunciation;
			splitOnSpace(line,word,pronunciation);
			splitOnSpace(pronunciation,junk,pronunciation);//phenomes only, no space
			std::string junkafter = pronunciation;
			if (words == numWords(pronunciation)+1){
				for (int k = 0; k < i; k++){
					splitOnSpace(junkafter,junk,junkafter); // move word from junkafter to junkpre
					junkpre = junkpre + junk + " ";
				}
				if (!pre.compare(junkpre) && !after.compare(junkafter) && input.compare(pronunciation)){
					std::cout << ' ' << word;
				}
			}
		}
		file.clear();
		file.seekg(std::ios::beg);
	}
}

int main(){
	std::string word;// = "plants";
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
	std::cout << "Pronunciation    :" << pronunciation << "\n\n";
	std::cout << "Identical        : ";
	identical(word,pronunciation);
	std::cout << '\n';
	std::string garbage;
	splitOnSpace(pronunciation,garbage,pronunciation);//get rid of starting space
	std::cout << "Replace phenome  :";
	replace(pronunciation);
	std::cout << '\n';
	std::cout << "Add phenome      :";
	insert(pronunciation);
	std::cout << '\n';
	std::cout << "Remove phenome   :";
	remove(pronunciation);
	std::cout << '\n';
}
