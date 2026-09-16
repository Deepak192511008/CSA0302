#include <stdio.h>

int cost[10][10];
int visited[10];
int n;
int minCost = 9999;

void tsp(int current, int count, int total)
{
    int i;

    if (count == n)
    {
        total = total + cost[current][0];

        if (total < minCost)
            minCost = total;

        return;
    }

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;

            tsp(i, count + 1, total + cost[current][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    printf("Minimum cost = %d", minCost);

    return 0;
}
