#include <stdio.h>

int main()
{
    int qttLines;
    char character;

    scanf("%d %c", &qttLines, &character);

    for (int i = 0; i < (qttLines - 1); i++)
    {
        for (int j = 0; j < (qttLines - 1); j++)
        {
            if (i == j || i + j == qttLines - 2)
            {
                printf("%c", character);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}