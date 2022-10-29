#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

typedef struct
{
    char name[200];
    int victories;
    int defeats;
    int draws;
    int goalsScored;
    int goalsAgainst;
} Team;

Team enterTeams(Team *teams, int qtt)
{
    for (int i = 0; i < qtt; i++)
    {
        scanf("%[^;]; %d %d %d %d %d", teams[i].name, &teams[i].victories, &teams[i].draws, &teams[i].defeats, &teams[i].goalsScored, &teams[i].goalsAgainst);
    }
    return *teams;
}

int points(Team team)
{
    return team.victories * 3 + team.draws;
}

int goalDifference(Team team)
{
    return team.goalsScored - team.goalsAgainst;
}

void sortTeams(Team teams[], int qtt)
{
    for (int i = 0; i < qtt; i++)
    {
        for (int j = i + 1; j < qtt; j++)
        {
            if (points(teams[i]) < points(teams[j]))
            {
                Team aux = teams[i];
                teams[i] = teams[j];
                teams[j] = aux;
            }
            else if (points(teams[i]) == points(teams[j]))
            {
                if (teams[i].victories < teams[j].victories)
                {
                    Team aux = teams[i];
                    teams[i] = teams[j];
                    teams[j] = aux;
                }
                else if (teams[i].victories == teams[j].victories && goalDifference(teams[i]) < goalDifference(teams[j]))
                {
                    Team aux = teams[i];
                    teams[i] = teams[j];
                    teams[j] = aux;
                }
            }
        }
    }
}

void printTeams(Team teams[], int qtt)
{
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols");
    for (int i = 0; i < qtt; i++)
    {
        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d", teams[i].name, points(teams[i]), teams[i].victories + teams[i].defeats + teams[i].draws, teams[i].victories, teams[i].draws, teams[i].defeats, teams[i].goalsScored, teams[i].goalsAgainst, goalDifference(teams[i]));
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    Team teams[t];

    teams[t] = enterTeams(teams, t);

    sortTeams(teams, t);

    printTeams(teams, t);

    printf("\n\n");
    printf("Times na zona da libertadores:");
    for (int i = 0; i < 6; i++)
    {
        printf("%s", teams[i].name);
    }

    printf("\n\n");
    printf("Times rebaixados:");
    for (int i = t - 1; i > t - 5; i--)
    {
        printf("%s", teams[i].name);
    }

    return 0;
}