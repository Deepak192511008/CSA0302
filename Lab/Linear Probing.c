#include <stdio.h>

int main()
{
    int h[10], n, x, i, p;

    for(i=0; i<10; i++)
        h[i] = -1;

    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &x);

        p = x % 10;

        while(h[p] != -1)
            p = (p + 1) % 10;

        h[p] = x;
    }

    for(i=0; i<10; i++)
    {
        if(h[i] != -1)
            printf("%d -> %d\n", i, h[i]);
    }

    return 0;
}
