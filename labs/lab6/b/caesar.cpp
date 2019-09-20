#include <iostream>

char shiftChar(char c, int rshift){
	char a = isupper(c) ? 'A' : 'a';
	return (((int)c - a + rshift) % 26) + a;
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

int main(){
	std::string plaintext;
	int rshift;
	std::cout << "enter plaintext: ";
	std::getline(std::cin,plaintext);
	std::cout << "enter rshift   : ";
	std::cin >> rshift;
	std::cout << "ciphertext     : ";
	std::cout << encryptCaesar(plaintext,rshift) << '\n';
	return 0;
}
