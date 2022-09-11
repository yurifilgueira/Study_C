#include <stdio.h>

int main()
{
    int number;

    scanf("%d", &number);

    if (number <= 0)
    {
        printf("Você entrou com %d, tente de novo na próxima", number);
    }
    else
    {
        int x = 0;
        for (int i = 1; i <= number; i++)
        {
            for (int j = 0; j < i; j++)
            {
                x++;
                if (x <= 9)
                {
                    printf(" %d ", x);
                }
                else
                {
                    printf("%d ", x);
                }
            }
            printf("\n");
        }
    }

    return 0;
}