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
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

void createLinkedList(struct node **head)
{
    struct node *newnode = NULL;
    newnode = creatNode();
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

void displayLinkedList(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d ->", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void addAtFirst(struct node **head)
{
    struct node *newnode = NULL;
    newnode = creatNode();
    newnode->next = *head;
    *head = newnode;
}
void insertAtPosition(struct node **head)
{
    int position;
    printf("Enter Position\n");
    scanf("%d", &position);
    if (position == 1)
    {
        addAtFirst(head);
    }

    else
    {

        int count = 0;
        int flag = 0;
        struct node *temp = NULL;
        struct node *temp1 = NULL;
        temp = *head;
        while (temp != NULL)
        {
            count += 1;
            if (count == position - 1)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 1 && temp != NULL)
        {
            struct node *newnode = NULL;
            newnode = creatNode();
            temp1 = temp->next;
            temp->next = newnode;
            ;
            newnode->next = temp1;
        }
        else if (temp == NULL && flag == 0)
        {
            printf("Invalid Index to add node \n");
        }
    }
}

void deleteAtFirst(struct node **head)
{
    struct node *temp = NULL;
    temp = *head;
    *head = temp->next;
    free(temp);
    printf("Deleted Successfully\n");
}
void deleteAtLast(struct node **head)
{
    struct node *temp = NULL;
    struct node *temp1 = NULL;
    temp = *head;
    while (temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
}

void deleteAtPosition(struct node **head)
{
    int position=0;
    printf("Enter position\n");
    scanf("%d",&position);
    if (position == 1)
    {
        deleteAtFirst(head);
    }
    else
    {
        int count = 0;
        int flag = 0;
        struct node *temp = NULL;
        struct node *temp2 = NULL;
        struct node *temp3 = NULL;
        temp=*head;
        while (temp != NULL)
        {
            count += 1;
            if (count == position - 1)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 1 && temp != NULL)
        {
            temp2=temp->next;
            temp3=temp2->next;
            temp->next=temp3;
            free(temp2);
        }
        else if (temp == NULL && flag == 0)
        {
            printf("Invalid Index to delete node \n");
        }
    }
}

void main()
{
    printf("Welcome user!!!\n");
    int choice;
    struct node *first = NULL;
    do
    {

        printf("1 Create Linked List\n");
        printf("2 Display Linked List\n");
        printf("3 Insert node at first\n");
        printf("4 Insert node at Last \n");
        printf("5 Insert node at any Position\n");
        printf("6 Delete node at first\n");
        printf("7 Delete node at Last \n");
        printf("8 Delete node at any Position\n");
        printf("0 Exit \n");
        printf("Enter you choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createLinkedList(&first);
            break;
        case 2:
            displayLinkedList(first);
            break;
        case 3:
            addAtFirst(&first);
            break;
        case 4:
            createLinkedList(&first);
            break;
        case 5:
            insertAtPosition(&first);
            break;

        case 6:
            deleteAtFirst(&first);
            break;
        case 7:
            deleteAtLast(&first);
            break;
        case 8:
            deleteAtPosition(&first);
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