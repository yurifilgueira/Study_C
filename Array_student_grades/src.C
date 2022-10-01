#include <stdio.h>

int main()
{

    int sQ; // sQ == studentsQtt;

    scanf("%d", &sQ);

    double studentsGrades[sQ], apr[sQ], rec[sQ], rep[sQ];

    for (int i = 0; i < sQ; i++)
    {
        printf("%d-", (i + 1));
        scanf("%lf", &studentsGrades[i]);
    }

    for (int i = 0; i < sQ; i++)
    {
        if (studentsGrades[i] >= 7.0)
        {
            apr[i] = studentsGrades[i];
        }
        else if (studentsGrades[i] < 7.0 && studentsGrades[i] >= 5)
        {
            rec[i] = studentsGrades[i];
        }
        else
        {
            rep[i] = studentsGrades[i];
        }
    }

    printf("Aprovados:");
    for (int i = 0; i < sQ; i++)
    {
        if (studentsGrades[i] == apr[i])
        {
            printf("%d (%.2lf),", (i + 1), apr[i]);
        }
    }

    printf("\n");

    printf("Recuperação:");
    for (int i = 0; i < sQ; i++)
    {
        if (studentsGrades[i] == rec[i])
        {
            printf("%d (%.2lf),", (i + 1), rec[i]);
        }
    }

    printf("\n");

    printf("Reprovados:");
    for (int i = 0; i < sQ; i++)
    {
        if (studentsGrades[i] == rep[i])
        {
            printf("%d (%.2lf),", (i + 1), rep[i]);
        }
    }

    return 0;
}