#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_digit(char s[]);
char rotate(char c, int key);
int to_int(char s[]);

int main(int argc, char *argv[])
{
    // Checking For Invalid Values
    if (argc != 2 || !is_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = to_int(argv[1]);

    char text[1000];
    char ciphertext[1000];

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++)
    {
        ciphertext[i] = rotate(text[i], key);
    }
    ciphertext[strlen(text)] = '\0';

    printf("ciphertext: %s", ciphertext);
    return 0;
}

int is_digit(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

char rotate(char c, int key)
{
    if (isupper(c))
    {
        return ((c - 'A' + key) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' + key) % 26) + 'a';
    }
    else
    {
        return c;
    }
}

int to_int(char s[])
{
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}
