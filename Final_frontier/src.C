#include <stdio.h>

int main()
{
    int n, m;
    int qttWater = 0, qttDesertArea = 0, qttVegetationArea = 0, qttNoNaturalResources = 0;

    scanf("%d %d", &n, &m);

    char map[n][m];

    int itsX = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            while (itsX != 1)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'X')
                {
                    printf("Planeta hostil");
                    itsX = 1;
                }
                else if (map[i][j] == '~')
                {
                    qttWater++;
                }
                else if (map[i][j] == '^')
                {
                    qttDesertArea++;
                }
                else if (map[i][j] == '^')
                {
                    qttDesertArea++;
                }
                else if (map[i][j] == '*')
                {
                    qttVegetationArea++;
                }
                else if (map[i][j] == '.')
                {
                    qttNoNaturalResources++;
                }
            }
        }
    }
}