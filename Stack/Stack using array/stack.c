#include <stdio.h>
#define max 10 //macro defination

// structure declearation
struct stack
{
    int a[max];
    int top;
};

//function to initialize top to -1
void init_Stack(struct stack *structPtr)
{
    structPtr->top = -1;
}

//function to cheak weather stack is empty or not
int isEmpty(struct stack s1)
{
    return (s1.top == -1);
}

//function to cheak wether stack is full or not
int isFull(struct stack s1)
{
    return s1.top == (max - 1);
}

//to insert a data to stack
void push(struct stack *structPtr, int data)
{
    (structPtr->top)++;
    structPtr->a[structPtr->top] = data;
    printf("data add succesfully\n");
}

//to delete data from stack
int pop(struct stack *structPtr)
{
    int popData = structPtr->a[structPtr->top];
    (structPtr->top)--;
    return popData;
}

void main()
{
    struct stack s1; //creqting object of user defined data type
    init_Stack(&s1); //initializing top value to -1

    int choice;
    //Menu driven program
    do
    {
        printf("Menu!!!\n");
        printf("1 isEmpty\n");
        printf("2 isfull\n");
        printf("3 Push\n");
        printf("4 pop\n");
        printf("enter choice to perform operation\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isEmpty(s1) == 1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
            }
            break;
        case 2:
            isFull(s1) == 1 ? printf("stack is full\n") : printf("stack is not full\n");
            break;
            //push operation call
        case 3:
            if (isFull(s1))
            {
                printf("Stack is already full or Stack Overflow\n");
            }
            else
            {
                int data;
                printf("enter data to be push\n");
                scanf("%d", &data);
                push(&s1, data);
            }
            break;
            //pop operation call
        case 4:
            if (isEmpty(s1))
            {
                printf("stack is empty or Stack Underflow\n");
            }
            else
            {
                int popdata = pop(&s1);
                printf("Poped data is %d\n", popdata);
            }
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