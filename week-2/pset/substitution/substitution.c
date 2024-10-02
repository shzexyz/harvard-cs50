#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    // get only one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // check for key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, len = strlen(key); i < len; i++)
    {
        // check for non-alphabetic characters
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetical characters.\n");
            return 1;
        }

        int repeat = 0;
        // check for repeated characters (case-insensitive)
        for (int j = 0; j < len; j++)
        {
            if (toupper(key[j]) == toupper(key[i]))
            {
                repeat++;
            }
            if (repeat > 1)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // prompt user fo plaintext
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;

    // output ciphertext
    for (int i = 0, plaintext_len = strlen(plaintext); i < plaintext_len; i++)
    {
        if (!isalpha(plaintext[i]))
            continue;
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 'A';
            char c = key[letter];
            ciphertext[i] = toupper(c);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 'a';
            char c = key[letter];
            ciphertext[i] = tolower(c);
        }
    }

    printf("ciphertext: %s\n", ciphertext);
}
