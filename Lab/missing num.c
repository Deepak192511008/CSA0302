#include <stdio.h>

int main()
{
    int a[100], n, i;
    int sum = 0, expected, missing;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n - 1);

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    expected = n * (n + 1) / 2;

    missing = expected - sum;

    printf("Missing element = %d", missing);

    return 0;
}
