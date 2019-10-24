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
	for(int i = 0; i < line.length(); i++){
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

void replaceOld(std::string input){
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
			splitOnSpace(pronunciation,junk,pronunciation);//phonemes only, no space
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

void insertOld(std::string input){
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
			splitOnSpace(pronunciation,junk,pronunciation);//phonemes only, no space
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

void removeOld(std::string input){
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
			splitOnSpace(pronunciation,junk,pronunciation);//phonemes only, no space
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
	std::cout << "Add phoneme      :";
	insert(pronunciation);
	std::cout << '\n';
	std::cout << "Remove phoneme   :";
	remove(pronunciation);
	std::cout << '\n';
	std::cout << "Replace phoneme  :";
	replace(pronunciation);
	std::cout << '\n';

}
