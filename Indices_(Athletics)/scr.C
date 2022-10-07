#include <stdio.h>

int main()
{
    int n;
    double sum = 0, qttYear = 0, year;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &year);
        if (year > -1)
        {
            sum += year;
            qttYear++;
        }
    }

    double average = (double)(sum / qttYear);

    if (average > 0)
    {
        printf("%.2lf", average);
    }
    else
    {
        printf("A competicao nao possui dados historicos!");
    }
}