#include <stdio.h>
#include <stdlib.h>

void sortNumbs(int numbs[], int size)
{

    int i, j, temp;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (numbs[i] > numbs[j])
            {
                temp = numbs[i];
                numbs[i] = numbs[j];
                numbs[j] = temp;
            }
        }
    }
}

void printNumbs(int numbs[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", numbs[i]);
    }
}

int main()
{

    int numb = 0;
    int *numbs;
    int qttNumbs = 0;
    numbs = (int *)malloc(1);

    while (scanf("%d", &numb) != EOF)
    {
        numbs[qttNumbs] = numb;
        qttNumbs++;
        numbs = (int *)realloc(numbs, qttNumbs + 1);
    }

    sortNumbs(numbs, qttNumbs);
    printNumbs(numbs, qttNumbs);

    return 0;
}