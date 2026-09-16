#include <stdio.h>

int q1[50], q2[50];
int f1 = 0, r1 = 0;
int f2 = 0, r2 = 0;

void push(int x)
{
    int temp;

    q2[r2++] = x;

    while (f1 < r1)
    {
        q2[r2++] = q1[f1++];
    }

    temp = f1;
    f1 = f2;
    f2 = temp;

    temp = r1;
    r1 = r2;
    r2 = temp;

    f2 = 0;
    r2 = 0;
}

void pop()
{
    if (f1 == r1)
        printf("Stack is empty\n");
    else
        printf("Popped: %d\n", q1[f1++]);
}

int main()
{
    push(10);
    push(20);
    push(30);

    pop();
    pop();
    pop();

    return 0;
}
