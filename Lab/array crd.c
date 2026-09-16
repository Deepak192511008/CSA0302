#include <stdio.h>

int main()
{
    int a[100], n, i, ch, pos, val;

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
        {
            scanf("%d%d", &pos, &val);

            for(i=n; i>pos; i--)
                a[i] = a[i-1];

            a[pos] = val;
            n++;
        }
        else if(ch == 2)
        {
            scanf("%d", &pos);

            for(i=pos; i<n-1; i++)
                a[i] = a[i+1];

            n--;
        }
        else if(ch == 3)
        {
            for(i=0; i<n; i++)
                printf("%d ", a[i]);
        }
        else
            break;
    }

    return 0;
}
