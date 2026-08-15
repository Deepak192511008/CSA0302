#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert after a particular value
void insertAfter(int value, int afterValue)
{
    struct Node *newNode;
    struct Node *temp;

    temp = head;

    // Find the node after which we want to insert
    while (temp != NULL && temp->data != afterValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("%d not found in the list.\n", afterValue);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    // Connect new node to the next node
    newNode->next = temp->next;

    // Connect previous node to new node
    temp->next = newNode;

    printf("%d inserted successfully.\n", value);
}

// Insert at end
void insertEnd(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted successfully.\n");
}

// Display list
void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;
    int value;
    int afterValue;

    while (1)
    {
        printf("\n--- LINKED LIST OPERATIONS ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert in Between\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter value: ");
                scanf("%d", &value);

                insertBeginning(value);

                break;

            case 2:

                printf("Enter value to insert: ");
                scanf("%d", &value);

                printf("Insert after which value? ");
                scanf("%d", &afterValue);

                insertAfter(value, afterValue);

                break;

            case 3:

                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(value);

                break;

            case 4:

                deleteBeginning();

                break;

            case 5:

                display();

                break;

            case 6:

                return 0;

            default:

                printf("Invalid choice.\n");
        }
    }

    return 0;
}
