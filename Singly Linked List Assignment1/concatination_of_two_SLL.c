#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *creteNode()
{
    struct node *newNode = NULL;
    int value;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory not alloctated\n");
    }
    else
    {
        printf("Memory allocted\n");
        printf("enter data\n");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

void creteLinkedList(struct node **head1, struct node **head2)
{
    struct node *newNode = NULL;
    int choice;
    newNode = creteNode();
lable:
    printf("enter your choice either to add node to linked list 1 or 2\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        struct node *temp = *head1;
        if (*head1 == NULL)
        {
            *head1 = newNode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    else if (choice == 2)
    {
        struct node *temp = *head2;
        if (*head2 == NULL)
        {
            *head2 = newNode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    else
    {
        printf("Invalid choice\n");
        goto lable;
    }
}
void Display1(struct node *head1)
{
    if (head1 == NULL)
    {
        printf("LInked list 1 is empty\n");
    }
    while (head1 != NULL)
    {
        printf("%d=>", head1->data);
        head1 = head1->next;
    }
    printf("\n");
}
void Display2(struct node *head2)
{
    if (head2 == NULL)
    {
        printf("LInked list 2 is empty\n");
    }
    while (head2 != NULL)
    {
        printf("%d=>", head2->data);
        head2 = head2->next;
    }
    printf("\n");
}
void Display3(struct node *head3)
{
    if (head3 == NULL)
    {
        printf("LInked list 3 is empty\n");
    }
    while (head3 != NULL)
    {
        printf("%d=>", head3->data);
        head3 = head3->next;
    }
    printf("\n");
}
void concatination(struct node *head1, struct node *head2, struct node **head3)
{
    if (head1 == NULL)
    {
        *head3 = head2;
    }
    else if (head2 == NULL)
    {
        *head3 = head1;
    }
    else if (head1 == NULL && head2 == NULL)
    {
        *head3 = NULL;
    }
    else
    {
        struct node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        *head3 = head1;
    }
}

void main()
{
    int choice;
    struct node *first1 = NULL;
    struct node *first2 = NULL;
    struct node *first3 = NULL;
    do
    {
        printf("1: Create Linked List\n");
        printf("2: Display Linked List 1\n");
        printf("3: Display Linked List 2\n");
        printf("4: Display Linked List 3\n");
        printf("5:Concatinate linked list\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creteLinkedList(&first1, &first2);
            break;
        case 2:
            Display1(first1);
            break;
        case 3:
            Display2(first2);
            break;
        case 4:
            Display2(first3);
            break;
        case 5:
            concatination(first1, first2, &first3);
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