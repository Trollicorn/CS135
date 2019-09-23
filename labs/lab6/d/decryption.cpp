#include <iostream>

char shiftChar(char c, int rshift){
	char a = isupper(c) ? 'A' : 'a';
	return (((int)c - a + rshift) % 26) + a;
}

char shiftChar(char c, char shift){
	int n = shift - 'a';
	char a = isupper(c) ? 'A': 'a';
	return ((int)c - a + n)% 26 + a;
}

std::string encryptCaesar(std::string plaintext, int rshift){
	char crypt[plaintext.length()+1];
	for (int i = 0; i < plaintext.length(); i++){
		crypt[i] = isalpha(plaintext[i]) ? shiftChar(plaintext[i],rshift) : plaintext[i];
	}
	crypt[plaintext.length()] = '\0';
	std::string str(crypt);
	return str;
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
	int keyin = 0;
	char crypt[plaintext.length()+1];
	for (int i = 0; i < plaintext.length(); i++){
		char p = plaintext[i];
		if (isalpha(p)){
			crypt[i] = shiftChar(p,keyword[keyin]);
			keyin = (keyin + 1) % keyword.length();
		}else{
			crypt[i] = p;
		}
	}
	crypt[plaintext.length()] = '\0';
	std::string str(crypt);
	return str;
}

int main(){
	std::string plaintext;
	std::cout << "enter plaintext: ";
	std::getline(std::cin,plaintext);
	std::cout << '\n' << '\n';
	
	std::cout << "= Caesar =\n";
	std::cout << "enter shift    : ";
	int rshift;
	std::cin >> rshift;
	std::cout << "ciphertext     : ";
	std::cout << encryptCaesar(plaintext,rshift) << '\n';

	std::cout << '\n' << '\n';
	std::cout << "= Vigenere =\n";
	std::cout << "enter keyword  : ";
	std::string keyword;
	std::cin >> keyword;
	std::cout << "ciphertext     : ";
	std::cout << encryptVigenere(plaintext,keyword) << '\n';
	return 0;


}
