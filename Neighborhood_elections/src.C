#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeVotes(int n, int votes[], int *mostVoted, int *secondMostVoted)
{
    int aux;
    int cand1 = 0, cand2 = 0, cand3 = 0, cand4 = 0, cand5 = 0, cand6 = 0, cand7 = 0, cand8 = 0, cand9 = 0, cand10 = 0;
    int candidateVet[11] = {0, cand1, cand2, cand3, cand4, cand5, cand6, cand7, cand8, cand9, cand10};
    for (int i = 1; i <= n; i++)
    {
        if (votes[i] == 1)
        {
            candidateVet[1]++;
        }
        else if (votes[i] == 2)
        {
            candidateVet[2]++;
        }
        else if (votes[i] == 3)
        {
            candidateVet[3]++;
        }
        else if (votes[i] == 4)
        {
            candidateVet[4]++;
        }
        else if (votes[i] == 5)
        {
            candidateVet[5]++;
        }
        else if (votes[i] == 6)
        {
            candidateVet[6]++;
        }
        else if (votes[i] == 7)
        {
            candidateVet[7]++;
        }
        else if (votes[i] == 8)
        {
            candidateVet[8]++;
        }
        else if (votes[i] == 9)
        {
            candidateVet[9]++;
        }
        else if (votes[i] == 10)
        {
            candidateVet[10]++;
        }
    }

    aux = 0;
    int mostQtt = 0;

    for (int i = 1; i <= 10; i++)
    {
        if (aux < candidateVet[i])
        {
            mostQtt = i;
            aux = candidateVet[i];
        }
    }

    *mostVoted = mostQtt;

    aux = 0;
    int secondMostQtt = 0;

    for (int i = 1; i <= 10; i++)
    {
        if (aux < candidateVet[i] && mostQtt != i)
        {
            secondMostQtt = i;
            aux = candidateVet[i];
        }
    }

    *secondMostVoted = secondMostQtt;
}

int main()
{
    int n;
    scanf("%d", &n);

    int votes[n];
    int mostVoted, secondMostVoted;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &votes[i]);
    }

    computeVotes(n, votes, &mostVoted, &secondMostVoted);

    printf("%d %d", mostVoted, secondMostVoted);

    return 0;
}