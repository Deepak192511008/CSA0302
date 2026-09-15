#include <stdio.h>

#define INF 9999

int main()
{
    int graph[10][10];
    int dist[10], visited[10];
    int n, start;
    int i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("Enter 0 if there is no edge.\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
    {
        dist[i] = graph[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;

    for (count = 0; count < n - 1; count++)
    {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 0 &&
                dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printf("\nShortest distances:\n");

    for (i = 0; i < n; i++)
    {
        printf("From %d to %d = %d\n", start, i, dist[i]);
    }

    return 0;
}
