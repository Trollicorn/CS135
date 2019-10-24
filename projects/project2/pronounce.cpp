/*
Author: Mohammed Uddin
Course: CSCI-135
Instructor: Maryash
Assignment: Project 2

takes a word and outputs its pronunciation as a list of phonemes
also outputs words with identical phonemes
and words with 1 phoneme replaced, 1 phoneme inserted, or 1 phoneme removed
*/

#include <iostream>
#include <fstream>

//OPTIMZE SPLIT LATER
void splitOnSpace(std::string s, std::string &before, std::string &after) {
	before = "";
	after = "";
	int len = s.size();
	int i = 0;
	for (i; i < len && !isspace(s[i]); i++);
	before = s.substr(0,i);
	if (i == len) return;
	after = s.substr(i+1);
}

int numWords(std::string line){
	int num = 1;
	int len = line.length();
	for(int i = 0; i < len; i++){
		if (isspace(line[i])){
			num++;
		}
	}
	return num;
}

bool checkWord(std::string word){
	int len = word.length();
	for (int i = 0; i < len; i++){
		if (!std::isalpha(word[i]) && word[i]!='\''){
			return false;
		}
	}
	return true;
}

std::string pronounce(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	file.clear();
	file.seekg(std::ios::beg);
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

void identical(std::string input, std::string phonemes){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	file.clear();
	file.seekg(std::ios::beg);
	std::string line;
	std::string word;
	std::string pronunciation;
	while (std::getline(file,line)){
		splitOnSpace(line,word,pronunciation);
		if (!phonemes.compare(pronunciation) && input.compare(word)){
			std::cout << word << ' ';
		}
	}
}

bool checkReplace(std::string input,std::string pronunciation){
	std::string before;
	std::string after;
	int words = numWords(input);
	if (words != numWords(pronunciation)){
		return false;
	}
	for (int i = 0; i < words; i++){
		std::string pre0 = "", pre1 = "";
		std::string before0, after0; //input
		std::string before1, after1; //pronunciation
		splitOnSpace(input,before0,after0); //first phoneme gone
		splitOnSpace(pronunciation,before1,after1);
		for (int j = 0; j < i; j++){ //remove other phonemes as necessary
			pre0 = pre0 + before0 + " ";
			pre1 = pre1 + before1 + " ";
			splitOnSpace(after0,before0,after0);
			splitOnSpace(after1,before1,after1);
		}
		if (!pre0.compare(pre1) && !after0.compare(after1)){
			return true;
		}
	}
	return false;
}

void replace(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	file.clear();
	file.seekg(std::ios::beg);
	std::string line;
	while(std::getline(file,line)){
		std::string word;
		std::string pronunciation;
		std::string junk;
		splitOnSpace(line,word,pronunciation);
		if (checkWord(word)){
			splitOnSpace(pronunciation,junk,pronunciation);//phonemes only, no space
			if (checkReplace(input,pronunciation) && input.compare(pronunciation)){
				std::cout << ' ' << word;
			}
		}
	}
}

bool checkInsert(std::string input,std::string pronunciation){
	std::string before;
	std::string after;
	int words = numWords(input);
	if (words != numWords(pronunciation)-1){
		return false;
	}
	for (int i = 0; i < words+1; i++){
		std::string pre0 = "", pre1 = "";
		std::string before0, after0 = input; //input
		std::string before1, after1 = pronunciation; //pronunciation
		for (int j = 0; j < i; j++){
			splitOnSpace(after0,before0,after0); //move words from after to pre
			splitOnSpace(after1,before1,after1); //remove words from pronunciation
			pre0 = pre0 + before0 + " ";
			pre1 = pre1 + before1 + " ";
		}
		splitOnSpace(after1,before1,after1); //remove first word

		if (!pre0.compare(pre1) && !after0.compare(after1)){
			return true;
		}
	}
	return false;
}

void insert(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	file.clear();
	file.seekg(std::ios::beg);
	std::string line;
	while(std::getline(file,line)){
		std::string word;
		std::string pronunciation;
		std::string junk;
		splitOnSpace(line,word,pronunciation);
		if (checkWord(word)){
			splitOnSpace(pronunciation,junk,pronunciation);//phonemes only, no space
			if (checkInsert(input,pronunciation)){
				std::cout << ' ' << word;
			}
		}
	}
}

bool checkRemove(std::string input, std::string pronunciation){
	int words = numWords(input);
	if (words != numWords(pronunciation)+1){
		return false;
	}
	for (int i = 0; i < words; i++){
		std::string pre0 = "", pre1 = "";
		std::string before0, after0; //input
		std::string before1;
		std::string after1 = pronunciation; //pronunciation
		splitOnSpace(input,before0,after0); //first phoneme gone
		for (int j = 0; j < i; j++){ //remove other phonemes as necessary
			pre0 = pre0 + before0 + " ";
			splitOnSpace(after0,before0,after0);
			splitOnSpace(after1,before1,after1);
			pre1 = pre1 + before1 + " ";
		}
		if (!pre0.compare(pre1) && !after0.compare(after1)){
			return true;
		}
	}
	return false;
}

void remove(std::string input){
	std::ifstream file("cmudict.0.7a");
	if (file.fail()){
		std::cerr << "file not found\n";
		exit(1);
	}
	file.clear();
	file.seekg(std::ios::beg);
	std::string line;
	while(std::getline(file,line)){
		std::string word;
		std::string pronunciation;
		std::string junk;
		splitOnSpace(line,word,pronunciation);
		if (checkWord(word)){
			splitOnSpace(pronunciation,junk,pronunciation);//phonemes only, no space
			if (checkRemove(input,pronunciation)){
				std::cout << ' ' << word;
			}
		}
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
	std::cout << "Add phoneme      :";
	insert(pronunciation);
	std::cout << '\n';
	std::cout << "Remove phoneme   :";
	remove(pronunciation);
	std::cout << '\n';
	std::cout << "Replace phoneme  :";
	replace(pronunciation);
	std::cout << '\n';
	return 0;
}
