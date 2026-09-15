#include <stdio.h>

int main()
{
    int graph[10][10];
    int visited[10] = {0};
    int queue[10];
    int n, start;
    int front = 0, rear = 0;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear)
    {
        int v = queue[front++];

        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
