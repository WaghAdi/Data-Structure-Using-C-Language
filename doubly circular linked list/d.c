#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createNode()
{
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory not allcated\n");
    }
    else
    {
        int value;
        printf("Memory allocated successfully\n");
        printf("Enter data\n");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

void createLinkedList(struct node **head, struct node **tail)
{
    struct node *newNode = NULL;
    newNode = createNode();
    if (*head == NULL)
    {
        *head = *tail = newNode;
        newNode->next = *head;
        newNode->prev = *tail;
    }
    else
    {
        newNode->next = (*tail)->next;
        (*tail)->next->prev = newNode;
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    do
    {
        printf("%d=>", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void reverseDisplay(struct node *tail)
{
    struct node *temp = tail;
    do
    {
        printf("%d=>", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

void insertAtFirst(struct node **head, struct node **tail)
{
    struct node *newNode = NULL;
    newNode = createNode();
    if (*head == NULL)
    {
        *head = *tail = newNode;
        newNode->next = *head;
        newNode->prev = *tail;
    }
    else
    {
        newNode->next = (*tail)->next;
        (*tail)->next->prev = newNode;
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *head = newNode;
    }
}

void insertAtPosition(struct node *head, struct node *tail)
{
    if (head == NULL)
    {
        printf("LInked list is empty\n");
    }
    else
    {
        struct node *newNode = createNode();
        int value;
        int flag = 0;
        printf("Enter data after which you want to add node\n");
        scanf("%d", &value);
        struct node *temp = head;
        do
        {
            if (temp->data == value)
            {
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
                flag = 1;
                printf("node added successfully\n");
                break;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != head);
        if (flag = 0)
        {
            printf("data not found\n");
        }
    }
}

void main()
{
    int choice;
    struct node *first = NULL;
    struct node *last = NULL;
    do
    {
        printf("1 Create LinkedList\n");
        printf("2 Display\n");
        printf("3 Reverse Display\n");
        printf("4 insert at first\n");
        printf("5 insert at last\n");
        printf("6 insert at position\n");

        printf("0 Exit\n");

        printf("enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createLinkedList(&first, &last);
            break;

        case 2:
            display(first);
            break;

        case 3:
            reverseDisplay(last);
            break;
        case 4:
            insertAtFirst(&first, &last);
            break;
        case 5:
            createLinkedList(&first, &last);
            break;
        case 6:
            insertAtPosition(first, last);
            break;

        case 0:
            printf("Thank you\n");
            break;
        default:
            printf("invalid choice\n");
            break;
        }

    } while (choice != 0);
}
