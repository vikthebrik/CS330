#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"




/* Helper function definitions
 */

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

//simple helper func
void removeSpaces(string& str) {
    for (unsigned int i = 0; i < str.length(); i++) {
    	if (str[i] == ' ')
	    str.erase(str.begin() + i);
    }
}


//check if pg is valid based on param defined in slides
bool is_valid_page(string page) {
    
    bool pgValid = true;
    
    //empty page check
    if (page.length() == 0) {
	cout << "Invalid Running key: " << page << endl;
	pgValid = false;
	return pgValid;
    } 

    // maek sure it is lower case or space
    for (unsigned int i = 0; i < page.length(); i++) {
    	char c = page[i];
	if (!(((c >= 'a') && (c <= 'z')) || (c == ' '))) {
	    cout << "Invalid Running key: " << page << endl;
	    pgValid = false;
	    return pgValid;
	}
    }

    return pgValid;
}

// -------------------------------------------------------
// Running Key Cipher implementation

struct Cipher::CipherCheshire {
    string cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
};

struct KCipher::ExtraCheshire {
    // Store book in vector
    vector<string> book;
    
    // Pg 0 start
    unsigned int page = 0;
};


KCipher::KCipher() {
    //Init storage vector
    vector<string> book;

    // Fill page with the letter 'a' for max len
    string page;
    for (unsigned int i = 0; i < MAX_LENGTH; i++) {
    	page += 'a';
    }

    // Push into the vector
    book.push_back(page);

    // new obj of the ExtraCheshire struct
    grin = new ExtraCheshire;

    // Store vector in the ExtraCheshire kcip
    grin->book = book;
};


KCipher::KCipher(string page_one) {
    //Err check
    if (!is_valid_page(page_one)) {
    	exit(EXIT_FAILURE);
    }
	
    grin = new ExtraCheshire;
    
    //Store in extracheshire
    grin->book.push_back(page_one);
};


void KCipher::add_key(string page) {
    // Err check
    if (!is_valid_page(page)) {
    	exit(EXIT_FAILURE);
    }
    
    // Push into the book
    grin->book.push_back(page);
};


void KCipher::set_id(unsigned int id) {
    // Error check
    if (id > grin->book.size()) {
    	cout << "Warning: invalid id: " << id << endl;
	exit(EXIT_FAILURE);
    }

    // Set the id for the page we'll use to encrypt/decrypt
    grin->page = id;
};


string KCipher::encrypt(string raw) {
    // Init ret var
    string retStr;
    removeSpaces(grin->book[grin->page]);
    string enc_page = grin->book[grin->page];
    
    // Initialize a vector to store the pos
    vector<int> space_pos;
    int len_raw_with_spaces = raw.length();

    // Pop the vector just created
    for (int i = 0; i < len_raw_with_spaces; i++) {
    	if (raw[i] == ' ')
	    space_pos.push_back(i);
    }
    removeSpaces(raw);

    //Err check
    if (enc_page.length() < raw.length()) {
    	cout << "Invalid Running key: " << enc_page << endl;
	exit(EXIT_FAILURE);
    }

    cout << "Encrypting...";

    // Get the length 
    int len_raw = raw.length();
    
    // Parse thru input string by char
    for (int i = 0; i < len_raw; i++) {
    	char lower_raw = LOWER_CASE(raw[i]);
	char lower_enc = LOWER_CASE(enc_page[i]);

	
	int pos_raw = find_pos(smile->cipher_alpha, lower_raw);
	int pos_enc = find_pos(smile->cipher_alpha, lower_enc);

	// Rotate the alphabet however far is needed
	rotate_string(smile->cipher_alpha, pos_raw);

	
	char output = smile->cipher_alpha[pos_enc];
	if (isupper(raw[i]))
	    output = UPPER_CASE(smile->cipher_alpha[pos_enc]);

	// Add the encrypted char
	retStr += output;

	// Reset the alphabet 
	rotate_string(smile->cipher_alpha, ALPHABET_SIZE - pos_raw);
    }

    // Get the length of the vector w space pos
    int vec_len = space_pos.size();

    // Insert spaces into the correct location
    for (int i = 0; i < vec_len; i++) {
	   retStr.insert(space_pos[i], " "); 
    }

    cout << "Done" << endl;

    return retStr;
}


string KCipher::decrypt(string enc) {
    cout << "Decrypting...";
    
    string retStr;
    string enc_page = grin->book[grin->page];

    // Init vector to store the positions of the spaces
    vector<int> space_pos;

    // Get length of the string 
    int len_enc_with_spaces = enc.length();
    for (int i = 0; i < len_enc_with_spaces; i++) {
    	if (enc[i] == ' ')
	    space_pos.push_back(i);
    }

    // Remove the spaces from enc since we know where they're at now
    removeSpaces(enc);

    // Get the length of the string we're decrypting
    int len_enc = enc.length();
    
    // Loop through every character in the string we're decrypting
    for (int i = 0; i < len_enc; i++) {
        // Convert the character we're looking for in enc and enc_page to lowercase
        char lower_enc = LOWER_CASE(enc[i]);
        char lower_page = LOWER_CASE(enc_page[i]);

        // Find position in normal page
        int pos_page = find_pos(smile->cipher_alpha, lower_page);

        // Rotate the alphabet however far is needed (how I handle tableau rows)
        rotate_string(smile->cipher_alpha, pos_page);
        int pos_dec = find_pos(smile->cipher_alpha, lower_enc);

        
        rotate_string(smile->cipher_alpha, ALPHABET_SIZE - pos_page);

        
        char result = smile->cipher_alpha[pos_dec];

        
        if (isupper(enc[i]))
	    result = UPPER_CASE(smile->cipher_alpha[pos_dec]);

        
        retStr += result;
    }

    
    int vec_len = space_pos.size();

    
    for (int i = 0; i < vec_len; i++) {
	   retStr.insert(space_pos[i], " "); 
    }

    cout << "Done" << endl;

    return retStr;
}


// Destructor to delete the ExtraCheshire struct we created
KCipher::~KCipher() {
    delete grin;
};
