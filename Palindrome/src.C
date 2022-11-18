#include <stdio.h>
#include <string.h>

int palindrome(char *input)
{
    int i = 0, j = strlen(input) - 1;

    while (i < j)
    {
        if (input[i] == ' ')
        {
            i++;
        }
        else if (input[j] == ' ')
        {
            j--;
        }
        else if (input[i] != input[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }

    return 1;
}

int main()
{
    char input[200];
    scanf("%[^\n]", input);

    if (palindrome(input))
    {
        printf("O texto \"%s\" é palíndromo", input);
    }
    else
    {
        printf("O texto \"%s\" não é palíndromo", input);
    }

    return 0;
}