#include <stdio.h>

int s1[50], s2[50];
int top1 = -1, top2 = -1;

void enqueue(int x)
{
    s1[++top1] = x;
}

void dequeue()
{
    int x;

    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    if (top2 == -1)
    {
        while (top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    x = s2[top2--];

    printf("Deleted: %d\n", x);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();
    dequeue();

    return 0;
}
