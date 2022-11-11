#include <stdio.h>
#include <string.h>

typedef struct
{
    int qttNumb;
    int numbs[200];
} set;

set unionSets(set *setA, set *setB)
{
    set auxSetA = *setA, auxSetB = *setB;
    set unionSetsAB;
    int totalNumbers = auxSetA.qttNumb + auxSetB.qttNumb;

    if (auxSetA.qttNumb == 0)
    {
        unionSetsAB = *setB;
    }
    else if (auxSetB.qttNumb == 0)
    {
        unionSetsAB = *setA;
    }
    else
    {
        unionSetsAB = *setA;
        for (int i = 1; i <= auxSetA.qttNumb; i++)
        {
            for (int j = auxSetA.qttNumb + 1; j <= totalNumbers; j++)
            {
                if (unionSetsAB.numbs[i] == auxSetB.numbs[j])
                {
                    auxSetB.numbs[j] = -1;
                    auxSetB.qttNumb--;
                }
            }
        }

        int inc = auxSetA.qttNumb + 1;
        for (int j = auxSetA.qttNumb + 1; j <= totalNumbers; j++)
        {
            if (auxSetB.numbs[j] != -1)
            {
                unionSetsAB.numbs[inc] = auxSetB.numbs[j];
                inc++;
            }
        }

        unionSetsAB.qttNumb += auxSetB.qttNumb;
    }

    return unionSetsAB;
}

set intersectionSets(set *setA, set *setB)
{
    set auxSetA = *setA, auxSetB = *setB;
    set intersectionSetsAB;
    intersectionSetsAB.qttNumb = 0;
    int totalNumbers = auxSetA.qttNumb + auxSetB.qttNumb;
    int x = 0;

    for (int j = auxSetA.qttNumb + 1; j <= totalNumbers; j++)
    {
        for (int i = 1; i <= auxSetA.qttNumb; i++)
        {
            if (auxSetA.numbs[i] == auxSetB.numbs[j])
            {
                x++;
                intersectionSetsAB.numbs[x] = auxSetB.numbs[j];
                intersectionSetsAB.qttNumb++;
            }
        }
    }

    return intersectionSetsAB;
}

void printNumbers(set operation)
{
    char space = ' ';
    for (int i = 1; i <= operation.qttNumb; i++)
    {
        printf("%d", operation.numbs[i]);
        if (operation.qttNumb > i)
        {
            printf("%c", space);
        }
    }
}

int main()
{
    int numbSetA;
    scanf("%d", &numbSetA);

    set setA;

    setA.qttNumb = numbSetA;
    for (int i = 1; i <= numbSetA; i++)
    {
        scanf("%d", &setA.numbs[i]);
    }

    int numbSetB;
    scanf("%d", &numbSetB);

    set setB;
    setB.qttNumb = numbSetB;
    for (int i = numbSetA + 1; i <= (numbSetB + numbSetA); i++)
    {
        scanf("%d", &setB.numbs[i]);
    }

    if (setA.qttNumb > 0 || setB.qttNumb > 0)
    {
        set unionAB = unionSets(&setA, &setB);
        printf("A união B == {");
        printNumbers(unionAB);
        printf("}\n");

        if (setA.qttNumb > 0 && setB.qttNumb > 0)
        {
            set intersectionAB;
            intersectionAB.qttNumb = 0;
            intersectionAB = intersectionSets(&setA, &setB);
            printf("A interseção B == {");
            printNumbers(intersectionAB);
            printf("}");
        }
        else
        {
            printf("A interseção B == {vazio}");
        }
    }
    else
    {
        printf("A união B == {vazio}\n");
        printf("A interseção B == {vazio}\n");
    }

    return 0;
}