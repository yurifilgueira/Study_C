#include <stdio.h>
#include <stdbool.h>

bool ehPar(int numb)
{
    if (numb % 2 == 0)
    {
        bool aws = true;
        return (aws);
    }
    else
    {
        bool aws = false;
        return (aws);
    }
}

int main()
{
    int numb;

    scanf("%d", &numb);

    bool aws = ehPar(numb);

    if (aws == true)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return (0);
}