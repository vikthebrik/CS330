#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"


// -------------------------------------------------------
// Caesar Cipher implementation


// -------------------------------------------------------

struct Cipher::CipherCheshire 
{
	string cipher_alpha;
};

CCipher::CCipher()
{
	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";

	rotate_string(cipher_alpha, 0);

	smile->cipher_alpha = cipher_alpha;

}

CCipher::CCipher(int shift)
{
	if(shift < 0)
	{
		cout << "Error: Caesar cipher is less than 0" << endl;
		exit(EXIT_FAILURE);
	}
	
	string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";

	rotate_string(cipher_alpha, shift);

	smile->cipher_alpha = cipher_alpha;

}
//use cipher.cc destructor
CCipher::~CCipher()
{

}
	


// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    // TODO: You will likely need this function. Implement it.
    while (rot) {
	
    	in_str[ALPHABET_SIZE] = in_str[0];

	// Shift the in_str down one
	for (unsigned int i = 0; i < ALPHABET_SIZE; i++) {
	    in_str[i] = in_str[i + 1];
	}

	// Decrement rot
	rot--;
    }
}
