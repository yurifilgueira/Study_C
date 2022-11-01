#include <stdio.h>

int main()
{

    int n, boring = 0;

    scanf("%d", &n);

    int vect[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vect[i]);
    }

    int aws;

    int qtt = 0;

    for (int i = 0; i < n; i++)
    {
        qtt++;
        if (qtt != n)
        {
            if ((vect[i] - vect[i + 1]) < 0)
            {
                aws = (vect[i] - vect[i + 1]) * (-1);
                if (aws % 2 != 0)
                {
                    boring = 1;
                }
            }
            else
            {
                if (vect[i] - vect[i + 1] % 2 != 0)
                {
                    boring = 1;
                }
            }
        }
    }

    if (boring == 0)
    {
        printf("Legal");
    }
    else
    {
        printf("Chato");
    }
}