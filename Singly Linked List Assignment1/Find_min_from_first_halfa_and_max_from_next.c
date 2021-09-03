#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next; //self refrential structure
};

struct node *createNode()
{
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("Memory allocated\n");
        int val;
        printf("Enter value\n");
        scanf("%d", &val);
        newNode->data = val;
        newNode->next = NULL;
    }
    return newNode;
}
void creatLinkedList(struct node **head)
{
    struct node *newNode = NULL;
    newNode = createNode();
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *temp = NULL;
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int countNode(struct node *head)
{
    int nodeCount = 0;
    while (head != NULL)
    {
        nodeCount += 1;
        head = head->next;
    }
    return nodeCount;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("LInked List is empty\n");
    }
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}

void min_max(struct node *head)
{
    int total = countNode(head);
    int firstHalf = total / 2;
    int secondHalf = total - firstHalf;
    int min = head->data;
    for (int i = 0; i < firstHalf-1; i++)
    {
        if (head->data < min)
        {
            min = head->data;
        }
        head = head->next;
    }
    printf("Minimum value is %d\n", min);
    int max = head->data;
    for (int i = 0; i < secondHalf; i++)
    {
        if (head->data > max)
        {
            max = head->data;
        }
        head = head->next;
    }
    printf("Maximum value is %d\n", max);
}

void main()
{
    int choice;
    struct node *first = NULL;
    do
    {
        printf("1: Create Linked List\n");
        printf("2: Display Linked List\n");
        printf("3:find min and max\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creatLinkedList(&first);
            break;
        case 2:
            display(first);
            break;
        case 3:
            min_max(first);
            break;
        case 0:
            printf("THANK YOU\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 0);
}