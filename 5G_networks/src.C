#include <stdio.h>

void printRange(int n, int cells[], int user, int distance, int hasCells, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (cells[i] >= user - distance && cells[i] <= user + distance)
        {
            printf("%d ", cells[i]);
            hasCells = 1;
        }
    }

    if (hasCells == 0)
    {
        printf("USUARIO DESCONECTADO");
    }
}

int range(int n, int cells[], int distance, int user, int *leftIndex, int *rightIndex)
{
    int hasCells = 0;
    int left = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        if (user - distance <= cells[i])
        {
            left = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (user + distance >= cells[i])
        {
            right = i;
            break;
        }
    }

    *leftIndex = left;
    *rightIndex = right;

    printRange(n, cells, user, distance, hasCells, left, right);

    return 0;
}

int main()
{
    int n, d, u, leftIndex, rightIndex;

    scanf("%d %d %d", &n, &d, &u);

    int cells[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cells[i]);
    }

    range(n, cells, d, u, &leftIndex, &rightIndex);

    return 0;
}