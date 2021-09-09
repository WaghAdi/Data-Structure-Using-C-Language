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
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d=>", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int countNode(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count += 1;
        head = head->next;
    }
    return count;
}

void reverseDisplay(struct node *tail)
{
    if (tail == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while (tail != NULL)
        {
            printf("%d=>", tail->data);
            tail = tail->prev;
        }
        printf("\n");
    }
}

void insertAtFirst(struct node **head, struct node **tail)
{
    struct node *newNode = NULL;
    newNode = createNode();
    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtPosition(struct node **head, struct node **tail)
{
    int position;
    int n = countNode(*head);
lable:
    printf("Enter Position\n");
    scanf("%d", &position);
    if (position == 1)
    {
        insertAtFirst(head, tail);
    }
    else if (position == (n + 1))
    {
        createLinkedList(head, tail);
    }
    else if (position > 1 && position < (n + 1))
    {
        struct node *newNode = NULL;
        newNode = createNode();
        struct node *temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    else
    {
        printf("Invalid position try again\n");
        goto lable;
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
        printf("3 reverseDisplay\n");
        printf("4 insertAtFirst\n");
        printf("5 insertAtLastt\n");
        printf("6 insertAtPosition\n");
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
            insertAtPosition(&first, &last);
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
