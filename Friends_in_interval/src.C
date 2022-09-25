#include <stdio.h>
#include <stdbool.h>

bool divisible(int numb, int denominator)
{
    if (numb % denominator == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumDivisor(int numb)
{
    int sum = 0;
    for (int i = 1; i < numb; i++)
    {
        if (divisible(numb, i) == true)
        {
            sum += i;
        }
    }
    return sum;
}

bool isFriend(int numb1, int numb2)
{

    if (sumDivisor(numb2) == numb1 && sumDivisor(numb1) == numb2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int numb1, numb2, numb3, numb4, qttFriends = 0;

    scanf("%d %d %d %d", &numb1, &numb2, &numb3, &numb4);

    for (int i = numb1; i <= numb2; i++)
    {
        for (int j = numb3; j <= numb4; j++)
        {
            if (i != j)
            {
                if (isFriend(i, j) == true)
                {
                    printf("O %d possui um amigo!\n", i);
                    qttFriends++;
                }
            }
        }
    }

    if (qttFriends == 0)
    {
        printf("Os intervalos nao apresentam amigos!\n");
    }

    return 0;
}