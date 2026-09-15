#include <stdio.h>

int parent[20];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

void unite(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    int graph[10][10];
    int n, i, j;
    int edges = 0, total = 0;
    int min, x, y, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = 9999;
        }

        parent[i] = i;
    }

    printf("Edges in MST:\n");

    while (edges < n - 1)
    {
        min = 9999;

        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        u = find(x);
        v = find(y);

        if (u != v)
        {
            printf("%d - %d : %d\n", x, y, min);

            total += min;
            unite(u, v);
            edges++;
        }

        graph[x][y] = 9999;
        graph[y][x] = 9999;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}
