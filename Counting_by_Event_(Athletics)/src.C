#include <stdio.h>
int main()
{

    char modality;
    int qttTeams, qttAthletesRace = 0, qttAthletesJump = 0, qttAthletesThrow = 0, totalAthletes = 0;

    scanf("%d", &qttTeams);
    for (int i = 0; i < qttTeams; i++)
    {
        scanf("%c", &modality);

        while (modality != 'F' || modality != 'f')
        {
            if (modality == 'C' || modality == 'c')
            {
                qttAthletesRace++;
            }
            else if (modality == 'S' || modality == 's')
            {
                qttAthletesJump++;
            }
            else if (modality == 'L' || modality == 'l')
            {
                qttAthletesThrow++;
            }

            scanf("%c", &modality);
        }
    }

    totalAthletes += (qttAthletesRace + qttAthletesJump + qttAthletesThrow);

    printf("%d %d %d %d", qttAthletesRace, qttAthletesJump, qttAthletesThrow, totalAthletes);

    return 0;
}
