#include <stdio.h>

int main()
{
    int a[100], n, i, large, second;

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    large = second = -99999;

    for(i=0; i<n; i++)
    {
        if(a[i] > large)
        {
            second = large;
            large = a[i];
        }
        else if(a[i] > second && a[i] != large)
            second = a[i];
    }

    printf("%d", second);

    return 0;
}
