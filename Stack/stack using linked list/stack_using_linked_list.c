/*
Name:Wagh Aditya
Topic:Stack using LInked list
*/

// *******************solution ******************

#include <stdio.h>  //headre file
#include <stdlib.h> //header file to use malloc and free function
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

//pushing element to stack

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
//to cheak wether stack is empty or not
int isEmpty(struct stack *top)
{
    return (top == NULL);
}

//add element to stack
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
    struct stack *top = NULL; //pointer to maintain address of top element of Stack

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