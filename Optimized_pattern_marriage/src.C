#include <stdio.h>
#include <string.h>

int main()
{
    char geneticSequence[50];
    char pattern[50];
    int i, j;

    scanf("%s", geneticSequence);
    scanf("%s", pattern);

    for (i = 0; i < strlen(geneticSequence); i++)
    {
        for (j = 0; j < strlen(pattern); j++)
        {
            printf("%c ", geneticSequence[(i + j)]);

            if (geneticSequence[(i + j)] != pattern[j])
            {
                printf("não\n");
                if (strchr(pattern, geneticSequence[(i + j)]) == NULL)
                {
                    i = i + j;
                }
                break;
            }
        }

        int lastVerification = j;
        int index = i;
        int seq1 = i + strlen(pattern);
        int seq2 = strlen(geneticSequence) - 1;

        if (lastVerification == strlen(pattern))
        {
            printf("sim\n");
            printf("Achei o padrão no índice %d", index);
            break;
        }
        else if (seq1 > seq2)
        {
            printf("Não achei o padrão");
            break;
        }
    }

    return 0;
}