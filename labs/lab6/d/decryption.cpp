#include <iostream>

char shiftChar(char c, int rshift){
	char a = isupper(c) ? 'A' : 'a';
	return (((int)c - a + rshift) % 26) + a;
}

char shiftChar(char c, char shift, int decrypt){
	int n = decrypt ? 'z' - shift + 1 : shift - 'a';
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

std::string decryptCaesar(std::string ciphertext, int rshift){
	return encryptCaesar(ciphertext, 26 - rshift);
}

std::string vigenere(std::string plaintext, std::string keyword, int decrypt){
	int keyin = 0;
	char crypt[plaintext.length()+1];
	for (int i = 0; i < plaintext.length(); i++){
		char p = plaintext[i];
		if (isalpha(p)){
			crypt[i] = shiftChar(p,keyword[keyin],decrypt);
			keyin = (keyin + 1) % keyword.length();
		}else{
			crypt[i] = p;
		}
	}
	crypt[plaintext.length()] = '\0';
	std::string str(crypt);
	return str;
}
std::string encryptVigenere(std::string plaintext, std::string keyword){
	return vigenere(plaintext, keyword, 0);
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
	return vigenere(ciphertext, keyword, 1);
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
	std::string caesarText = encryptCaesar(plaintext,rshift);
	std::cout << caesarText << '\n';
	std::cout << "decrypted      : ";
	std::cout << decryptCaesar(caesarText,rshift) << '\n';

	std::cout << '\n' << '\n';
	std::cout << "= Vigenere =\n";
	std::cout << "enter keyword  : ";
	std::string keyword;
	std::cin >> keyword;
	std::cout << "ciphertext     : ";
	std::string vigenereText = encryptVigenere(plaintext,keyword);
	std::cout << vigenereText << '\n';
	std::cout << "decrypted      : ";
	std::cout << decryptVigenere(vigenereText,keyword) << '\n';
	return 0;


}
