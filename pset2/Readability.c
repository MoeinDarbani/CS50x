#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[10000];
    // Getting input
    printf("Enter Your Pragraph: ");
    fgets(text, sizeof(text), stdin);

    // Counting Alphabets
    int alpha = strlen(text);
    int letters = 0;
    for (int k = 0; k < alpha; k++)
    {
        if (isalpha(text[k]))
        {
            letters++;
        }
    }
    // Counting Words & Sentences
    int words = 1;
    int sentences = 0;
    for (int i = 0; i < alpha; i++)
    {
        if ((int) text[i] == 32)
        {
            words++;
        }
        else if ((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63)
        {
            sentences++;
        }
    }

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded = (round(index));

    if (rounded >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else if (rounded < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else
    {
        printf("Grade %d\n", rounded);
    }
}
