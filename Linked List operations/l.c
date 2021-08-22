#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode()
{
    struct node *newnode = NULL;
    int value;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated\n");
    }
    else
    {
        printf("memory allocated\n");
        printf("Enter data to be enter\n");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

void createLinklist(struct node **head)
{
    struct node *newnode = NULL;
    newnode = createNode();
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = NULL;
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void displayLinklist(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("%d =>", temp->data);
        temp = temp->next;
    }
    // printf("\n");
}
void main()
{
    struct node *first = NULL;
    char ch;
    int choice;
    do
    {
        printf("Enter your choice\n");
        printf("1 Create LinkedList\n");
        printf("2 Display LinkedList\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createLinklist(&first);
            break;
        case 2:
            displayLinklist(&first);
            break;

        case 0:
            printf("Thank you\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

    } while (choice != 0);
}