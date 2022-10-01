#include <stdio.h>

int main()
{
    int n, layer = 2;

    scanf("%d", &n);
    int p[n][n];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int aws = 0;
            if (i == 1 || j == 1 || i == n || j == n)
            {
                p[i][j] = 1;
                aws = 1;
            }
            if (aws == 0)
            {
                if (i > 1 && j > 1 || i < n && j < n)
                {
                    if (i == j && j + 1 < n && i != 2)
                    {
                        layer++;
                        p[i][j] = layer;
                    }
                    else
                    {
                        p[i][j] = layer;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}