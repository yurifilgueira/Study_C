#include <stdio.h>

int main()
{

    int number, modified_number, x = 0;
    int digits[x];

    scanf("%d", &number);
    modified_number = number;

    while (modified_number > 0)
    {
        digits[x] = modified_number % 10;
        modified_number /= 10;
        x++;
    }

    int palindrome = 0;

    for (int i = 0; i < x; i++)
    {
        if (digits[i] == digits[x - (i + 1)])
        {
            palindrome = 1;
        }
    }

    if (palindrome == 1)
    {
        if ((number % 2) != 0)
        {
            printf("%d é Palíndromo e impar.", number);
        }
        else
        {
            printf("%d é Palíndromo e par.", number);
        }
    }
    else
    {
        if ((number % 2) != 0)
        {
            printf("%d Não é Palíndromo e impar.", number);
        }
        else
        {
            printf("%d Não é Palíndromo e par.", number);
        }
    }

    return 0;
}