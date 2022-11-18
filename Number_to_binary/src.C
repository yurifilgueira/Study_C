#include <iostream>
#include <stdio.h>

void numberToBinary(int numb)
{
    if (numb / 2 != 0)
    {
        numberToBinary(numb / 2);
    }

    printf("%d", (numb % 2));
}

int main()
{
    int numb;
    scanf("%d", &numb);

    numberToBinary(numb);

    return 0;
}
