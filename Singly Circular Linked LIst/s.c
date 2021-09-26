#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; //self refrential structure
};
struct node *creatNode()
{
    int value;
    struct node *newnode = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("Memory allocted succesfully\n");

        printf("Enter value of node\n");
        scanf("%d",&value);
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

void createLinkedList(struct node **tail)
{
    struct node *newnode = NULL;
    newnode = creatNode();
    if (*tail == NULL)
    {
        *tail = newnode;
        newnode->next=(*tail);
    }
    else
    {
       newnode->next=(*tail)->next;
       (*tail)->next=newnode;
       *tail=newnode;
    }
}

void displayLinkedList(struct node *tail)
{
    if (tail == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        struct node *temp=tail->next;
        struct node *head=tail->next;

        do
        {
            printf("%d=>",temp->data);
            temp=temp->next;
        }while(temp!=head);
        printf("\n");
    }
}

void insertAtFirst(struct node **tail)
{
    struct node *newNode=NULL;
    newNode=creatNode();
    if(*tail==NULL)
    {
       *tail=newNode;
       newNode->next=*tail;
    }
    else
    {
       newNode->next=(*tail)->next;
       (*tail)->next=newNode;
    }
}

void insertAtLast(struct node **tail)
{
    struct node *newNode=NULL;
    newNode=creatNode();
    if(*tail==NULL)
    {
       *tail=newNode;
       newNode->next=*tail;
    }
    else
    {
        newNode->next=(*tail)->next;
       (*tail)->next=newNode;
       *tail=newNode;
    }
}

void insertAtPosition(struct node *tail)
{   
    struct node *newNode=creatNode();
    int value;
    int flag=0;
    printf("Enter value after which you want to add data\n");
    scanf("%d",&value);
    struct node *head=tail->next;
    struct node *temp=tail->next;
    do
    {
       if(temp->data==value)
       {   
           newNode->next=temp->next;
           temp->next=newNode;
           flag=1;
           printf("node addes successfully\n");
           break;
       }
       else
       {
           temp=temp->next;
       }

    }while(temp!=head);
    if(flag==0)
    {
        printf("Data Not Found\n");
    }

   
}

void main()
{
    printf("Welcome user!!!\n");
    int choice;
    struct node *last = NULL;
    do
    {

        printf("1 Create Linked List\n");
        printf("2 Display Linked List\n");
        printf("3 Insert at first\n");
        printf("4 Insert at Last\n");
        printf("5 Insert at Position\n");
        printf("0 Exit \n");
        printf("Enter you choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createLinkedList(&last);
            break;
        case 2:
            displayLinkedList(last);
            break;
        case 3:
            insertAtFirst(&last);
            break;
        case 4:
            insertAtLast(&last);
            break;
        case 5:
            insertAtPosition(last);
            break;
        case 0:
            printf("Thank you user!!!\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
}