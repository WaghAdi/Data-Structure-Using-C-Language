/*balance paranthesis problme solving using stack 
  logic 
  if openign paranthis push to stack
  push till get closing paranthesis
  if closing paranthesis then 
  1.if stack is empty then not balance 
  2.else match pop element from stack with current if they are equalvaliht then repeta till end of expressiong
  3.after end of expresion cheka wehte stack is empty if not then not balance or else balanced
  */

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
    while (exp[i] != '\0') //traverse loop till last character
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') //push if opending paranthesis come
        {
            push(s1, exp[i]); //push now to stack
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(*s1) == 1)
            {
                return 0; //not balance expresssion
            }
            char popItem = pop(s1);
            int matchingResult = matching(popItem, exp[i]); //to cheak wehter closing paranthesis is related to opening parantheis
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