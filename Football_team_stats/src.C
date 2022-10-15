#include <stdio.h>
#include <string.h>

void flush_in()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}

struct Team
{
    char name[200];
    int goalsScored;
    int goalsConceded;
};

void printSortTeams(struct Team *teams, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d - %s", (i + 1), teams[i].name);
        printf("Gols marcados: %d\n", teams[i].goalsScored);
        printf("Gols sofridos: %d\n", teams[i].goalsConceded);
    }
}

void sortTeams(struct Team *teams, int n, int *whoCameFirst)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (teams[i].goalsScored > teams[j].goalsScored || teams[i].goalsScored == teams[j].goalsScored && whoCameFirst[i] < whoCameFirst[j])
            {
                int biggerGoalsScored = teams[j].goalsScored;
                int smallerGoalsScored = teams[i].goalsScored;
                teams[i].goalsScored = biggerGoalsScored;
                teams[j].goalsScored = smallerGoalsScored;

                int biggerGoalsConceded = teams[j].goalsConceded;
                int smallerGoalsConceded = teams[i].goalsConceded;
                teams[i].goalsConceded = biggerGoalsConceded;
                teams[j].goalsConceded = smallerGoalsConceded;

                char biggerName[200];
                char smallerName[200];
                strcpy(biggerName, teams[j].name);
                strcpy(smallerName, teams[i].name);
                strcpy(teams[j].name, smallerName);
                strcpy(teams[i].name, biggerName);
            }
        }
    }
    printSortTeams(teams, n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int whoCameFirst[n];

    struct Team teams[n];

    for (int i = 0; i < n; i++)
    {
        flush_in();
        fgets(teams[i].name, 200, stdin);
        scanf("%d %d", &teams[i].goalsScored, &teams[i].goalsConceded);
        whoCameFirst[i] = i;
    }

    sortTeams(teams, n, whoCameFirst);

    return 0;
}