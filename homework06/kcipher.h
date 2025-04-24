#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;

/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */
// TODO: Implement this function

class KCipher : public Cipher
{
	protected:
		struct ExtraCheshire;
		ExtraCheshire *grin;
	
	public:
		KCipher();
		KCipher(string page_one);

		//define funcs used in main
		void add_key(string page);
		void set_id(unsigned int id);
		//new def and uses in kcipher of enc and dec funcs
		string encrypt(string raw);
		string decrypt(string enc);

		~KCipher();

};
	
void removeSpaces(string& str);

#endif

