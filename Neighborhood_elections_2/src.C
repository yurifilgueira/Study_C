#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int identifier;
    char name[200];
    int numbOfVotes;
} Party;

void computeVotes(int m, int votes[], int n, Party parties[], Party *mostVoted, Party *secondMostVoted, int *validVotes)
{
    int valid = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (votes[j] == parties[i].identifier)
            {
                parties[i].numbOfVotes++;
                valid++;
            }
        }
    }

    *validVotes = valid;

    int numbMostVoted = 0;
    int numbSecondMostVoted = 0;

    for (int i = 0; i < n; i++)
    {
        if (numbMostVoted < parties[i].numbOfVotes)
        {
            numbMostVoted = parties[i].numbOfVotes;
            *mostVoted = parties[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (numbSecondMostVoted < parties[i].numbOfVotes && parties[i].numbOfVotes < numbMostVoted)
        {
            numbSecondMostVoted = parties[i].numbOfVotes;
            *secondMostVoted = parties[i];
        }
    }
}

int main()
{
    int n; // Number of parties
    scanf("%d", &n);

    Party parties[n];
    Party mostVoted, secondMostVoted;

    for (int j = 0; j < n; j++)
    {
        scanf("%d %s", &parties[j].identifier, parties[j].name);
        parties[j].numbOfVotes = 0;
    }

    int m; // Number of votes
    scanf("%d", &m);
    int votes[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &votes[i]);
    }

    int validVotes;

    computeVotes(m, votes, n, parties, &mostVoted, &secondMostVoted, &validVotes);

    double percentageWinner = ((double)(mostVoted.numbOfVotes * 100) / validVotes);
    double percentageVice = ((double)(secondMostVoted.numbOfVotes * 100) / validVotes);

    printf("VENCEDOR: %s (%d votos = %.2f%%)\n", mostVoted.name, mostVoted.numbOfVotes, percentageWinner);
    printf("VICE: %s (%d votos = %.2f%%)\n", secondMostVoted.name, secondMostVoted.numbOfVotes, percentageVice);

    return 0;
}