#include <stdio.h>

#define INF 9999

int main()
{
    int graph[10][10];
    int selected[10] = {0};
    int n, i, j, edges = 0;
    int min, x, y, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
        }
    }

    selected[0] = 1;

    printf("Edges in MST:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, min);

        total += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}
