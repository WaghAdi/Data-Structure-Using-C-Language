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

//count node
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

void addAtFirst(struct node **head)
{
    struct node *newnode = NULL;
    newnode = creatNode();
    newnode->next = *head;
    *head = newnode;
}
// void insertAtPosition(struct node **head)
// {
//     int position;
//     printf("Enter Position\n");
//     scanf("%d", &position);
//     if (position == 1)
//     {
//         addAtFirst(head);
//     }

//     else
//     {

//         int count = 0;
//         int flag = 0;
//         struct node *temp = NULL;
//         struct node *temp1 = NULL;
//         temp = *head;
//         while (temp != NULL)
//         {
//             count += 1;
//             if (count == position - 1)
//             {
//                 flag = 1;
//                 break;
//             }
//             temp = temp->next;
//         }
//         if (flag == 1 && temp != NULL)
//         {
//             struct node *newnode = NULL;
//             newnode = creatNode();
//             temp1 = temp->next;
//             temp->next = newnode;
//             ;
//             newnode->next = temp1;
//         }
//         else if (temp == NULL && flag == 0)
//         {
//             printf("Invalid Index to add node \n");
//         }
//     }
// }

void insertAtPosition(struct node **head)
{
    int position;
    int nodecount = countNode(*head);
lable:
    printf("Enter position\n");
    scanf("%d", &position);
    if (position == 1)
    {
        addAtFirst(head);
    }
    else if (position == nodecount + 1)
    {
        createLinkedList(head);
    }
    else if (position < 0 || position > nodecount + 1)
    {
        printf("Inavalid Index to add node try again\n");
        goto lable;
    }
    else
    {
        struct node *temp = NULL;
        struct node *newnode = NULL;
        newnode = creatNode();
        temp = *head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

/*DELETION OPERATIONS*/

/* DELETE AT FIRST*/

void deleteAtFirst(struct node **head)
{
    if (*head == NULL)
    {
        printf("LInked list is already empty\n");
    }
    else
    {
        struct node *temp = NULL;
        temp = *head;
        *head = temp->next;
        free(temp);
        printf("Deleted Successfully\n");
    }
}

/* DELETE AT LAST*/
void deleteAtLast(struct node **head)
{
    if (*head == NULL)
    {
        printf("LInked list is already empty\n");
    }
    else if((*head)->next == NULL)
    {
         free(*head);
         *head=NULL;
    }
    else
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
}

// void deleteAtPosition(struct node **head)
// {
//     int position = 0;
//     printf("Enter position\n");
//     scanf("%d", &position);
//     if (position == 1)
//     {
//         deleteAtFirst(head);
//     }
//     else
//     {
//         int count = 0;
//         int flag = 0;
//         struct node *temp = NULL;
//         struct node *temp2 = NULL;
//         struct node *temp3 = NULL;
//         temp = *head;
//         while (temp != NULL)
//         {
//             count += 1;
//             if (count == position - 1)
//             {
//                 flag = 1;
//                 break;
//             }
//             temp = temp->next;
//         }
//         if (flag == 1 && temp != NULL)
//         {
//             temp2 = temp->next;
//             temp3 = temp2->next;
//             temp->next = temp3;
//             free(temp2);
//         }
//         else if (temp == NULL && flag == 0)
//         {
//             printf("Invalid Index to delete node \n");
//         }
//     }
// }

/* DELETE AT POSITION*/
void deleteAtPosition(struct node **head)
{
    if (*head == NULL)
    {
        printf("LInked list is already empty\n");
    }
    else
    {
        int position;
        int nodecount = countNode(*head);
    lable:
        printf("Enter position\n");
        scanf("%d",&position);
        if (position == 1)
        {
            deleteAtFirst(head);
        }
        else if (position == nodecount)
        {
            deleteAtLast(head);
        }
        // else if(*head->next ==NULL)
        // {
            
        // }
        else if (position <= 0 || position >= nodecount + 1)
        {
            printf("Inavalid Index to delete node try again\n");
            goto lable;
        }
        
        else
        {
            struct node *temp = NULL;
            struct node *temp1 = NULL;
            temp = *head;
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            temp1 = temp->next;
            temp->next = temp1->next; 
            free(temp1);
        }
    }
}


void reverseSinglyLinkedList(struct node **head)
{   
    printf("Inside function\n");
    struct node *prevPtr=NULL;
    struct node *currentPtr=(*head);
    struct node *nextPtr=currentPtr->next;
    printf("variable initializzzed\n");
    int i=1;
    while(currentPtr!=NULL)
    { 
        printf("Inside loop %d \n",i++);
       currentPtr->next=prevPtr;
       prevPtr=currentPtr;
       currentPtr=nextPtr;
       //if conditin need because of segmentation fault
       if(currentPtr==NULL)
       {
           break;
       }
       nextPtr=nextPtr->next;
    }
    printf("outside loop\n");
    (*head)=prevPtr;

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
        printf("9 reverse linked list\n");
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
        case 9:
             reverseSinglyLinkedList(&first);
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