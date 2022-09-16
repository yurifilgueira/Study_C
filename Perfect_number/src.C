#include <stdio.h>
#include <stdbool.h>

bool ehPerfeito(int numb)
{
    int sum = 0;
    bool aws = false;
    for (int i = 1; i < numb; i++)
    {
        if (numb % i == 0)
        {
            sum += i;
        }
    }
    if (sum == numb)
    {
        aws = true;
    }

    return (aws);
}

int main()
{
    int qttNumb, numb;

    scanf("%d", &qttNumb);

    for (int i = 0; i < qttNumb; i++)
    {
        scanf("%d", &numb);
        bool aws = ehPerfeito(numb);
        if (aws == true)
        {
            printf("%d eh perfeito\n", numb);
        }
        else
        {
            printf("%d nao eh perfeito\n", numb);
        }
    }
}