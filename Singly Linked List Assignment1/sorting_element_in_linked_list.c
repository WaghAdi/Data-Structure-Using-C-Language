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

void sort(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct node *temp = NULL;
        struct node *temp1 = NULL;
        struct node *min = NULL;
        temp = head;
        while (temp->next != NULL)
        {
            min = temp;
            temp1 = temp->next;
            while (temp1 != NULL)
            {
                if (temp1->data < min->data)
                {
                    min = temp1;
                }
                temp1 = temp1->next;
            }
            int temporary = min->data;
            min->data = temp->data;
            temp->data = temporary;
            temp = temp->next;
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
        printf("3 Sort Linked List\n");

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
            sort(first);
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