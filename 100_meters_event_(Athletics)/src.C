#include <stdio.h>

int main()
{
    int qttAthletes = 0, qttSeries = 0, minimumNumberOfAthletesForASeries = 0;
    double timeOfAthlete = 0;

    double maxTime = 0;
    scanf("%lf", &maxTime);

    while (timeOfAthlete >= 0)
    {
        scanf("%lf", &timeOfAthlete);

        if (timeOfAthlete > 0 && timeOfAthlete <= maxTime)
        {
            qttAthletes++;
            if (qttAthletes > minimumNumberOfAthletesForASeries)
            {
                qttSeries++;
                minimumNumberOfAthletesForASeries += 8;
            }
        }
    }

    printf("%d %d", qttAthletes, qttSeries);

    return 0;
}