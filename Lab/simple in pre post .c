#include <stdio.h>

int tree[100];
int n;

void inorder(int i)
{
    if (i < n)
    {
        inorder(2 * i + 1);
        printf("%d ", tree[i]);
        inorder(2 * i + 2);
    }
}

void preorder(int i)
{
    if (i < n)
    {
        printf("%d ", tree[i]);
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }
}

void postorder(int i)
{
    if (i < n)
    {
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        printf("%d ", tree[i]);
    }
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    i = 0;

    while (i < n)
    {
        scanf("%d", &tree[i]);
        i++;
    }

    printf("Inorder: ");
    inorder(0);

    printf("\nPreorder: ");
    preorder(0);

    printf("\nPostorder: ");
    postorder(0);

    return 0;
}
