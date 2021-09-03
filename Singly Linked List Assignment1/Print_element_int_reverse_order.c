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
// void reverseDisplay(struct node *head)
// {
//     if (head == NULL)
//     {
//         printf("Linked list is empty\n");
//     }
//     else
//     {
//         int max = countNode(head);
//         do
//         {
//             struct node *temp=NULL;
//             int count=0;
//             temp=head;
//             while(temp!=NULL)
//             {
//                 count+=1;
//                 if(count==max)
//                 {
//                     printf("%d->",temp->data);
//                     max=max-1;
//                     break;
//                 }
//                 temp=temp->next;
//             }
//         }while(max>0);
//         printf("\n");
//     }
// }

void reverseDisplay(struct node *head)
{
    if (head == NULL)
    {
        printf("Empty linked list");
    }
    else
    {
        if (head->next == NULL)
        {
            printf("%d=>", head->data);
        }
        else
        {
            reverseDisplay(head->next);
            printf("%d =>", head->data);
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
        printf("3:Display Linked List reverse order\n");

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
            reverseDisplay(first);
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