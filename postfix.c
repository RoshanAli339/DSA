#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stk[20], top = -1;

void push(char c)
{
    if (top == 19)
    {
        printf("Stack is full\n");
        return;
    }
    stk[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        return 1;
    }
    return stk[top--];
}

char peek()
{
    if (top == -1)
    {
        return 1;
    }
    return stk[top];
}

char* convPostfix(char infix[])
{
    int a[100];
    a[1] = -1;
    a['^'] = 3;
    a['%'] = 2;
    a['/'] = 2;
    a['*'] = 2;
    a['+'] = 1;
    a['-'] = 1;
    a['('] = 0;
    int index = -1;
    char *postfix = (char*)malloc(strlen(infix)*sizeof(char));
    for (int i = 0; infix[i] != '\0'; ++i)
    {
        if (infix[i] >= 97 && infix[i] <= 122)
            postfix[++index] = infix[i];
        else
        {
            if (infix[i] == ')')
            {
                while (peek() != '(')
                {
                    postfix[++index] = pop();
                }
                pop();
            }
            else
            {
                while (infix[i] != '(' && a[infix[i]] <= a[peek()])
                {
                    postfix[++index] = pop();
                }
                push(infix[i]);
            }
        }
        //printf("%c : %s : %s\n", infix[i], postfix, stk);
    }
    if (top != -1)
    {
        while (top >= 0)
        {
            postfix[++index] = pop();
        }
    }
    return postfix;
}

int main()
{
    char infix[20];
    printf("Enter an infix expression: ");
    scanf(" %[^\n]", infix);
    char *postfix = convPostfix(infix);
    printf("%s\n", postfix);
}
