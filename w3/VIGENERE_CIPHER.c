#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // ensure user entered a valid key
    if (argc != 2 || atoi(argv[0]) < 0)
    {
        printf("Usage: ./VIGENERE CIPHER key\n");
        return 1;
    }

    // save the key
    string key = argv[1];
    int key_len = strlen(key);

    // get the plaintext from the user
    string plaintext = GetString();

    // encrypt the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = (plaintext[i] - 'A' + (key[(i%key_len)] - 'A')) % 26 + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] < 'z')
        {
            plaintext[i] = (plaintext[i] - 'a' + (key[(i%key_len)]-'a')) % 26 + 'a';
        }
    }

    // print out the encrypted message
    printf("%s\n", plaintext);

    return 0;
}
