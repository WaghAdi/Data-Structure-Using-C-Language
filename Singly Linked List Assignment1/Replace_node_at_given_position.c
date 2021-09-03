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
void replaceNode(struct node **head)
{
    if (*head == NULL)
    {
        printf("LInked list is empty\n");
    }
    else
    {
        struct node *newNode = NULL;
        newNode = createNode();
        int nodeCount = countNode(*head);
        int position;
    lable:
        printf("Enter position\n");
        scanf("%d", &position);
        if (position == 1)
        {
            struct node *temp = *head;
            newNode->next = temp->next;
            *head = newNode;
            free(temp);
        }
        else if (position == nodeCount)
        {
            struct node *temp = NULL;
            struct node *temp1 = NULL;
            temp = *head;
            while (temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = newNode;
            free(temp);
        }
        else if (position < 1 || position > nodeCount)
        {
            printf("Invalide Position try again\n ");
            goto lable;
        }
        else
        {
            struct node *temp = NULL;
            struct node *temp1 = NULL;
            temp = *head;
            for(int i=1;i<position-1;i++)
            {
                temp=temp->next;
            }
            temp1=temp->next;
            newNode->next=temp1->next;
            temp->next=newNode;
            free(temp1);
            
        }
    }
}

void main()
{
    int choice;
    struct node *first = NULL;
    do
    {
        printf("1: Create Linked List\n");
        printf("2: Display Linked List\n");
        printf("3:Replace Node\n");

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
            replaceNode(&first);
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