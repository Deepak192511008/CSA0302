#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct Node));

        root->data = value;
        root->left = NULL;
        root->right = NULL;

        return root;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root, int k, int *count, int *answer)
{
    if (root == NULL)
        return;

    inorder(root->left, k, count, answer);

    (*count)++;

    if (*count == k)
    {
        *answer = root->data;
        return;
    }

    inorder(root->right, k, count, answer);
}

int main()
{
    struct Node *root = NULL;
    int n, i, value;
    int k, count = 0, answer = -1;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    inorder(root, k, &count, &answer);

    if (answer != -1)
        printf("%dth minimum = %d", k, answer);
    else
        printf("Invalid k");

    return 0;
}
