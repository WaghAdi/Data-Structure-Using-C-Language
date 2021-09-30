#include <stdio.h>
#define max 100

struct stack
{
    int top;
    char a[max];
};
int isEmpty(struct stack s1)
{
    return s1.top == -1;
}
int isFull(struct stack s1)
{
    return s1.top == (max - 1);
}

void push(struct stack *s1, char value)
{
    (s1->top)++;
    s1->a[s1->top] = value;
}
int pop(struct stack *s1)
{
    char popvalue = s1->a[s1->top];
    (s1->top)--;
    return popvalue;
}

int cheakBalance(struct stack *s1, char exp[])
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(s1, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(*s1) == 1)
            {
                return 1;
            }
            else if (pop(s1) != '(')
            {
                return 1;
            }
        }
        i++;
    }
    if (isEmpty(*s1) == 1)
    {
        return 0;
    }
}

void main()
{
    struct stack s1;
    s1.top = -1;
    char arr[max];
    printf("enter Expression\n");
    scanf("%s", &arr);
    int result = cheakBalance(&s1, arr);
    if (result == 1)
    {
        printf("Not Balance Paranthesis\n");
    }
    else
    {
        printf("Balance Paranthesis\n");
    }
}