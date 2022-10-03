#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, m;
    int qttWater = 0, qttDesertArea = 0, qttVegetationArea = 0, qttNoNaturalResources = 0;

    scanf("%d %d", &n, &m);

    char map[n][m];
    double areaPlanet = n * m;
    double percWater, percDesert, percVegetation;

    bool hostil = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &map[i][j]);
            if (hostil == false)
            {
                if (map[i][j] == 'X')
                {
                    printf("Planeta Hostil");
                    hostil = true;
                }
                else if (map[i][j] == '~')
                {
                    qttWater++;
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

    if (hostil == false)
    {
        percWater = (double)(100 * qttWater) / areaPlanet;
        percDesert = (double)(100 * qttDesertArea) / areaPlanet;
        percVegetation = (double)(100 * qttVegetationArea) / areaPlanet;

        if (percWater >= 50 && percVegetation >= 20)
        {
            printf("Planeta Classe M");
            printf("", percWater, percDesert, percVegetation);
        }
        else if (percWater >= 85)
        {
            printf("Planeta Aquático");
        }
        else if (percDesert >= 60)
        {
            printf("Planeta Desértico");
        }
        else if (percVegetation >= 65)
        {
            printf("Planeta Selvagem");
        }
        else
        {
            printf("Planeta Inóspito");
        }
    }

    return 0;
}