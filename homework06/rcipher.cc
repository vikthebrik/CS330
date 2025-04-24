#include <string>
#include <iostream>
#include "rcipher.h"

// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------

struct Cipher::CipherCheshire {
    string cipher_alpha;
};

// Use CCipher's contructor and destructor, just extend
RCipher::RCipher() : CCipher(13) {
}

RCipher::~RCipher() {
}


