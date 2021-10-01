/*
Name:Wagh Aditya
Topic:Stack using LInked list
*/

// *******************solution ******************

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next; //self refrencing structure
};
struct stack *createNode()
{
    struct stack *newNode = NULL;
    int value;
    newNode = (struct stack *)malloc(sizeof(struct stack));
    printf("plz enter data want to push\n");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(struct stack **top)
{
    struct stack *newNode = NULL;
    newNode = createNode();
    if (*top == NULL)
    {
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }
    printf("value added successfully\n");
}

int isEmpty(struct stack *top)
{
    return (top == NULL);
}
int pop(struct stack **top)
{
    int popValue;
    struct stack *temp = *top;
    popValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return popValue;
}

void main()
{
    struct stack *top = NULL;

    int choice;
    do
    {
        printf("1 Push\n");
        printf("2 pop\n");
        printf("enter choice to perform operation\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&top);
            break;
        case 2:
            isEmpty(top) == 1 ? printf("Stack is empty or Underflow") : printf("poped data is %d\n", pop(&top)); //short hand if else to cheak stack empty condition
            break;
        case 0:
            printf("Thank You!!!\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (choice != 0);
}