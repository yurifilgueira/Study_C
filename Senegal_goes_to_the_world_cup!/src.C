#include <stdio.h>

int calculateBet(int height, int large, int flag[large][height])
{
    int value = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (large / 3); j++)
        {
            value += flag[i][j];
        }
    }
    return value;
}

int main()
{
    int large;
    scanf("%d", &large);
    int height = 2 * (large / 3);
    int initialNumber;
    scanf("%d", &initialNumber);
    char color;
    scanf(" %c", &color);
    int flagFirstColor[height][large];
    int flagSecondtColor[height][large];
    int flagThirdyColor[height][large];
    int sum = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (large / 3); j++)
        {
            flagFirstColor[i][j] = initialNumber + sum;
        }
    }

    sum++;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (large / 3); j++)
        {
            flagSecondtColor[i][j] = initialNumber + sum;
        }
    }

    sum++;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (large / 3); j++)
        {
            flagThirdyColor[i][j] = initialNumber + sum;
        }
    }

    int value = 0;
    if (color == 'G')
    {
        value = calculateBet(large, height, flagFirstColor);
    }
    else if (color == 'Y')
    {
        value = calculateBet(large, height, flagSecondtColor);
    }
    else if (color == 'R')
    {
        value = calculateBet(large, height, flagThirdyColor);
    }

    printf("%d", value);
}