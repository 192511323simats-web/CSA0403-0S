#include "crypto.h"

const char *crypto_version(void) { 
    return "encryption library v1 (old algorithm)"; 
}

void encrypt_buf(char *buf, int n, char key) { 
    for (int i = 0; i < n; i++) 
        buf[i] ^= key; 
}