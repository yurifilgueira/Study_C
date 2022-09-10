#include <stdio.h>

int main()
{

    int number, modified_number, x = 0;
    int digits[x];

    scanf("%d", &number);
    int copy_number = number;
    modified_number = number;

    while (modified_number > 0)
    {
        digits[x] = modified_number % 10;
        modified_number /= 10;
        x++;
    }

    int palindrome = 1;

    for (int i = 0; i < x; i++)
    {
        int a = digits[i];
        int b = digits[x - (i + 1)];
        if (digits[i] != digits[x - (i + 1)])
        {
            palindrome = 0;
        }
    }

    if (palindrome == 1)
    {
        if ((copy_number % 2) != 0)
        {
            printf("%d é Palíndromo e impar.", copy_number);
        }
        else
        {
            printf("%d é Palíndromo e par.", copy_number);
        }
    }
    else
    {
        if ((copy_number % 2) != 0)
        {
            printf("%d não é Palíndromo e impar.", copy_number);
        }
        else
        {
            printf("%d não é Palíndromo e par.", copy_number);
        }
    }

    return 0;
}