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

void search(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Not found\n");
        return;
    }

    if (root->data == key)
        printf("Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int minimum(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int maximum(struct Node *root)
{
    while (root->right != NULL)
        root = root->right;

    return root->data;
}

int main()
{
    struct Node *root = NULL;
    int n, i, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Minimum = %d\n", minimum(root));
    printf("Maximum = %d\n", maximum(root));

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(root, key);

    return 0;
}
