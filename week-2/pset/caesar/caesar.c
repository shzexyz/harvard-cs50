#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // return error if > 1 argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // return error if argument != number
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert key to digit
    int key = atoi(argv[1]);

    // get plaintext
    string plaintext = get_string("plaintext: ");

    // encipher
    string ciphertext = plaintext;
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (!isalpha(plaintext[i]))
            continue;
        else if (isupper(plaintext[i]))
            ciphertext[i] = (((plaintext[i] - 65) + key) % 26) + 65;
        else if (islower(plaintext[i]))
            ciphertext[i] = (((plaintext[i] - 97) + key) % 26) + 97;
    }
    // print ciphertext
    printf("ciphertext: %s\n", ciphertext);
}
