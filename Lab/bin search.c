#include <stdio.h>

int main()
{
    int a[100], n, x, low, high, mid, i;

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == x)
        {
            printf("Element found at position %d", mid+1);
            return 0;
        }
        else if(a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element not found");

    return 0;
}
