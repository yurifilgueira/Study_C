#include <stdio.h>

int main()
{
    int n, m;
    int qttWater = 0, qttDesertArea = 0, qttVegetationArea = 0, qttNoNaturalResources = 0;

    scanf("%d %d", &n, &m);

    char map[n][m];
    int areaPlanet = n * m;
    double percWater, percDesert, percVegetation;

    int itsX = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (itsX == 0)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'X')
                {
                    printf("Planeta Hostil");
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

    if (itsX == 0)
    {
        percWater = areaPlanet / (100 * qttWater);
        percDesert = areaPlanet / (100 * qttDesertArea);
        percVegetation = areaPlanet / (100 * qttVegetationArea);

        if (percWater >= 50 && percVegetation >= 20)
        {
            printf("Planeta Classe M");
        }
        else if (percWater == 85)
        {
            printf("Planeta Aquático");
        }
        else if (percDesert == 60)
        {
            printf("Planeta Desértico");
        }
        else if (percVegetation == 65)
        {
            printf("Plneta Selvagem");
        }
        else
        {
            printf("Planeta Inóspito");
        }
    }

    return 0;
}