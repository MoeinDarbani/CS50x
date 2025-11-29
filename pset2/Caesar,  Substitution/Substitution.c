#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int letters[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        int index = toupper(key[i]) - 'A';
        if (letters[index] > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        letters[index] = 1;
    }

    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    char ciphertext[1000];
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int index = plaintext[i] - 'A';
            ciphertext[i] = toupper(key[index]);
        }
        else if (islower(plaintext[i]))
        {
            int index = plaintext[i] - 'a';
            ciphertext[i] = tolower(key[index]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
