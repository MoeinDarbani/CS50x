#include <stdio.h>

int main()
{
    char answer[12];
    printf("What's Your Name? ");
    scanf("%s", answer);

    printf("Hello, %s\n", answer);
    return 0;
}
