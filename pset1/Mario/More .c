#include <stdio.h>

int main()
{
    float num;
    do
    {
        printf("How many bricks do you want: ");
        scanf("%f", &num);
    }
    while (num <= 0 || num != (int) num);
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("  ");

        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        for (int k = 0; k < i; k++)
        {
        }
        printf("\n");
    }
    return 0;
}
