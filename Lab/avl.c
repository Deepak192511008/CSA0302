#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int getBalance(struct Node *root)
{
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

/* Right Rotation */
struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

/* Left Rotation */
struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

/* Insert */
struct Node* insert(struct Node *root, int value)
{
    int balance;

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + max(height(root->left),
                            height(root->right));

    balance = getBalance(root);

    /* LL Case */
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    /* RR Case */
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    /* LR Case */
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* RL Case */
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* Find minimum node */
struct Node* minValueNode(struct Node *root)
{
    struct Node *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Delete */
struct Node* deleteNode(struct Node *root, int value)
{
    int balance;

    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        /* No child */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        /* One child */
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        /* Two children */
        else
        {
            struct Node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }

    root->height = 1 + max(height(root->left),
                            height(root->right));

    balance = getBalance(root);

    /* LL */
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    /* LR */
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* RR */
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    /* RL */
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* Search */
void search(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if (root->data == key)
    {
        printf("Element found\n");
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

/* Inorder */
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    int choice;
    int value;

    while (1)
    {
        printf("\n--- AVL TREE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Inorder\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter value: ");
                scanf("%d", &value);

                root = insert(root, value);

                break;

            case 2:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                break;

            case 3:

                printf("Enter value to search: ");
                scanf("%d", &value);

                search(root, value);

                break;

            case 4:

                printf("Inorder: ");
                inorder(root);
                printf("\n");

                break;

            case 5:

                return 0;

            default:

                printf("Invalid choice\n");
        }
    }
}
