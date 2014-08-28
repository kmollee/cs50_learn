/**
 * caesar.c
 *
 * week 3 section
 * fall 2013
 *
 * h/t Mike Rizzo
 *
 * practice using GDB on buggy code
 */

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
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // save the key
    int key = atoi(argv[1]);

    // get the plaintext from the user
    string plaintext = GetString();

    // encrypt the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = (plaintext[i] - 'A' + key) % 26;
        }
        else if (plaintext[i] >= 'a' && plaintext[i] < 'z')
        {
            plaintext[i] = (plaintext[i] - 'a' + key) % 26;
        }
    }

    // print out the encrypted message
    printf("%s\n", plaintext);

    return 0;
}
