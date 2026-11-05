#include <stdio.h>
#include <string.h>


int main(void) 
{
    char msg[] = "ACCOUNT 192511355 BALANCE 5000";
    printf("--- Q1: Linking and Loading ---\n");
    printf("%s\n", crypto_version());
    encrypt_buf(msg, strlen(msg), 0x5A); 
    encrypt_buf(msg, strlen(msg), 0x5A);   /* encrypt, then decrypt */
    printf("round trip ok: %s\n", msg); 
    return 0;
}