#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Vingenere Key Cipher implementation
// -------------------------------------------------------

struct Cipher::CipherCheshire
{
	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";


};

struct KCipher::ExtraCheshire 
{
	vector<string> book;
	unsigned int page = 0;

};

VCipher::VCipher() : KCipher()
{

};
//Err check
VCipher::VCipher(string key)
{
	for (unsigned int i = 0; i < key.size(); i++)
	{
		char c = key[i];
		if(!(c >= 'a') && (c <= 'z'))
		{
			cout << "Error: Use a valid Vigenere keyword" << endl;
			exit(EXIT_FAILURE);
		}

	}


string page;

while(page.size() < MAX_LENGTH) {
    	page += key;
    }

    // Clear book 
    grin->book.clear();

    // Push page 
    grin->book.push_back(page);
};

//Destructor
VCipher::~VCipher() {
};


