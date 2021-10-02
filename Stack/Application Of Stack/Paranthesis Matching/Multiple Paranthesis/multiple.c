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

int matching(char popItem, char currentChar)
{
    if (currentChar == ')' && popItem == '(')
    {
        return 1;
    }
    else if (currentChar == '}' && popItem == '{')
    {
        return 1;
    }
    else if (currentChar == ']' && popItem == '[')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheakBalance(struct stack *s1, char exp[])
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s1, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(*s1) == 1)
            {
                return 0; //not balance expresssion
            }
            char popItem = pop(s1);
            int matchingResult = matching(popItem, exp[i]);
            if (matchingResult != 1)
            {
                return 0;
            }
        }
        i++;
    }
    if (isEmpty(*s1) == 1)
    {
        return 1; //balance expression
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
        printf("Given expression is contain well Balance Paranthesis\n");
    }
    else
    {
        printf("Given Expression is not well Balance Paranthesis\n");
    }
}